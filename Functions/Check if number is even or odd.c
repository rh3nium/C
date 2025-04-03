// Check if number is even or odd

#include<stdio.h>
int evenorodd (int a) {
    if (a%2==0) {
        printf("Number %d is even\n", a);
    }
    else {
        printf("Number %d is odd\n", a);
    }
    return 0;
}
int main() {
    printf("Check if number is even or odd:\n\n");
    evenorodd(13); /* Output: Number 13 is odd */
    // Declaring int variable, then passing it in function call
    int x = 42;
    evenorodd(x); /* Output: Number 42 is even */
    return 0;
}
