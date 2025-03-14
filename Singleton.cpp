#include <iostream>
class Singleton
{
  public:
    static Singleton &getInstance()
    {
        if (!instance)
        {
            instance = new Singleton();
        }
        return *instance;
    }
    void someOperation()
    {
        std::cout << "Singleton is performing some operation." << std::endl;
    }
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

  private:
    Singleton()
    {
        std::cout << "Singleton instance created." << std::endl;
    }
    ~Singleton()
    {
        std::cout << "Singleton instance destroyed." << std::endl;
    }
    static Singleton *instance;
};
Singleton *Singleton::instance = nullptr;
int main()
{
    Singleton &singleton = Singleton::getInstance();
    singleton.someOperation();
    return 0;
}
