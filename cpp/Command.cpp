#include <iostream>
class Receiver
{
  public:
    void performAction()
    {
        std::cout << "Receiver is performing an action." << std::endl;
    }
};
class Command
{
  public:
    virtual void execute() = 0;
};
class ConcreteCommand : public Command
{
  private:
    Receiver &receiver;

  public:
    ConcreteCommand(Receiver &r) : receiver(r)
    {
    }

    void execute()
    {
        receiver.performAction();
    }
};
class Invoker
{
  private:
    Command *command;

  public:
    void setCommand(Command *c)
    {
        command = c;
    }

    void executeCommand()
    {

        command->execute();
    }
};
int main()
{
    Receiver receiver;
    ConcreteCommand command(receiver);
    Invoker invoker;
    invoker.setCommand(&command);
    invoker.executeCommand();

    
    return 0;
}