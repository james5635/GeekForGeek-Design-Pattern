#include <iostream>
#include <memory>
class Command
{
  public:
    virtual void execute() = 0;
    virtual ~Command() = default;

  protected:
    Command() = default;
};
template <typename R> class SimpleCommand : public Command
{
    typedef void (R::*Action)();

  public:
    SimpleCommand(std::shared_ptr<R> receiver_, Action action_) : receiver(receiver_.get()), action(action_)
    {
    }
    SimpleCommand(const SimpleCommand &) = delete;
    const SimpleCommand &operator=(const SimpleCommand &) = delete;
    void execute() override
    {
        (receiver->*action)();
    }

  private:
    R *receiver;
    Action action;
};
class Myclass
{
  public:
    void action()
    {
        std::cout << "Myclass::action\n";
    }
};
int main()
{
    std::shared_ptr<Myclass> receiver = std::make_shared<Myclass>();
    std::unique_ptr<Command> command = std::make_unique<SimpleCommand<Myclass>>(receiver, &Myclass::action);
    command->execute();
}