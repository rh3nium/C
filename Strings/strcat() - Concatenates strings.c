// strcat() - Concatenates strings

#include<stdio.h>
#include<string.h>
int main(){
    printf("strcat() - Concatenates strings\n\n");
    char word1[40], word2[40];
    printf("Enter string 1: \n");
    scanf("%s", word1);
    printf("Enter string 2: \n");
    scanf("%s", word2);
    printf("\n");
    // strcat() - concatenate strings
    printf("%s\n", strcat(word1, word2));
}