// 1. Memento
#include <iostream>
#include <stack>
#include <string>

class TextMemento
{
  private:
    std::string state;

  public:
    TextMemento(const std::string &s) : state(s)
    {
    }
    std::string getState() const
    {
        return state;
    }
};
// Originator
class TextEditor
{
  private:
    std::string text;

  public:
    void type(const std::string &newText)
    {
        text += newText;
    }
    void showText() const
    {
        std::cout << "Current text: " << text << std::endl;
    }
    TextMemento save()
    {
        return TextMemento(text);
    }
    void restore(const TextMemento &memento)
    {
        text = memento.getState();
    }
};
//  Caretaker
class history
{
  private:
    std::stack<TextMemento> mementos;

  public:
    void backup(const TextMemento &memento)
    {
        mementos.push(memento);
    }
    TextMemento undo()
    {
        if (mementos.size() == 0)
        {
            return TextMemento("");
        }
        if (mementos.size() == 1)
        {
            return mementos.top();
        }
        mementos.pop();
        return mementos.top();
    }
};
// Usage
int main()
{
    TextEditor editor;
    history history;

    editor.type("Hello, ");
    history.backup(editor.save());

    editor.type("world! ");
    history.backup(editor.save());

    editor.type("Memento pattern in C++.");
    history.backup(editor.save());

    editor.showText();

    std::cout << "Undoing ..." << std::endl;
    editor.restore(history.undo());
    editor.showText();

    std::cout << "Undoing ..." << std::endl;
    editor.restore(history.undo());
    editor.showText();

    return 0;
}
