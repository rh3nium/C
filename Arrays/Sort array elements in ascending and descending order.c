// Sort array elements in ascending/descending order

#include <stdio.h>

// Function to print array
void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Function to manually add an element to the start
void addToFront(int arr[], int *size, int index) {
    int value = arr[index];
    // Shift all elements right to make space at index 0
    for(int i = index; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = value;
}

void sortArray(int arr[], int size, int isAscending) {
    for(int i = 0; i < size - 1; i++) {
        // Ascending order: if current element > next, move the next one to the front
        // Descending order: if current element < next, move the next one to the front
        if ((isAscending && arr[i] > arr[i + 1]) || (!isAscending && arr[i] < arr[i + 1])) {
            addToFront(arr, &size, i + 1);
        }
    }
}

int main() {
    int arr[100] = {5, 3, 8, 1, 2};  // Original array
    int size = 5;
    int order;

    // Get the user's choice for sorting order
    printf("Choose sort order:\n1. Ascending\n2. Descending\n");
    scanf("%d", &order);

    // Ascending is 1, Descending is 0
    int isAscending = (order == 1) ? 1 : 0;

    // Sort the array based on user input
    sortArray(arr, size, isAscending);

    // Print the final sorted array
    printf("Sorted array: ");
    printArray(arr, size);

    return 0;
}