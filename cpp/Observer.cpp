#include <iostream>
#include <vector>
// Observer interface
class Observer
{
  public:
    virtual void update(float temperator, float humidity,
                        float preasure) = 0; // Pure virtual function
};
// Subject (WeatherSation) class
class WeatherStation
{
  private:
    std::vector<Observer *> observers; // List of observers
    float temperator;
    float humidity;
    float preasure;

  public:
    void registerObserver(Observer *observer)
    {
        observers.push_back(observer);
    }
    void removeObserver(Observer *observer)
    {
        // Remove observer from the list
    }
    void notifyObservers()
    {
        for (auto observer : observers)
        {
            observer->update(temperator, humidity, preasure);
        }
    }
    void setMeasurements(float t, float h, float p)
    {
        temperator = t;
        humidity = h;
        preasure = p;
        notifyObservers();
    }
};
// Concrete observer class
class Display: public Observer
{
  public:
    void update(float temperator, float humidity, float preasure) override
    {
        std::cout << "Display: Temperature = " <<
        temperator << "°C, Humidity = " <<
        humidity << "%, Pressure = " << preasure << "hPa" << std::endl;

    }
};
int main()
{
    WeatherStation weatherStation;
    Display display;
    Display display2;

    weatherStation.registerObserver(&display);
    weatherStation.registerObserver(&display2);
    weatherStation.setMeasurements(25.0, 65.0, 1013.0);
    weatherStation.setMeasurements(30.0, 70.0, 1012.0);

    return 0;
}