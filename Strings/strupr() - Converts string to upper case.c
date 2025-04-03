/* strupr() - Converts string to upper case
- Not part of standard C library (C99, C11, etc.), only available in Turbo C (old compilers) and MSVC (Windows) */

#include<stdio.h>
#include<string.h>
int main(){
    char str1[] = "This is a string";
    printf("%s\n", strupr(str1)); // Output: THIS IS A STRING
    return 0;
}