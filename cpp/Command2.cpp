#include <iostream>
#include <vector>
class ElectronicDevice
{
  public:
    ElectronicDevice(const std::string &name_) : name(name_)
    {
    }
    virtual void turnOn()
    {
        std::cout << " is ON now." << std::endl;
    }
    virtual void off()
    {
        std::cout << " is OFF now." << std::endl;
    }

  private:
    std::string name;
};
class Command
{
  public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};
class turnOnCommand : public Command
{

  private:
    ElectronicDevice &device;

  public:
    turnOnCommand(ElectronicDevice &device_) : device(device_)
    {
    }
    void execute() override
    {
        device.turnOn();
    }
};

class turnOffCommand : public Command
{
  private:
    ElectronicDevice &device;

  public:
    turnOffCommand(ElectronicDevice &device_) : device(device_)
    {
    }
    void execute() override
    {
        device.off();
    }
};
class RemoteControl
{
  private:
    std::vector<Command *> commands;

  public:
    void addCommand(Command *command)
    {
        commands.push_back(command);
    }
    void pressButton(int slot)
    {
        if (slot >= 0 && slot < commands.size())
        {
            commands[slot]->execute();
        }
        else
        {
            std::cout << "Invalid command slot." << std::endl;
        }
    }
};
int main(void)
{
    ElectronicDevice tv("TV");
    ElectronicDevice radio("Radio");
    ElectronicDevice fan("Fan");

    turnOnCommand tvOn(tv);
    turnOffCommand tvOff(tv);
    turnOnCommand radioOn(radio);
    turnOffCommand radioOff(radio);
    turnOnCommand fanOn(fan);
    turnOffCommand fanOff(fan);
    RemoteControl remote;
    remote.addCommand(&tvOn);
    remote.addCommand(&tvOff);
    remote.addCommand(&radioOn);
    remote.addCommand(&radioOff);
    remote.addCommand(&fanOn);
    remote.addCommand(&fanOff);
    std::cout << "Pressing button 0 (TV ON): ";
    remote.pressButton(0);
    std::cout << "Pressing button 1 (TV OFF): ";
    remote.pressButton(1);
    std::cout << "Pressing button 2 (Radio ON): ";
    remote.pressButton(2);
    std::cout << "Pressing button 3 (Radio OFF): ";
    remote.pressButton(3);
    std::cout << "Pressing button 4 (Fan ON): ";
    remote.pressButton(4);
    std::cout << "Pressing button 5 (Fan OFF): ";
    remote.pressButton(5);
    std::cout << "Pressing button 6 (Invalid): ";
    remote.pressButton(6);
    std::cout << "Pressing button -1 (Invalid): ";
    remote.pressButton(-1);

    return 0;
}