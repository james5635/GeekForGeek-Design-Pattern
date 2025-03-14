#include <stdio.h>
int x();
int main()
{
    x();
    return 0;
}
int x()
{
    char x[4] = "iss";
    char y[4] = "iss\0";
    char z[4] = {'i', 's', 's', '\0'};
    char z1[4] = {'i', 's', 's'};
    printf("%d, %d, %d, %d", x[3], y[3], z[3], z1[3]);
    return 10;
}
