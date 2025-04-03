// Conditional Operator

#include<stdio.h>
void main() {
    printf("Conditional Operator\n\n");
    int a, b, max;
    printf("Enter value of a: ");
    scanf("%d", &a);
    printf("Enter value of b: ");
    scanf("%d", &b);
    max = (a>b)?a:b;
    printf("Maximum number between %d and %d: %d\n", a, b, max);
}