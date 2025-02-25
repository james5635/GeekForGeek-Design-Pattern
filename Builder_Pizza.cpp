#include <iostream>
#include <string>
class Pizza
{
  public:
    void setDough(const std::string &dough)
    {
        this->dough = dough;
    }
    void setSource(const std::string &source)
    {
        this->source = source;
    }
    void setTopping(const std::string &topping)
    {
        this->topping = topping;
    }
    void displayPizza()
    {
        std::cout << "Pizza with Dough: " << dough << ", Source: " << source << ", Topping: " << topping << std::endl;
    }

  private:
    std::string dough;
    std::string source;
    std::string topping;
};
class PizzaBuilder
{
  public:
    virtual void buildDough() = 0;
    virtual void buildSource() = 0;
    virtual void buildTopping() = 0;
    virtual Pizza getPizza() const = 0;
};
class HawaiianPizzaBuilder : public PizzaBuilder
{
  public:
    void buildDough() override
    {
        pizza.setDough("Pan Dough");
    }
    void buildSource() override
    {
        pizza.setSource("Hawaiian Source");
    }
    void buildTopping() override
    {
        pizza.setTopping("Ham and Pineapple");
    }
    Pizza getPizza() const override
    {
        return pizza;
    }

  private:
    Pizza pizza;
};
class SpicyPizzaBuilder : public PizzaBuilder
{
  public:
    void buildDough() override
    {
        pizza.setDough("Thin Dough");
    }
    void buildSource() override
    {
        pizza.setSource("Spicy Tomato Source");
    }
    void buildTopping() override
    {
        pizza.setTopping("Pepperoni and Jalapenos");
    }
    Pizza getPizza() const override
    {
        return pizza;
    }

  private:
    Pizza pizza;
};
class Cook
{
  public:
    void makePizza(PizzaBuilder &builder)
    {
        builder.buildDough();
        builder.buildSource();
        builder.buildTopping();
    }
};
int main()
{
    Cook cook;

    HawaiianPizzaBuilder hawaiianPizzaBuilder;
    cook.makePizza(hawaiianPizzaBuilder);
    Pizza hawaiianPizza = hawaiianPizzaBuilder.getPizza();
    hawaiianPizza.displayPizza();

    SpicyPizzaBuilder spicyPizzaBuilder;
    cook.makePizza(spicyPizzaBuilder);
    Pizza spicyPizza = spicyPizzaBuilder.getPizza();
    spicyPizza.displayPizza();

    return 0;
}
