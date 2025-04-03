// Copying elements of structure to another structure

#include<stdio.h>
struct student {
    int age;
    char name[50];
    };
int main() {
    struct student struc1 = {19, "Ritu"};
    struct student struc2;
    // Copy elements of structure 1 to structure 2
    struc2 = struc1;
    printf("Elements of structure struc2:\n");
    printf("Age: %d\nName: %s\n", struc2.age, struc2.name);
    return 0;
}
/* Output:
Age: 19
Name: Ritu
*/
