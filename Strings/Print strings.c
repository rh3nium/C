// Print strings

#include<stdio.h>
int main(){
    printf("Print Strings\n\n");
    // Define char arrays for strings with character limit
    char word1[40], word2[40];
    printf("Enter word 1: \n");
    scanf("%s", word1);
    printf("Enter word 2: \n");
    scanf("%s", word2);
    printf("\n");
    // Print strings
    printf("word1 = %s\nword2 = %s\n", word1, word2);
}