#include <iostream>
#include <memory>
// #include <print>
#include <fmt/core.h>
class Beverage
{
  public:
    virtual void drink() = 0;
    virtual ~Beverage() = default;
};
class Coffee : public Beverage
{
  public:
    virtual void drink() override
    {
        fmt::print("Drinking Coffee");
    }
};
class Soda : public Beverage
{
  public:
    virtual void drink() override
    {
        fmt::print("Drinking Soda");
    }
};
class BeverageDecorator : public Beverage
{
  public:
    BeverageDecorator() = delete;
    BeverageDecorator(std::unique_ptr<Beverage> component_) : component(std::move(component_))
    {
    }
    virtual void drink() = 0;

  protected:
    void callComponentDrink()
    {
        if (component)
        {
            component->drink();
        }
    }

  private:
    std::unique_ptr<Beverage> component;
};
class Milk : public BeverageDecorator
{
  public:
    Milk(std::unique_ptr<Beverage> component_, float percentage_)
        : BeverageDecorator(std::move(component_)), percentage(percentage_)
    {
    }
    virtual void drink() override
    {
        callComponentDrink();
        fmt::print(", with milk of richness {}% ", percentage);
    }

  private:
    float percentage;
};
class IceCubes : public BeverageDecorator
{
  public:
    IceCubes(std ::unique_ptr<Beverage> component_, int count_)
        :

          BeverageDecorator(std::move(component_)), count(count_)
    {
    }

    virtual void drink() override
    {

        callComponentDrink();
        fmt::print(", with {} ice cubes", count);
    }

  private:
    int count;
};
class Sugar : public BeverageDecorator
{
  public:
    Sugar(std::unique_ptr<Beverage> component_, int spoon_) : BeverageDecorator(std::move(component_)), spoons(spoon_)
    {
    }
    virtual void drink() override
    {
        callComponentDrink();
        fmt::print(", with {} spoons of sugar", spoons);
    }

  private:
    int spoons = 1;
};
int main()
{
    std::unique_ptr<Beverage> soda = std::make_unique<Soda>();
    soda = std ::make_unique<IceCubes>(std::move(soda), 3);
    soda = std::make_unique<Sugar>(std::move(soda), 1);

    soda->drink();
    fmt::print("\n");

    std::unique_ptr<Beverage> coffee = std::make_unique<Coffee>();
    coffee = std::make_unique<IceCubes>(std::move(coffee), 16);
    coffee = std::make_unique<Milk>(std::move(coffee), 3);
    coffee = std::make_unique<Sugar>(std::move(coffee), 2);

    coffee->drink();
    return 0;
}