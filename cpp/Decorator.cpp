#include <iostream>
#include <string>
using namespace std;
class IceCream
{
  public:
    virtual string getDescription() const = 0;
    virtual double cost() const = 0;
};
class VanillaIceCream : public IceCream
{
  public:
    string getDescription() const override
    {
        return "Vanilla Ice Cream";
    }
    double cost() const override
    {
        return 160.0;
    }
};
class IceCreamDecorator : public IceCream
{
  protected:
    IceCream *iceCream;

  public:
    IceCreamDecorator(IceCream *ic) : iceCream(ic)
    {
    }
    string getDescription() const override
    {
        return iceCream->getDescription();
    }
    double cost() const override
    {
        return iceCream->cost();
    }
};
class ChocolatedDecorator : public IceCreamDecorator
{
  public:
    ChocolatedDecorator(IceCream *ic) : IceCreamDecorator(ic)
    {
    }
    string getDescription() const override
    {
        return iceCream->getDescription() + " with Chocolate";
    }
    double cost() const override
    {
        return iceCream->cost() + 100.0;
    }
};
class CamelDecorator : public IceCreamDecorator
{
  public:
    CamelDecorator(IceCream *ic) : IceCreamDecorator(ic)
    {
    }
    string getDescription() const override
    {
        return iceCream->getDescription() + " with Camel";
    }
    double cost() const override
    {
        return iceCream->cost() + 150.0;
    }
};
int main()
{
    IceCream *vanillaIceCream = new VanillaIceCream();
    cout << "Order: " << vanillaIceCream->getDescription() << ", cost: Rs." << vanillaIceCream->cost() << endl;
    IceCream *chocolateIceCream = new ChocolatedDecorator(vanillaIceCream);
    cout << "Order: " << chocolateIceCream->getDescription() << ", cost: Rs." << chocolateIceCream->cost() << endl;
    IceCream *camelIceCream = new CamelDecorator(chocolateIceCream);
    cout << "Order: " << camelIceCream->getDescription() << ", Cost: Rs." << camelIceCream->cost() << endl;

    delete vanillaIceCream;
    delete chocolateIceCream;
    delete camelIceCream;
    return 0;
}