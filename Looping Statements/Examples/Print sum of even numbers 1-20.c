// Find largest of 3 numbers

#include<stdio.h>
int main(){
    int a = 5;
    int b = 31;
    int c = 70;
    if (a>b && a>c) {
        printf("%d", a);
    }
    else if (b>a && b>c) {
        printf("%d", b);
    }
    else if (c>a && c>b) {
        printf("%d", c);
    }
    return 0;
}

/* Output:
70
*/