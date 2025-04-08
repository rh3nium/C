// Call by value

#include <stdio.h>
void display(char name[], int roll, char branch[]);
void main() {
    struct student {
        char name[30];
        int roll;
        char branch[25];
    } s;
    printf("Enter name: ");
    scanf("%s", s.name);
    printf("Enter roll: ");
    scanf("%d", &s.roll);
    printf("Enter branch: ");
    scanf("%s", s.branch);
    display(s.name, s.roll, s.branch);
}
void display(char name[], int roll, char branch[]) {
    printf("Name = %s", name);
    printf("\nRoll no. = %d", roll);
    printf("\nBranch = %s\n", branch);
}
