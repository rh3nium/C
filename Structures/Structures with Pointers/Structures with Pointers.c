// Structures with Pointers

#include<stdio.h>
struct Book {
    int id;
    char title[30];
    int price;
};
int main() {
    struct Book b1 = {12, "SomeBook", 8};
    struct Book *ptr = &b1; // Declare pointer to structure
    
    // Accessing structure elements using pointer
    printf("Structures with Pointers\n\n");
    printf("ID: %d\n", ptr->id); /* Output: ID: 12 */
    printf("Title: %s\n", ptr->title); /* Output: Title: SomeBook */
    printf("Price: %d\n", ptr->price); /* Output: Price: 8 */

    // Modifying variable value using pointer
    ptr->id = 9;
    printf("\nModified Value of ID: %d\n", ptr->id); /* Output: Modified Value of ID: 9 */
    return 0;
}