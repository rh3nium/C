// Recursive function - function that calls itself

// Function to calculate factorial of a number
#include<stdio.h>
int factorial(int n) {
    if (n==0)
        return 1;
    // Calling function inside function
    else return n * factorial(n - 1);
}
int main() {
    int num = 5;
    printf("Factorial of %d = %d\n", num, factorial(num)); /* Output: Factorial of 5 = 120 */
    return 0;
}
