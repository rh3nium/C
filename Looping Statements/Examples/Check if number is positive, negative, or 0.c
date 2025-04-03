// Check if number is positive, negative, or 0

#include <stdio.h>
int main() {
    int num1;
    printf("Enter a number: ");
    scanf("%d", &num1);
    if (num1 > 0) {
        printf("%d is positive.\n", num1);
    } else if (num1 < 0) {
        printf("%d is negative.\n", num1);
    } else {
        printf("%d is equal to 0.\n", num1);
    }
    return 0;
}