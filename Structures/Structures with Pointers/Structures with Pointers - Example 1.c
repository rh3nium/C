// Structures with Pointers

#include<stdio.h>
struct Student {
    int id;
    char name[30];
    float marks;
};
int main() {
    struct Student s1 = {12, "Ritu", 97};
    struct Student *ptr; // Declare pointer to structure
    ptr = &s1;
    // Accessing structure elements using pointer
    printf("ID: %d\n", ptr->id); /* Output: ID: 12 */
    printf("Name: %s\n", ptr->name); /* Output: Name: Ritu */
    printf("Marks: %f\n", ptr->marks); /* Output: Marks: 97 */
    // Modifying variable value using pointer
    ptr->marks = 99.98;
    printf("\nModified marks: %f\n", ptr->marks); /* Output: Modified marks: 99.98 */
    return 0;
}