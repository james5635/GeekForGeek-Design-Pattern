#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
// Observer Interface
class IObserver
{
  public:
    virtual void update(const std::string &message) = 0;
    virtual ~IObserver() = default;
};

// Subject Interface
class ISubject
{
  public:
    virtual void attach(IObserver *observer) = 0;
    virtual void detach(IObserver *observer) = 0;
    virtual void notify() = 0;
    virtual ~ISubject() = default;
};

// Concrete Subject
class NewsAgency : public ISubject
{
  private:
    std::vector<IObserver *> observers;
    std::string news;

  public:
    void attach(IObserver *observer) override
    {
        observers.push_back(observer);
    }

    void detach(IObserver *observer) override
    {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify() override
    {
        for (auto observer : observers)
        {
            observer->update(news);
        }
    }
    void setNews(const std::string &news)
    {
        this->news = news;
        notify();
    }
};
// Concrete Observer
class NewsReader : public IObserver
{
  private:
    std::string name;

  public:
    NewsReader(const std::string &name) : name(name)
    {
    }

    void update(const std::string &message) override
    {
        std::cout << name << " received news: " << message << std::endl;
    }
};
// Usage
int main()
{
    NewsAgency agency;
    NewsReader alice("Alice");
    NewsReader bob("Bob");

    agency.attach(&alice);
    agency.attach(&bob);

    agency.setNews("Breaking News: Observer Pattern in C++!");

    std::cout << std::endl;

    agency.detach(&bob);
    agency.setNews("Only Alice will see this news!");
    return 0;
}