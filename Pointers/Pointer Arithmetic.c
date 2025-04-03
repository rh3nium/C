// Pointer Arithmetic

#include<stdio.h>
int main() {
    int i = 100;
    int *p;
    p = &i;
    printf("Value of p: %p\n", p);
    printf("Pointer p value: %p\n", p);
    // Addition - Moves memory address forward
    printf("%p\n", p + 9);
    // Subtraction - Moves memory address behind
    printf("%p\n", p - 3);
    printf("%p\n", p - 2);
}