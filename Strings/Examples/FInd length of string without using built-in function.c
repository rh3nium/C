// Find length of string without using built-in function

#include <stdio.h>
int main() {
    printf("Find length of string without using built-in function\n\n");
    char str[50];
    int len = 0;
    printf("Enter a string: ");
    scanf("%s", str);
    // Count characters in string until null terminator '\0'
    for (int j = 0; str[j] != '\0'; j++) {
        len++;
    }
    printf("Length of string: %d\n", len);
    return 0;
}
