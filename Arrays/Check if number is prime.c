// Check if number is prime

#include <stdio.h>
#include <stdbool.h>
int main() {
    printf("Check if number is prime\n\n");
    int num;
    bool isPrime = true;
    label1:
    printf("Enter a positive number: \n");
    scanf("%d", &num);
    if (num < 0) {
        printf("Please enter a positive number.\n");
        goto label1;
    }
    else if (num <= 1) {
        isPrime = false; // 1 and numbers < 1 are not prime
    } else {
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = false; // If divisible by any number, it's not prime
                break;
            }
        }
    }
    if (isPrime) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }
    return 0;
}