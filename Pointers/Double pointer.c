// Double pointer

#include<stdio.h>
int main() {
    int num = 5;
    int *ptr = &num;
    // Declare double pointer - **pointerName
    int **doublePtr = &ptr;
    printf("Value using double pointer: %d\n", **doublePtr); /* Output: 5 */
    return 0;
}