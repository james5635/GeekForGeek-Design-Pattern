#include <iostream>
#include <list>
#include <memory>
#include <stdexcept>
#include <string>
typedef double Currency;
class Equipment
{

  public:
    virtual const std::string &getName()
    {
        return name;
    }
    virtual void setName(const std::string &name_)
    {
        this->name = name_;
    }
    virtual Currency getPrice()
    {
        return netPrice;
    }
    virtual Currency getNetPrice()
    {
        return netPrice;
    }
    virtual void setNetPrice(Currency netPrice_)
    {
        this->netPrice = netPrice_;
    }
    virtual void add(std::shared_ptr<Equipment>) = 0;
    virtual void remove(std::shared_ptr<Equipment>) = 0;
    virtual ~Equipment() = default;

  protected:
    Equipment() : name(""), netPrice(0)
    {
    }
    Equipment(const std::string &name_) : name(name_), netPrice(0)
    {
    }

  private:
    std::string name;
    Currency netPrice;
};
class CompositeEquipment : public Equipment
{
  public:
    virtual Currency getNetPrice() override
    {
        Currency total = Equipment::getNetPrice();
        for (const auto &i : equipment)
        {
            total += i->getNetPrice();
        }
        return total;
    }
    virtual void add(std::shared_ptr<Equipment> equipment_) override
    {
        equipment.push_front(equipment_.get());
    }
    virtual void remove(std::shared_ptr<Equipment> equipment_) override
    {
        equipment.remove(equipment_.get());
    }

  protected:
    CompositeEquipment() : equipment()
    {
    }
    CompositeEquipment(const std::string &name_) : equipment()
    {
        setName(name_);
    }

  private:
    std::list<Equipment *> equipment;
};
class FloppyDisk : public Equipment
{
  public:
    FloppyDisk(const std::string &name_)
    {
        setName(name_);
    }
    void add(std::shared_ptr<Equipment>) override
    {
        throw std::runtime_error("FloppyDisk::add");
    }
    void remove(std::shared_ptr<Equipment>) override
    {
        throw std::runtime_error("FloppyDisk::remove");
    }
};
class Chassis : public CompositeEquipment
{
  public:
    Chassis(const std::string &name_)
    {
        setName(name_);
    }
};

int main()
{
    std::shared_ptr<Equipment> fd1 = std::make_shared<FloppyDisk>("3.5in Floppy");
    fd1->setNetPrice(19.99);
    std::cout << fd1->getName() << ": netPrice " << fd1->getNetPrice() << std::endl;

    std::shared_ptr<Equipment> fd2 = std::make_shared<Chassis>("5.25in Floppy");
    fd2->setNetPrice(29.99);
    std::cout << fd2->getName() << ": netPrice " << fd2->getNetPrice() << std::endl;

    std::unique_ptr<Chassis> ch = std::make_unique<Chassis>("PC Chassis");
    ch->setNetPrice(39.99);
    ch->add(fd1);
    ch->add(fd2);
    std::cout << ch->getName() << ": netPrice " << ch->getNetPrice() << std::endl;

    fd2->add(fd1);

    return 0;
}