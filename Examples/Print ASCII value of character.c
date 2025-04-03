// Print ASCII value of character

#include <stdio.h>
int main() {
    char chr;
    printf("Enter a character: ");
    scanf("%c", &chr);
    printf("ASCII value of '%c':  %d\n", chr, chr);
    return 0;
}
