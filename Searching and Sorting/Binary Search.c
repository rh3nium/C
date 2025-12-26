//-- Binary Search --//
// Binary search is an efficient divide-and-conquer algorithm used to quickly find a target value within a sorted array. It works by repeatedly halving the search space until the target is found or the search interval becomes empty

#include <stdio.h>

// Binary search function to repeatedly halve array until target is found/search interval is empty
int binarySearch(int array[], int x, int low, int high) {
  // Repeat until the pointers low and high meet each other
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (x == array[mid])
      return mid;

    if (x > array[mid])
      low = mid + 1;

    else
      high = mid - 1;
  }

  return -1;
}


// MAIN FUNCTION //
int main(void) {
  int array[] = {3, 4, 33, 6, 15, 8, 9};
  int n = sizeof(array) / sizeof(array[0]);
  int x = 4;
  int result = binarySearch(array, x, 0, n - 1);
  if (result == -1)
    printf("Not found");
  else
    printf("Element is found at index %d", result);
  return 0;
}
