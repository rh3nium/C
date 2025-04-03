// Check if number is palindrome

#include<stdio.h>
int main() {
    int num, rev = 0, rem, original;
    printf("Enter a number: ");
    scanf("%d", &num);
    original = num;
    while (num != 0) {
        rem = num % 10;
        rev = rev * 10 + rem;
        num /= 10;
    }
    if (original == rev) {
        printf("Number is a palindrome \n");
    }
    else {
        printf("Number is not a palindrome \n");
    }
}