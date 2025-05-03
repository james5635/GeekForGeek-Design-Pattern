#include <iostream>
// Abstract class
class GameAI
{
  public:
    // Template method
    void turn()
    {
        collectResources();
        ;
        buildStructures();
        buildUnits();
        attack();
    }
    virtual ~GameAI() {}

  protected:
    void collectResources()
    {
        std::cout << "Collecting resources..." << std::endl;
    }
    virtual void buildStructures() = 0;
    virtual void buildUnits() = 0;
    virtual void attack()
    {
        std::cout << "Attacking enemy..." << std::endl;
    }
};
// Concrete class
class OrcAI : public GameAI
{
  protected:
    void buildStructures() override
    {
        std::cout << "Building Orc hut..." << std::endl;
    }
    void buildUnits() override
    {
        std::cout << "Building Orc warriors..." << std::endl;
    }
};
// Concrete class
class ElfAI : public GameAI
{
  protected:
    void buildStructures() override
    {
        std::cout << "Building Elven treehouse..." << std::endl;
    }
    void buildUnits() override
    {
        std::cout << "Building Elven archers..." << std::endl;
    }
};
// USage
int main()
{
    GameAI *orcAI = new OrcAI();
    orcAI->turn();

    GameAI *elfAI = new ElfAI();
    elfAI->turn();

    delete orcAI;
    delete elfAI;

    return 0;
}