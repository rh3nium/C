// Structures
  // Structure - Collection of variables of various data types

#include<stdio.h>
int main() {
    // Define structure - struct struct_name {variables}
    struct student //structure tag
    {
        int no, age;
            char branch[50];
            long mobno;
    } s1, s2;
    printf("Enter roll no.: ");
    scanf("%d", &s1.no);
    printf("Enter age: ");
    scanf("%d", &s1.age);
    printf("Enter branch: ");
    scanf("%s", &s1.branch);
    printf("Enter mobile number: ");
    scanf("%ld", &s1.mobno);
    printf("\nStudent Details:\n");
    printf("Roll No.: %d\nAge: %d\nBranch: %s\nPhone: %ld\n", s1.no, s1.age, s1.branch, s1.mobno);
    return 0;
}
