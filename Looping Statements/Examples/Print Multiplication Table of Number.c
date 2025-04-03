// Print multiplication table of number entered by user

#include <stdio.h>
int main() {
    int num;
    int product;
    printf("Enter a number: ");
    scanf("%d", &num);
    for (int i = 1; i <= 12; i++) {
        product = num * i;
        printf("%d*%d=%d\n", num, i, product); 
    }
    return 0;
}