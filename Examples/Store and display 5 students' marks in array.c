// Store and display marks of 5 students using array

#include <stdio.h>
int main() {
    int marks[5]; // Array to store marks
    int i;
    for (i = 0; i < 5; i++) {
        do {
            printf("Enter marks of student %d: ", i + 1);
            scanf("%d", &marks[i]);
            if (marks[i] < 0) {
                printf("Please enter a non-negative number.\n");
            }
        } while (marks[i] < 0);
    }
    printf("Marks of students:\n");
    for (i = 0; i < 5; i++) {
        printf("Student %d: %d\n", i + 1, marks[i]);
    }
    return 0;
}