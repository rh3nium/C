// arr[pos] = value - Insert element into 1D array

#include <stdio.h>
int main() {
    int array1[6]= {10, 20, 30, 55, 99};
    // Initialize variables for position and element to be inserted
    int pos = 2, value = 333;
    for (int i = 5; i > pos; i--) {
        array1[i] = array1[i - 1];
    }
    array1[pos] = value;
    for (int i = 0; i < 6; i++) {
        // Print updated array after overwriting element
        printf("%d ", array1[i]); /* Output: 10 20 333 30 55 99 */
    }
    return 0;
}