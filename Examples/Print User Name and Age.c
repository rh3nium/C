// Accept a user's full name and age, and display them in a formatted manner

#include <stdio.h>
int main() {
    char name[100];
    int age;
    printf("Enter your name: \n");
    scanf("%s", &name);
    printf("Enter your age: \n");
    scanf("%d", &age);
    printf("Name:%s \n", name);
    printf("Age:%d ", age);
}