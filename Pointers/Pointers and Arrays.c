// Pointers and arrays

#include<stdio.h>
int main() {
    int array1[] = {10, 20, 90, 40, 70};
    int *ptr = array1;
    printf("First element in array: %d\n", *ptr); // Output: 10
    printf("2nd element in array: %d\n", *(ptr + 1)); // Output: 20
    printf("Element which doesn't exist in array: %d\n", *(ptr + 5)); // Output: 32767 (garbage value)
    // Store address of entire array
    int (*ptr2)[5] = &array1;
    printf("3rd element in array: %d\n", (*ptr2)[2]); // Output: 90
    return 0;
}