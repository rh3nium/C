// Take user input for array elements

#include<stdio.h>
int main() {
    printf("Take user input for array elements\n\n");
    int arr[5];
    // Take user input for array elements
    for (int i = 0; i < 5; i++) {
        int pos = i + 1;
        printf("Enter element %d: \n", pos);
        scanf("%d", &arr[i]);
    }
    // Print array element4
    printf("The elements of the array are: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}