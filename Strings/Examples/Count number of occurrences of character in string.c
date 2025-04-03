// Count number of occurrences of character in string

#include <stdio.h>
#include <string.h>
int main() {
    printf("Count number of occurrences of character in string\n\n");
    char str[50], ch;
    int count = 0;
    printf("Enter a string: \n");
    scanf("%s", str);
    getchar(); 
    printf("Enter a character to count: \n");
    scanf("%c", &ch);
    // Count occurrences of ch in 'str'
    for (int j = 0; str[j] != '\0'; j++) {
        if (str[j] == ch) {
            count++;
        }
    }
    printf("Number of times character '%c' occurs in the string: %d\n", ch, count);
    return 0;
}
