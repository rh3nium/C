// Pointer Subtraction

#include<stdio.h>
int main() {
    int a = 10, b = 20, result;
    int *pA = &a, *pB = &b, *pResult = &result;
    // Difference
    *pResult = (*pA) - (*pB);
    printf("Difference = %d\n", result); // Output: Difference = -10
    return 0;
}