// arr[pos] = value - Overwrite element in 1D array

#include <stdio.h>
int main() {
    int array1[6]= {10, 20, 30, 55, 99, 113};
    // Initialize variables for position and element to be inserted
    int pos = 2, value = 333;
    // Print original array
    printf("Original array: ");
    for (int i = 0; i < 6; i++) {
        printf("%d " , array1[i]); /* Output: 10 20 30 55 99 113 */
    }
    printf("\n");
    // Insert element into array, overwriting original element - arr[pos] = value
    array1[pos] = value;
    printf("Array after overwriting element: ");
    for (int i = 0; i < 6; i++) {
        // Print updated array after overwriting element
        printf("%d " , array1[i]); /* Output: 10 20 333 55 99 113 */
    }
    printf("\n");
    return 0;
}