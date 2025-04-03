// Pointer pointing to another pointer

#include <stdio.h>
int main() {
    int *ptr1 = (int*)88;
    int *ptr2 = (int*)12;
    printf("Address of ptr1: %p\n", (void*)&ptr1);
    // Assign address of ptr2 to ptr1
    ptr1 = (int*)&ptr2;
    printf("New Address of ptr1: %p\n", (void*)ptr1);
    return 0;
}