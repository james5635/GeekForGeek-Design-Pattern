#include <iostream>
class Engine
{
  public:
    void Start()
    {
        std::cout << "Engine started" << std ::endl;
    }
    void Stop()
    {
        std::cout << "Engline stopped" << std::endl;
    }
};
class Lights
{
  public:
    void TurnOn()
    {
        std::cout << "Light On" << std::endl;
    }
    void TurnOff()
    {
        std::cout << "Light Off" << std::endl;
    }
};
class Car
{
  private:
    Engine engine;
    Lights light;

  public:
    void StartCar()
    {
        engine.Start();
        light.TurnOn();
        std::cout << "Car is ready to drive" << std ::endl;
    }
    void StopCar()
    {
        light.TurnOff();
        engine.Stop();
        std::cout << "Car has stopped" << std::endl;
    }
};
int main()
{
    Car car;
    car.StartCar();
    car.StopCar();
    return 0;
}