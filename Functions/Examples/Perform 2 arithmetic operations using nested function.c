// Perform arithmetic operations using nested functions

#include<stdio.h>
void operations(int n1, int n2) {
    if (n1>n2) {
        if (n1>5) {
            printf("%d - %d = %d\n", n1, n2, n1-n2);
        }
        else {
            printf("%d - %d = %d\n", n2, n1, n2-n1);
        }
    }
    else {
        printf("%d * %d = %d", n2, n1, n2*n1);
    }
}
int main() {
    int n1, n2;
    printf("Enter number 1: \n");
    scanf("%d", &n1);
    printf("Enter number 2: \n");
    scanf("%d", &n2);
    operations(n1, n2);
    return 0;
}