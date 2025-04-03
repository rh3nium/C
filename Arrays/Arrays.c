// Arrays

#include<stdio.h>
int main() {
    printf("Arrays\n\n");
    // Create array
    int array1[4] = {10, 20, 30, 40};
    // Print element at specific index
    printf("Element at position 2: %d\n", array1[2]); /* Output: Element at position 2: 30 */

    // Print all elements in array
    for (int i = 0; i < 4; i++) {
        printf("%d \n", array1[i]);
    }
    /* Output:
    10
    20
    30
    40
    */
}

