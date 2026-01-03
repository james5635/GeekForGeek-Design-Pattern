#include <iostream>
#include <string>
class Computer
{
  public:
    void setCPU(const std::string &cpu)
    {
        cpu_ = cpu;
    }
    void setMemory(const std::string &memory)
    {
        memory_ = memory;
    }
    void setStorage(const std::string &storage)
    {
        storage_ = storage;
    }
    void display()
    {
        using namespace std;
        cout << "CPU: " << cpu_ << endl;
        cout << "Memory: " << memory_ << endl;
        cout << "Storage: " << storage_ << endl;
    }

  private:
    std::string cpu_;
    std::string memory_;
    std::string storage_;
};
class ComputerBuilder
{
  public:
    virtual void buildCPU(const std::string &cpu) = 0;
    virtual void buildMemory(const std::string &memory) = 0;
    virtual void buildStorage(const std::string &storage) = 0;
    virtual Computer getResult() = 0;
};
class DesktopComputerBuilder : public ComputerBuilder
{
  public:
    DesktopComputerBuilder()
    {
        computer_ = Computer();
    }
    void buildCPU(const std::string &cpu) override
    {
        computer_.setCPU(cpu);
    }
    void buildMemory(const std::string &memory) override
    {
        computer_.setMemory(memory);
    }
    void buildStorage(const std::string &storage) override
    {
        computer_.setStorage(storage);
    }
    Computer getResult() override
    {
        return computer_;
    }

  private:
    Computer computer_;
};
class ComputerAssembler
{
  public:
    Computer assembleComputer(ComputerBuilder &builder)
    {
        builder.buildCPU("Intel Core i7");
        builder.buildMemory("16GB");
        builder.buildStorage("512GB SSD");
        return builder.getResult();
    }
};
int main()
{
    DesktopComputerBuilder desktopBuilder;
    ComputerAssembler assembler;
    Computer desktop = assembler.assembleComputer(desktopBuilder);

    std::cout << "Desktop Computer Configuration." << std::endl;
    desktop.display();

    return 0;
}
