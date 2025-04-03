// Passing direct values in function call

// Header files
#include<stdio.h>

// Function header and body
int add (int a, int b) {
    int sum;
    sum = a + b;
    return sum;
}

// Main function
int main() {
    int sum = add(13, 20); // Function call (directly passing values)
    printf("Sum = %d\n", sum); /* Output: Sum = 33 */
    return 0;
}
