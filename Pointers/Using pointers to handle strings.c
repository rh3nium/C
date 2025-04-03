// Using pointers to handle strings

#include <stdio.h>
#include <string.h>
int main() {
    char str[] = "This is a string!";
    char *ptr;

    // Assigning address of string to pointer
    ptr = str;

    // Printing entire string using pointer
    printf("Value of string using pointer: %s\n", ptr); // Output: This is a string

    // Accessing characters in string using pointer
    printf("1st character: %c\n", *ptr);
    printf("6th character: %c\n", *(ptr + 5));

    // Modifying string using pointer
    ptr[0] = 'J'; // Change 'T' to 'J'
    printf("Modified string: %s\n", str); /* Output: Jhis is a string! */

    // Finding length of string using pointers
    ptr = str;
    int length = 0;
    while (*ptr != '\0') {
        length++;
        ptr++;
    }
    printf("Length of string: %d\n", length); /* Output: 17 */

    // Copying string to another string using pointers
    // Initialize new string for value to be copied to
    char str2[20];
    char *source = str;
    char *dest = str2;
    // strcopy(dest, source)
    strcpy(dest, source);
    printf("Copied string: %s\n", str2); /* Output: Jhis is a string! */

    return 0;
}