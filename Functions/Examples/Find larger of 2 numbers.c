// FInd larger of 2 numbers

#include<stdio.h>
void larger(int n1, int n2) {
    if (n1>n2) {
        printf("%d is larger\n", n1);
    }
    else { printf("%d is larger\n", n2); }
}
int main() {
    int n1, n2;
    printf("Enter number 1: \n");
    scanf("%d", &n1);
    printf("Enter number 2: \n");
    scanf("%d", &n2);
    larger(n1, n2);
    return 0;
}