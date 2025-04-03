// Input and Output Functions

#include <stdio.h>
int main() {
    char name[10];
    int age;
    // printf - Gets user input
    printf("Enter your name\n");
    // scanf - Reads user input
    scanf("%s", &name);
    printf("Enter your age\n");
    scanf("%d", &age);
    printf("Name:%s\n", name);
    printf("Age:%d", age);
    return 0;
}
