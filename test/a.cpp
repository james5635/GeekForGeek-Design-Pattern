#include <iostream>
int main()
{
    int x = 10;
    int &y = x;

    int &z = x;
    std::cout << "x: " << x << std::endl;
    y++;
    std::cout << "y: " << y << std::endl;
}