// Passing entire structure to function

#include <stdio.h>
struct student {
    char name[30];
    int age, roll;
};
void display(struct student s, const char* var_name); // Defining variable for the structure name
int main() {
    printf("Passing entire structure to function\n");
    struct student s1 = {"Riya", 30, 21};
    struct student s2 = {"Ritu", 29, 22};
    display(s1, "Student 1");
    display(s2, "Student 2");
    return 0;
}
void display(struct student s, const char* var_name) {
    printf("\n-- %s --", var_name);
    printf("\nName = %s", s.name);
    printf("\nRoll no. = %d", s.roll);
    printf("\nAge = %d\n", s.age);
}
