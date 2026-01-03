#include <iostream>
extern int a;
extern int b;
extern int k();
extern int l();
int main(){
    int a1 = a;
    int b2 = b; 
    std::cout << k() << std::endl;
    std::cout << l() << std::endl;
}