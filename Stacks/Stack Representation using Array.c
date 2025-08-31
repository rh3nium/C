// Stack representation using array

#include <stdio.h>

// define size of array
#define SIZE 100;
int stack[SIZE]; // define fized-size array
int top = -1; // define int variable top with index of last inserted element

int main() {
    printf("Stack initialized. Top = %d\n", top);
    return 0;
}
