#include <iostream>
#include <string>
#include <vector>
// Originator: The object whose state need to be saved and restored
class Originator
{
  private:
    std::string state;

  public:
    void setState(const std::string &state)
    {
        this->state = state;
    }
    std::string getState() const
    {
        return state;
    }
    class Memento
    {
      private:
        std::string state;

      public:
        Memento(const std::string &state) : state(state)
        {
        }
        std::string getSavedState() const
        {
            return state;
        }
    };
    Memento saveToMemento()
    {
        return Memento(state);
    }
    void restoreFromMemento(const Memento &memento)
    {
        state = memento.getSavedState();
    }
};
// Caretaker: Manage the Memento Objects
class Caretaker
{
  private:
    std::vector<Originator::Memento> mementoList;

  public:
    void addMemento(const Originator::Memento &memento)
    {
        mementoList.push_back(memento);
    }
    Originator::Memento getMemento(int index)
    {
        if (index < 0 || (std::size_t)index >= mementoList.size())
        {
            throw std::out_of_range("invalid memento index");
        }
        return mementoList[index];
    }
};
int main()
{
    Originator originator;
    Caretaker caretaker;

    originator.setState("State 1");
    caretaker.addMemento(originator.saveToMemento());

    originator.setState("State 2");
    caretaker.addMemento(originator.saveToMemento());

    originator.setState("State 3");
    caretaker.addMemento(originator.saveToMemento());

    std::cout << "Current State: " << originator.getState() << std::endl;

    originator.restoreFromMemento(caretaker.getMemento(1));
    std::cout << "Restored to: " << originator.getState() << std::endl;

    originator.restoreFromMemento(caretaker.getMemento(0));
    std::cout << "Restored to: " << originator.getState() << std::endl;
    return 0;
}