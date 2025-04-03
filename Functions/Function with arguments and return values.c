// Function with arguments and return values

#include<stdio.h>
int square (int n);
int main() {
    printf("Function with arguments and return values\n\n");
    int num = 5;
    int result = square(num);
    printf("%d\n", result); /* Output: 25 */
    return 0;
}
int square(int n) {
    return n * n;
}