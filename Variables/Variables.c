// Variables.c

#include <stdio.h>
int main() {
    printf("Variables in C\n\n");
    // Initialize char/string variable
    char str1[] = "Riya";
    // Initialize int variable
    int int1 = 31;
    // Initialize float variable
    float float1 = 9.32;
    // Initialize double variable
    double double1 = 9.3278;
    // Print variables
    printf("char: %s\n", str1); /* Output: char: Riya */
    printf("int: %d\n", int1); /* Output: int: 31 */
    printf("float: %f\n", float1); /* Output: float: 9.320000 */
    printf("double: %lf\n", double1); /* Output: double: 9.327800 */
}