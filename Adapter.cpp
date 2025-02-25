#include <iostream>
class Printer
{
  public:
    virtual void print() = 0;
};
class LegacyPrinter
{
  public:
    void printDocument()
    {
        std::cout << "Legacy Printer is printing a document.";
    }
};
class PrinterAdapter : public Printer
{
  private:
    LegacyPrinter legacyPrinter;

  public:
    void print() override
    {
        legacyPrinter.printDocument();
    }
};
void clientCode(Printer &printer)
{
    printer.print();
}
int main()
{
    PrinterAdapter adapter;
    clientCode(adapter);
    return 0;
}
