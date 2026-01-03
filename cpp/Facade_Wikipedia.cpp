
#include <fmt/color.h>
#include <fmt/core.h>
#include <iostream>
// Compile-time constants using constexpr char[]
constexpr long kBootAddress = 0x1234abc;
constexpr long kBootSector = 0x321acd;
constexpr long kBootSize = 0x23faf;
constexpr char HDDATA[] = "abcde"; // Safer alternative to #define
struct CPU
{
    void Freeze();
    void Jump(long positon);
    void Execute();
};
void CPU::Freeze()
{
    fmt::print(fg(fmt::color::blue), "freezing cpu\n");
}
void CPU::Jump(long postion)
{
    fmt::print("jumping to postion {}\n", postion);
}
void CPU::Execute()
{
    fmt::print("Executing...\n");
}
struct HardDrive
{
    const char *Read(long lba, int size);
};
const char *HardDrive::Read(long lba, int size)
{
    fmt::print("Reading data from HardDrive (lba: {}, size: {}) ...\n", lba, size);

    return HDDATA;
}
struct Memory
{
    void Load(long position, const char *data);
};
void Memory::Load(long position, const char *data)
{
    fmt::print("Loading data to memory(position: {}, data: {})...\n", position, data);
}
class ComputerFacade
{
  public:
    void Start()
    {
        cpu_.Freeze();
        memory_.Load(kBootAddress, hard_drive_.Read(kBootSector, kBootSize));
        cpu_.Jump(kBootAddress);
        cpu_.Execute();
    }

  private:
    CPU cpu_;
    HardDrive hard_drive_;
    Memory memory_;
};
int main()
{
    ComputerFacade computer;
    computer.Start();
    return 0;
}