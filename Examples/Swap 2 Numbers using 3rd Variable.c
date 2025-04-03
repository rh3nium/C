// Swap two numbers using 3rd variable

#include <stdio.h>
int main() {
    int num1, num2, temp;
    printf("Enter number 1: ");
    scanf("%d", &num1);
    printf("Enter number 2: ");
    scanf("%d", &num2);
    printf("Before swapping: num1 = %d, num2 = %d\n", num1, num2);
    temp = num1;
    num1 = num2;
    num2 = temp;
    printf("After swapping: num1 = %d, num2 = %d\n", num1, num2);
    return 0;
}
