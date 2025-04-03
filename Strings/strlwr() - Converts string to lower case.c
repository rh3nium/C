/* strlwr() - Converts string to lower case
- Not part of standard C library (C99, C11, etc.), only available in Turbo C (old compilers) and MSVC (Windows) */

#include<stdio.h>
#include<string.h>
int main(){
    char str1[] = "THIS IS A STRing";
    printf("%s\n", strlwr(str1)); // Output: this is a string
    return 0;
}