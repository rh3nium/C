// -- 2D Array -- //

#include <stdio.h>
int main() {
    printf("2D Array\n\n");
    // Initialize 2D array
    int array1[4][3] = {
        {10, 20, 30},
        {40, 50, 60},
        {80, 100, 101},
        {103, 104, 110}
    };
    // Print all elements in the array
    printf("Elements of the array: ");
    for (int i = 0; i < 4; i++) {
        for (int z = 0; z < 3; z++) {
            printf("%d ", array1[i][z]);
        }
    }
    printf("\n");
    return 0;
}

/* Output:
Elements of the array: 10 20 30 40 50 60 80 100 101 103 104 110
*/
