// Allocate memory for integer array of size N

#include<stdio.h>
#include<stdlib.h>
int main() {
    int *arr;
    int N, i;
    printf("Enter the number of elements: "); // Ask user for the size of the array
    scanf("%d", &N);
    // Dynamically allocate memory for N integers
    arr = (int *) malloc(N * sizeof(int));
    printf("Enter %d integers:\n", N); // Take input from the user
    for (i = 0; i < N; i++)
    {
    scanf("%d", &arr[i]);
    }
    printf("You entered: "); // Print the array
    for (i = 0; i < N; i++)
    {
    printf("%d ", arr[i]);
    }
    printf("\n");
    // Free allocated memory
    free(arr);
    return 0;
}