// sizeof() Operator
// Finds size in bytes of a variable

#include <stdio.h>
int main()
{
    int num;
    float flt;
    double dbl;
    char chr;
    printf("Size of int: %zu bytes \n", sizeof(num)); // Output: Size of int: 4 bytes
    printf("Size of float: %zu bytes \n", sizeof(flt)); // Output: Size of float: 4 bytes
    printf("Size of double: %zu bytes \n", sizeof(dbl)); // Output: Size of double: 8 bytes
    printf("Size of char: %zu bytes \n", sizeof(chr)); // Output: Size of char: 1 bytes
}
