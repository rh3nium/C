// strcpy() - Copies 2nd string to 1st

#include<stdio.h>
#include<string.h>
int main(){
    printf("strcpy() - Copies 2nd string to 1st string\n\n");
    // Copy content to empty string
    char city[20];
    // strcpy() - copy string
    strcpy(city, "Paris");
    // Print copied string
    printf("Copied string: %s\n\n", city); // Output: Paris

    // Accept 2 strings from user and copy 2nd string to 1st
    char str1[30], str2[30];
    printf("Enter string 1: \n");
    scanf("%s", str1);
    printf("Enter string 2: \n");
    scanf("%s", str2);
    printf("Copied string: %s\n", strcpy(str1, str2));
    return 0;
}