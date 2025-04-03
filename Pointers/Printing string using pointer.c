// Using pointers to handle strings

#include <stdio.h>
#include <string.h>
int main() {
    char str[] = "Hello";
    char *ptr;
    ptr = str;
    // Printing entire string using pointer
    printf("String: %s\n", ptr); /* Output: Hello  */
}