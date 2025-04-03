// Pointer Division

#include<stdio.h>
int main() {
    int a = 33, b = 3, result;
    int *pA = &a, *pB = &b, *pResult = &result;
    // Division
    *pResult = (*pA) / (*pB);
    printf("Quotient = %d\n", result); // Output: Quotient = 11
    return 0;
}