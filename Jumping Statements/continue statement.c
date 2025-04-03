// continue statement

#include<stdio.h>
int main() {
    for (int i = 1; i <= 9; i++) {
        if (i == 5) {
            continue;
        }
        printf("%d", i);
    }
    return 0;
}

/* Output: 123456789 */