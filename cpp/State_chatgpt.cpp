#include <iostream>
#include <memory>
#include <string>

// Forward declaration
class Document;

// State Interface
class DocumentState
{
  public:
    virtual ~DocumentState() = default;
    virtual void submitForReview(Document &document) = 0;
    virtual void publish(Document &document) = 0;
    virtual void archive(Document &document) = 0;
    virtual std::string name() const = 0;
};
// Context
class Document
{
  private:
    std::unique_ptr<DocumentState> state;

  public:
    Document(std::unique_ptr<DocumentState> initialState) : state(std::move(initialState))
    {
    }
    void setState(std::unique_ptr<DocumentState> newState)
    {
        state = std::move(newState);
    }
    void submitForReview()
    {
        state->submitForReview(*this);
    }
    void publish()
    {
        state->publish(*this);
    }
    void archive()
    {
        state->archive(*this);
    }
    void showState() const
    {
        std::cout << "Current state: " << state->name() << std::endl;
    }
};
// Concrete States
class ArchivedState : public DocumentState
{
  public:
    void submitForReview(Document &document) override
    {
        std::cout << "Cannot submit an archived document for review." << std::endl;
    }
    void publish(Document &document) override
    {
        std::cout << "Cannot publish an archived document." << std::endl;
    }
    void archive(Document &document) override
    {
        std::cout << "Already archived." << std::endl;
    }
    std::string name() const override
    {
        return "Archived";
    }
};

class DraftState : public DocumentState
{
  public:
    void submitForReview(Document &document) override;
    void publish(Document &document) override
    {
        std::cout << "Cannot publish a draft document. submit for review first." << std::endl;
    }
    void archive(Document &document) override
    {
        std::cout << "Archiving draft ..." << std::endl;
        document.setState(std::make_unique<ArchivedState>());
    }
    std::string name() const override
    {
        return "Draft";
    }
};
class ReviewState : public DocumentState
{
  public:
    void submitForReview(Document &document) override
    {
        std::cout << "Already in review state." << std::endl;
    }
    void publish(Document &document) override;
    void archive(Document &document) override
    {

        std::cout << "Archiving document from review ..." << std::endl;
        document.setState(std::make_unique<ArchivedState>());
    }
    std::string name() const override
    {
        return "Review";
    }
};
class PublishedState : public DocumentState
{
  public:
    void submitForReview(Document &document) override
    {
        std::cout << "Already Published, cannot submit for review." << std::endl;
    }
    void publish(Document &document) override
    {
        std::cout << "Already published." << std::endl;
    }
    void archive(Document &document) override
    {
        std::cout << "Archiving published document ..." << std::endl;
        document.setState(std::make_unique<ArchivedState>());
    }
    std::string name() const override
    {
        return "Published";
    }
};

// State transitions implementation
void DraftState::submitForReview(Document &document)
{
    std::cout << "Submitting document for review ..." << std::endl;
    document.setState(std::make_unique<ReviewState>());
}
void ReviewState::publish(Document &document)
{
    std::cout << "Publishing reviewed document ..." << std::endl;
    document.setState(std::make_unique<PublishedState>());
}
// Main function
int main()
{
    Document doc(std::make_unique<DraftState>());

    doc.showState();       // Current state: Draft
    doc.publish();         // Cannot publish a draft document. submit for review first.
    doc.submitForReview(); // Submitting document for review ...
    doc.showState();       // Current state: Review

    doc.submitForReview(); // Already in review state.
    doc.publish();         // Publishing reviewed document ...
    doc.showState();       // Current state: Published

    doc.archive();   // Archiving published document ...
    doc.showState(); // Current state: Archived

    doc.publish(); // Cannot publish an archived document.
    return 0;
}