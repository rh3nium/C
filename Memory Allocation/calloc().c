// calloc() - Allocates multiple memory blocks dynamically

#include<stdio.h>
#include<stdlib.h>
int main() {
    int *ptr;
    int n = 5, i;
    // Allocate memory dynamically
    ptr = (int*) calloc(n, sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit if fails
    }
    printf("Values after calloc(): ");
    for (i = 0; i < n; i++) {
        printf("%d", ptr[i]); /* Output: Values after calloc(): 00000 */
    }
    free(ptr);
    return 0;
}
