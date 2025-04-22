// malloc() - Allocates single memory block dynamically

#include<stdio.h>
#include<stdlib.h>
int main() {
    int *ptr;
    int n, i;
    // Allocate memory dynamically
    ptr = (int*) malloc(5 * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit if fails
    }
    printf("Enter the number of integers you want to enter: ");
    scanf("%d", &n);
    ptr = (int*) malloc(n * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }
    printf("\nYou entered: ");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    free(ptr);
    return 0;
}