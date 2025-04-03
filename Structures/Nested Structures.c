// Nested Structures

#include<stdio.h>
struct Date {
    int day, month, year;
};
struct Student {
    int roll;
    struct Date dob; // Nested structure
};
int main() {
    struct Student s1;
    printf("\nEnter student roll no.: ");
    scanf("%d", &s1.roll);
    printf("\nEnter DOB (dd mm yy): ");
    scanf("%02d %02d %02d", &s1.dob.day, &s1.dob.month, &s1.dob.year);
    printf("\nStudent Details:\n");
    printf("Roll no: %d\nDOB: %02d-%02d-%02d\n", s1.roll, s1.dob.day, s1.dob.month, s1.dob.year);
    return 0;
}
