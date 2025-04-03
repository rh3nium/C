// Print Fibonacci Series

#include<stdio.h>
int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
    int terms = 20;
    printf("Fibonacci Series\n");
    for (int i = 0; i < terms; i++) {
        printf("%d ", fibonacci(i));
    }
    return 0;
}