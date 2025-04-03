// Pointer Addition

#include<stdio.h>
int main() {
    int a = 10, b = 20, result;
    int *pA = &a, *pB = &b, *pResult = &result;
    // Addition
    *pResult = (*pA) + (*pB);
    printf("Sum = %d\n", result); // Output: Sum = 30
    return 0;
}