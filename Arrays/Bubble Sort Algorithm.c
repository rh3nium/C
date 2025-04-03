// Bubble Sort Algorithm

#include <stdio.h>
void swap(int* arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Last i elements are already in place, so the loop will only run n - i - 1 times
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
        }
    }
}
int main() {
    printf("Bubble Sort Algorithm\n\n");
    int arr[] = { 9, 0, 31, 5, 17, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]); /* Output: 0 4 5 9 17 31*/
    return 0;
}