// Find number of occurrences of element in array

#include<stdio.h>
int main() {
    printf("Find number of occurences of element in array\n\n");
    int array1[7] = {1, 2, 3, 9, 70, 11, 0};
    // Define number of elements in array
    int n = 7;
    // Define element to be input by user
    int element;
    // Get user input for element to search
    printf("Enter the element to search: ");
    scanf("%d", &element);
    // Search if user input is an element in array, define index of element i
    for (int i = 0; i < n; i++) {
        // Define position of element in array, starting from 1 (different from index)
        int pos = i + 1;
        if (array1[i] == element) {
            // If element found
            printf("Element found at: index %d, position %d\n", i, pos);
            return 0;
        }
    }
    // If element not found
    printf("Element not found\n");
    return 0;
}