// Nested Functions

#include<stdio.h>
int main() {
    outerFunction();
    return 0;
}
void outerFunction() {
    printf("Hello\n");
    helperFunction(); // Call helper function
}
void helperFunction() {
    printf("Helper function\n");
}
