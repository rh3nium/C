// Modifying variables using pointers

#include<stdio.h>
int main() {
    int num = 11;
    int *ptr;
    ptr = num;
    printf("Modifying variables using pointers\n\n");
    printf("Value of pointer: %d\n", ptr); /* Output: 11 */
    // Modifying variable using pointer
    ptr = 44;
    printf("Modified value of pointer: %d\n", ptr); /* Output: 44 */
    return 0;
}
