// Pointers

#include<stdio.h>
int main() {
    int a = 100;
    // Define pointer: datatype *pointer_name
    int *pointer1;
    // Assign int a value to pointer
    *pointer1 = a;
    // Print pointer1 value
    printf("%d", *pointer1); // Output: 100
}