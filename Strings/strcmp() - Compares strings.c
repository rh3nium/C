// strcmp() - Compares strings

#include<stdio.h>
#include<string.h>
int main(){
    char str1[30], str2[30];
    printf("Enter string 1: \n");
    scanf("%s", str1);
    printf("Enter string 2: \n");
    scanf("%s", str2);
    if (strcmp(str1, str2) == 0) {
        printf ("Strings are equal");
    }
    else {
        printf ("Strings are unequal");
    }
    return 0;
}