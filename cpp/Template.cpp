#include <iostream>
// Template class
class VehicleTemplate
{
    public:
    // Template method
    void buildVehicle()
    {
        assembleBody();
        installEngine();
        addWheels();
        std::cout << "Vehicle is ready.\n";
    }
    // Abstract methods
    virtual void assembleBody() = 0;
    virtual void installEngine() = 0;
    virtual void addWheels() = 0;

};
// Concrete class
class Car : public VehicleTemplate
{
    public:
    void assembleBody() override
    {
        std::cout << "Assembling car body.\n";
    }
    void installEngine() override
    {
        std::cout << "Installing car engine.\n";
    }
    void addWheels() override
    {
        std::cout << "Adding 4 car wheels.\n";
    }
};
// Concrete class
class Motorcycle : public VehicleTemplate
{
    public:
    void assembleBody() override
    {
        std::cout << "Assembling motorcycle frame.\n";
    }
    void installEngine() override
    {
        std::cout << "Installing motorcycle engine.\n";
    }
    void addWheels() override
    {
        std::cout << "Adding 2 motorcycle wheels.\n";
    }
};

// Client code
int main()
{
    std::cout << "Building a car:\n";
    VehicleTemplate* car = new Car();
    car->buildVehicle();
    delete car;

    std::cout << "Building a motorcycle:\n";
    VehicleTemplate* motorcycle = new Motorcycle();
    motorcycle->buildVehicle();
    delete motorcycle;

    return 0;
}