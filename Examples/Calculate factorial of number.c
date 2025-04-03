// Calculate factorial of number

#include<stdio.h>
int fact() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    double result = 1;
    if (n==0) {
        result = 1;
        printf("Factorial of %d = %lf\n", n, result);
    }
    else {
        for (int i = n; i >= 1; i--) {
            result *= i;
        }
    printf("Factorial of %d = %lf\n", n, result);
}
}
int main() {
    fact();
    return 0;
}