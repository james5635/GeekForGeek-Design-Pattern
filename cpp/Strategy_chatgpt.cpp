#include <iostream>
#include <memory>

// Strategy interface
class AttackStrategy
{
  public:
    virtual void attack() const = 0;
    virtual ~AttackStrategy() = default;
};
// Concrete strategy
class SwordAttack : public AttackStrategy
{
  public:
    void attack() const override
    {
        std::cout << "Attacking with a sword!" << std::endl;
    }
};
class BowAttack : public AttackStrategy
{
  public:
    void attack() const override
    {
        std::cout << "Shooting arrow with a bow!" << std::endl;
    }
};
class MagicAttack : public AttackStrategy
{
  public:
    void attack() const override
    {
        std::cout << "Casting a powerful magic spell!" << std::endl;
    }
};
// Context
class Character
{
  private:
    std::unique_ptr<AttackStrategy> attackStrategy;

  public:
    Character(std::unique_ptr<AttackStrategy> strategy) : attackStrategy(std::move(strategy))
    {
    }
    void setAttackStrategy(std::unique_ptr<AttackStrategy> strategy)
    {
        attackStrategy = std::move(strategy);
    }
    void performAttack() const
    {
        attackStrategy->attack();
    }
};
// Client code
int main()
{
    // Create a character with a sword attack strategy
    Character knight(std::make_unique<SwordAttack>());
    knight.performAttack(); // Output: Attacking with a sword!

    // Change the attack strategy to bow attack
    knight.setAttackStrategy(std::make_unique<BowAttack>());
    knight.performAttack(); // Output: Shooting arrow with a bow!

    // Change the attack strategy to magic attack
    knight.setAttackStrategy(std::make_unique<MagicAttack>());
    knight.performAttack(); // Output: Casting a powerful magic spell!

    return 0;
}