// Simple Macro Substitution Directive

#include<stdio.h>
// Define macro
#define PI 3.14159
int main() {
    printf("Value of PI = %f\n", PI); /* Output: Value of PI = 3.14159 */
    int result = PI * 3 * 3;
    printf("Area of circle = %d\n", result); /* Output: Area of circle = 28 */
    return 0;
}