#include <iostream>
// State Interface
class TrafficLightState
{
  public:
    virtual void handle() = 0;
    virtual ~TrafficLightState() = default;
};
// Concrete States
class RedState : public TrafficLightState
{
  public:
    void handle() override
    {
        std::cout << "Traffic Light is Red" << std::endl;
    }
};
class GreenState : public TrafficLightState
{
  public:
    void handle() override
    {
        std::cout << "Traffic Light is Green" << std::endl;
    }
};
class YellowState : public TrafficLightState
{
  public:
    void handle() override
    {
        std::cout << "Traffic Light is Yellow" << std::endl;
    }
};
// Context
class TrafficLight
{
  private:
    TrafficLightState *state;

  public:
    TrafficLight() : state(new RedState)
    {
    }
    void setState(TrafficLightState *newState)
    {
        delete state; // Clean up the old state
        state = newState;
    }
    void change()
    {
        state->handle();
    }
};
int main()
{
    TrafficLight light;
    light.change(); // Red
    light.setState(new GreenState());
    light.change(); // Green
    light.setState(new YellowState());
    light.change(); // Yellow
    return 0;
}