// Function with arguments and no return values

#include<stdio.h>
int main() {
    printf("Function with arguments and no return values\n\n");
    int num1 = 5, num2 = 10;
    addNos(num1, num2); /* Output: 15 */
    return 0;
}
void addNos(int a, int b) {
    int sum = a + b;
    printf("%d\n", sum);
}