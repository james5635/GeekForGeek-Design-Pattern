#include <bits/stdc++.h>
#include <cmath>
class Pizza {
public:
  virtual void bake() = 0;
  virtual void cut() = 0;
  virtual void box() = 0;
  virtual ~Pizza() {}
};
class NewYorkCheesePizza : public Pizza {
public:
  void bake() override {
    std::cout << "Baking New York-style Cheese Pizza" << std::endl;
  }
  void cut() override {
    std::cout << "Cutting New York-style Cheese Pizza" << std::endl;
  }
  void box() override {
    std::cout << "Boxing New York-style Cheese Pizza" << std::endl;
  }
};
class NewYorkPepperoniPizza : public Pizza {
public:
  void bake() override {
    std::cout << "Baking New York-style Pepperoni Pizza" << std::endl;
  }
  void cut() override {
    std::cout << "Cutting New York-style Pepperoni Pizza" << std::endl;
  }
  void box() override {
    std::cout << "Boxing New York-style Pepperoni Pizza" << std::endl;
  }
};
class ChicagoCheesePizza : public Pizza {
public:
  void bake() override {
    std::cout << "Baking Chicago-style Cheese Pizza" << std::endl;
  }
  void cut() override {
    std::cout << "Cutting Chicago-style Cheese Pizza" << std::endl;
  }
  void box() override {
    std::cout << "Boxing Chicago-style Cheese Pizza" << std::endl;
  }
};
class ChicagoPepperoniPizza : public Pizza {
public:
  void bake() override {
    std::cout << "Baking Chicago-style Pepperoni Pizza" << std::endl;
  }
  void cut() override {
    std::cout << "Cutting Chicago-style Pepperoni Pizza" << std::endl;
  }
  void box() override {
    std::cout << "Boxing Chicago-style Pepperoni Pizza" << std::endl;
  }
};
class PizzaFactory {
public:
  virtual Pizza *createCheesePizza() = 0;
  virtual Pizza *createPepperoniPizza() = 0;
  virtual ~PizzaFactory() {}
};
class NewYorkPizzaFactory : public PizzaFactory {
public:
  Pizza *createCheesePizza() override { return new NewYorkCheesePizza(); }
  Pizza *createPepperoniPizza() override { return new NewYorkPepperoniPizza(); }
};
class ChicagoPizzaFactory : public PizzaFactory {
public:
  Pizza *createCheesePizza() override { return new ChicagoCheesePizza(); }
  Pizza *createPepperoniPizza() override { return new ChicagoPepperoniPizza(); }
};
int main() {
  PizzaFactory *newYorkFactory = new NewYorkPizzaFactory();
  Pizza *newYorkCheesePizza = newYorkFactory->createCheesePizza();
  Pizza *newYorkPepperoniPizza = newYorkFactory->createPepperoniPizza();

  PizzaFactory *chicagoFactory = new ChicagoPizzaFactory();
  Pizza *chicagoCheesePizza = chicagoFactory->createCheesePizza();
  Pizza *chicagoPepperoniPizza = chicagoFactory->createPepperoniPizza();

  newYorkCheesePizza->bake();
  newYorkCheesePizza->cut();
  newYorkCheesePizza->box();

  newYorkPepperoniPizza->bake();
  newYorkPepperoniPizza->cut();
  newYorkPepperoniPizza->box();

  chicagoCheesePizza->bake();
  chicagoCheesePizza->cut();
  chicagoCheesePizza->box();

  chicagoPepperoniPizza->bake();
  chicagoPepperoniPizza->cut();
  chicagoPepperoniPizza->box();

  delete newYorkFactory;
  delete newYorkCheesePizza;
  delete newYorkPepperoniPizza;
  delete chicagoFactory;
  delete chicagoCheesePizza;
  delete chicagoPepperoniPizza;

  return 0;
}
