// Accessing variables using pointers

#include<stdio.h>
int main() {
    int num = 10;
    int *ptr;
    ptr = &num;
    printf("Value of num using pointer: %d\n", *ptr); // Output: 10
    printf("Address of num: %d\n", ptr); // Output: -11268
    printf("Address of pointer: %d\n", &ptr); // Output: -11264
    printf("Value of num: %d\n", num); // Output: 10
}