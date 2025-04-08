// Define structure to store person information

#include <stdio.h>
struct Person {
    char name[50];
    int age;
    float height;
};
int main() {
    struct Person p[3] =
    {
        {"Alice", 25, 5.6},
        {"Bob", 30, 5.9},
        {"Charlie", 22, 5.8}
    };
    printf("Person Details:\n");
    for (int i=0; i<3; i++) {
        printf("\nPerson %d:\n", i);
        printf("Name: %s, Age: %d, Height: %.lf feet\n", p[i].name, p[i].age, p[i].height);
    }
    return 0;
}