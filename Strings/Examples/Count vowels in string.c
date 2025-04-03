// Count vowels in string

#include <stdio.h>
#include <string.h>
int main() {
    printf("Count vowels in string\n\n");
    char str[50];
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    int count = 0;
    printf("Enter a string: ");
    scanf("%s", str);
    int len = strlen(str);
    // Count vowels in 'str'
    for (int j = 0; j <= len; j++) {
        for (int i = 0; i <= 4; i++)
        if (str[j] == vowels[i]) {
            count++;
        }
    }
    printf("Number of vowels in string: %d\n", count);
    return 0;
}
