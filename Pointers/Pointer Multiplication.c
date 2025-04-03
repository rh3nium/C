// Pointer Multiplication

#include<stdio.h>
int main() {
    int a = 10, b = 20, result;
    int *pA = &a, *pB = &b, *pResult = &result;
    // Multiplication
    *pResult = (*pA) * (*pB);
    printf("Product = %d\n", result); // Output: Product = 200
    return 0;
}