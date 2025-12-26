//-- Bubble Sort --//

#include <stdio.h>

// Swap function with temp variable
void swap(int *arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

// Bubble Sort function to check values and call swap() function
void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    // Last i elements are already in place, so the loop will only num n - i - 1 times
    for (int j = 0; j < n - i - 1; j++) {
      // If next element is greater than current element, swap elements
      if (arr[j] > arr[j + 1])
        swap(arr, j, j + 1);
    }
  }
}


// MAIN FUNCTION //
int main() {
  int arr[] = {5, 8, 2, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  // Calling bubble sort on array arr
  bubbleSort(arr, n);

  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  
  return 0;
}
