// break statement

#include<stdio.h>
int main() {
    for (int i = 1; i <= 10; i++) {
        if (i == 5) {
            // break statement - terminates the loop
            break;
        }
        printf("%d", i);
    }
    return 0;
}

/* Output: 1234 */