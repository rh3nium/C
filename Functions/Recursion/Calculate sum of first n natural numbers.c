// Calculate sum of first n natural numbers

#include<stdio.h>
int sumnos(int n) {
    if (n==0)
        return 0;
    else return n + sumnos(n - 1);
}
int main() {
    int n;
    printf("Enter a natural number: ");
    scanf("%d", &n);
    printf("Sum of numbers = %d\n", sumnos(n));
    return 0;
}
