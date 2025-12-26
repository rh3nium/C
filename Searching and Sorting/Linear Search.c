//-- Linear Search --//
#include <stdio.h>

int linearSearch(int* arr, int n, int key) {
  
    // Loop to search for the key in arr
    for (int i = 0; i < n; i++) {

        // If key is found, return key
        if (arr[i] == key) {
            return i;
        }
    }

    // If key is not found, return some value to indicate end
    return -1;
}

int main() {
    int arr[] = { 10, 50, 30, 70, 80, 60, 20, 90, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    // Calling linearSearch() for arr with key = 43
    int i = linearSearch(arr, n, key);

    // printing result based on value returned by linearSearch()
    if (i == -1)
        printf("Key Not Found");
    else
        printf("Key Found at Index: %d", i);

    return 0;
}
