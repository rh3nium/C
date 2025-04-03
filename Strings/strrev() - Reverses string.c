/* strrev() - Reverses string
- Not part of standard C library (C99, C11, etc.), only available in Turbo C (old compilers) and MSVC (Windows) */

#include<stdio.h>
#include<string.h>
int main() {
    char str1[20];
    printf("Enter a string: \n");
    scanf("%s", str1);
    strrev(str1);
    printf("Reversed string: %s\n", str1);
    return 0;
}