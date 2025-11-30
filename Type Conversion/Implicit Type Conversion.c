// -- Implicit Type Conversion -- //

#include<stdio.h>
int main() {
    float var = 20;
    char ch = 'B';
    float res;
    res = ch + var;
    printf("Result: %f\n", res);
    return 0;
}

// Output: Result: 86.000000
