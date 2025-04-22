// realloc() - Reallocates/Resizes memory block

#include<stdio.h>
#include<stdlib.h>
int main() {
    int *ptr;
    ptr = (int*) malloc(2 * sizeof(int)); // Allocate memory for integers
    ptr[0] = 10;
    ptr[1] = 20;
    printf("Before realloc(): %d %d\n", ptr[0], ptr[1]); /* Output: Before realloc(): 10 20 */
    // realloc() - resize memory
    ptr = (int*) realloc(ptr, 3 * sizeof(int));
    ptr[2] = 30; // Assign new value
    printf("After realloc(): %d %d %d\n", ptr[0], ptr[1], ptr[2]); /* Output: After realloc(): 10 20 30 */
    free(ptr);
    return 0;
}