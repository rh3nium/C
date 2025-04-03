// strlen() - Returns length of string

#include<stdio.h>
#include<string.h>
int main(){
    printf("strlen() - Returns length of string\n\n");
    char str1[] = "This is a string";
    int len = strlen(str1);
    printf("%d\n", len); /* Output: 16 */
    return 0;
}
