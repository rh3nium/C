// Functions in C

// Header files
#include<stdio.h>
// Function declaration/prototype
int add(int a, int b);
// Main function
int main() {
    int x = 11, y = 40;
    int result = add(x, y); // Function call (with actual arguments)
    printf("%d\n", result); /* Output: 51 */
    return 0;
}
// Function definition (with formal arguments - destroyed when function ends)
int add (int a, int b) {
    return a + b;
}