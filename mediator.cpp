#include <iostream>
#include <string>

class AirTrafficControlTower;

// Colleague Interface
class Airplane
{
  public:
    virtual void requestTakeoff() = 0;
    virtual void requestLanding() = 0;
    virtual void notifyAirTrafficControl(const std::string &message) = 0;
};

// Mediator interface
class AirTrafficControlTower
{
  public:
    virtual void requestTakeoff(Airplane *airplane) = 0;
    virtual void requestLanding(Airplane *airplane) = 0;
};


// Concrete Colleague
class CommercialAirplane : public Airplane
{
  private:
    AirTrafficControlTower *mediator;

  public:
    CommercialAirplane(AirTrafficControlTower *mediator) : mediator(mediator)
    {
    }
    void requestTakeoff() override
    {
        mediator->requestTakeoff(this);
    }
    void requestLanding() override
    {
        mediator->requestLanding(this);
    }
    void notifyAirTrafficControl(const std::string &message) override
    {
        std::cout << "Commercial Airplane: " << message << std::endl;
    }
};

// Concrete Mediator
class AirportControlTower : public AirTrafficControlTower
{
  public:
    void requestTakeoff(Airplane *airplane) override
    {
        airplane->notifyAirTrafficControl("Requesting takeoff clearance.");
    }
    void requestLanding(Airplane *airplane) override
    {
        airplane->notifyAirTrafficControl("Requesting landing clearance.");
    }
};
int main()
{
    AirTrafficControlTower *tower = new AirportControlTower();
    Airplane *commercialAirplane1 = new CommercialAirplane(tower);
    Airplane *commercialAirplane2 = new CommercialAirplane(tower);
    commercialAirplane1->requestTakeoff();
    commercialAirplane2->requestLanding();
    delete commercialAirplane1;
    delete commercialAirplane2;
    delete tower;
    return 0;
}