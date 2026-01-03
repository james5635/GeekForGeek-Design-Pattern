#include <iostream>
#include <map>
#include <string>
class Tenant
{
  public:
    Tenant(const std::string &name = "") : m_name(name)
    {
    }
    std::string name() const
    {
        return m_name;
    }

  private:
    std::string m_name;
};
class Registry
{
  public:
    Registry() : tenants()
    {
    }
    Tenant &findByName(const std::string &name)
    {
        if (!tenants.contains(name))
        {
            tenants[name] = Tenant{name};
        }
        return tenants[name];
    }

  private:
    std::map<std::string, Tenant> tenants;
};
class Apartment
{
  public:
    Apartment() : m_occupants(), m_registry()
    {
    }
    void addOccupant(const std::string &name, int room)
    {
        m_occupants[room] = &m_registry.findByName(name);
    }
    void tenants()
    {
        for (const auto &i : m_occupants)
        {
            const int &room = i.first;
            const auto &tenant = i.second;
            std::cout << tenant->name() << " occupies room " << room << std::endl;
        }
    }

  private:
    std::map<int, Tenant *> m_occupants;
    Registry m_registry;
};
int main()
{
    Apartment apartment;
    apartment.addOccupant("David", 1);
    apartment.addOccupant("Sarah", 3);
    apartment.addOccupant("George", 12);
    apartment.addOccupant("Sarah", 12);
    apartment.addOccupant("Michael", 10);
    apartment.tenants();
    return 0;
}