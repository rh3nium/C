// Check if string is palindrome

#include <stdio.h>
#include <string.h>
int main() {
    printf("Check if string is palindrome\n\n");
    char str1[50], strrev1[50];
    printf("Enter a string: \n");
    scanf("%s", str1);
    strrev1 = strrev(str1);
    // Check if str1 is palindrome
    if (str1 == strrev1) {
        printf("%s is a palindrome\n", str1);
    }
    else {
        printf("%s is not a palindrome\n", str1);
    }
    return 0;
}
