#include <iostream>
#include <list>
#include <stdio.h>
struct B
{
  public:
    // x will use the member initializer with list initialization  which invoke the constructor with
    // std::initializer_list
    B() : x{11, 12, 13, 14}
    {
    }
    std::list<int> x{10};
    // declare member y using this default memeber initializer {} with list initialization which perform value
    // initialization which perfrom default initialization which invoke the default constructor
    std::list<int> y{};
    // declare member z using thsi default member initalizer {19} with list initialization  which invoke the constructor
    // with std::initializer_list
    std::list<int> z{19};
    // declare member k with default initialization which perform nothing
    int k;
    // declare member l using default member initializer = 20 with copy initialization
    int l = 20;

    /*
        copy initialization include 5 case
    */
};
int main()
{
    B b;
    std::cout << "------------- printing b.x ------------\n";
    for (auto &i : b.x)
    {
        std::cout << i << std::endl;
    }
    std::cout << "------------- printing b.y ------------\n";

    for (auto &i : b.y)
    {
        std::cout << i << std::endl;
    }
    std::cout << "------------- printing b.z ------------\n";
    for (auto &i : b.z)
    {
        std::cout << i << std::endl;
    }
    return 0;
}
