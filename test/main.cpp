// namespace A
// {
// #include <iostream>
// #include <list>
// #include <stdio.h>
// struct B
// {
//   public:
//     // x will use the member initializer with list initialization  which invoke the constructor with
//     // std::initializer_list
//     B() : x{11, 12, 13, 14}
//     {
//     }
//     std::list<int> x{10};
//     // declare member y using this default memeber initializer {} with list initialization which perform value
//     // initialization which perfrom default initialization which invoke the default constructor
//     std::list<int> y{};
//     // declare member z using thsi default member initalizer {19} with list initialization  which invoke the
//     constructor
//     // with std::initializer_list
//     std::list<int> z{19};
//     // declare member k with default initialization which perform nothing
//     int k;
//     // declare member l using default member initializer = 20 with copy initialization
//     int l = 20;

//     /*
//         copy initialization include 5 case
//     */
// };
// int main()
// {
//     B b;
//     std::cout << "------------- printing b.x ------------\n";
//     for (auto &i : b.x)
//     {
//         std::cout << i << std::endl;
//     }
//     std::cout << "------------- printing b.y ------------\n";

//     for (auto &i : b.y)
//     {
//         std::cout << i << std::endl;
//     }
//     std::cout << "------------- printing b.z ------------\n";
//     for (auto &i : b.z)
//     {
//         std::cout << i << std::endl;
//     }
//     return 0;
// }

// } // namespace A

#include <iostream>
void process(const int &x)
{
    std::cout << "const Lvalue\n";
}
void process(int &x)
{
    std::cout << "Lvalue\n";
}
void process(int &&x)
{
    std::cout << "Rvalue\n";
}

template <typename T> void wrapper(T &&arg)

{
    std::cout << typeid(T).name() << std::endl;
    process(std::forward<T>(arg)); // Always calls `process(int&)`, even for rvalues!

    process(arg); // Always calls `process(int&)`, even for rvalues!
}

int main()
{
    const int a = 10;
    int b = 20;
    int c = 20;

    // int &b = a;
    // std::cout << b << std::endl;
    // b = c;
    // std::cout << b << std::endl;

    // int &j = a;
    int &&k = 9;
    int &&l = 6;

    typedef int &lref;
    typedef int &&rref;
    int n;

    lref &r1 = n;  // type of r1 is int&
    lref &&r2 = n; // type of r2 is int&
    rref &r3 = n;  // type of r3 is int&
    rref &&r4 = 1; // type of r4 is int&&

    wrapper(10); // Calls process(int&) -> "Lvalue"
    // wrapper(20); // Calls process(int&) -> Wrong! Expected "Rvalue", but got "Lvalue"

    auto &&vec = {1, 2, 3};   // foo() may be lvalue or rvalue, vec is a forwarding reference
    auto i = std::begin(vec); // works either way

    auto &&z = {1, 2, 3}; // *not* a forwarding reference (special case for initializer lists)
                          // auto j = std::begin(z); // error: begin() requires an lvalue
                          // auto &p = 10;
                          /*
                          T& &   == T&
                          T& &&  == T&
                          T&& &  == T&
                          T&& && == T&&
                      
                          auto         => will copy the vector, but we wanted a reference
                          auto&        => will only bind to modifiable lvalues
                          const auto&  => will bind to anything but make it const, giving us const_iterator
                          const auto&& => will bind only to rvalues
                          */
    const int &x = 10;
    const int o = 11;
    const int &m = o;
}
