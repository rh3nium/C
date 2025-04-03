// Incrementing a pointer

#include<stdio.h>
int main() {
    int array1[] = {1, 2, 3, 5};
    int *ptr;
    ptr = &array1;
    printf("Incrementing a pointer\n\n");
    printf("Pointer value: %d\n", *ptr); /* Output: 1 */
    // Incrementing pointer
    ptr++;
    printf("Incremented pointer value: %d\n", *ptr); /* Output: 2 */
    ptr++;
    printf("3rd pointer value: %d\n", *ptr); /* Output: 3 */
    return 0;
}