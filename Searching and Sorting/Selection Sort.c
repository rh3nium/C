//-- Selection Sort --//

#include <stdio.h>

// Selection sort function
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
      
        // Assume the current position holds the minimum element
        int min_index = i;
        
        // Iterate through the unsorted portion to find the actual minimum element
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
              
                // Update min_index if a smaller element is found
                min_index = j;
            }
        }
        
        // Move minimum element to its
        // correct position
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


// MAIN FUNCTION //
int main() {
    int arr[] = {64, 23, 17, 49, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: ");
    printArray(arr, n);
    
    selectionSort(arr, n);
    
    printf("Sorted array: ");
    printArray(arr, n);
    
    return 0;
}
