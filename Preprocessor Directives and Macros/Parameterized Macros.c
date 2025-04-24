// Parameterized Macros

#include <stdio.h>
// Parameterized macros
#define SQUARE(x) ((x) * (x))
#define CUBE(x) ((x) * (x) * (x))
int main() {
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);
    printf("Square of %d = %d\n", number, SQUARE(number));
    printf("Cube of %d = %d\n", number, CUBE(number));
    return 0;
}