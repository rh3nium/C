// Passing Structures to Functions using Pointer

#include<stdio.h>
struct book {
    int id;
    char title[30];
    float price;
};
int main() {
    struct book b1 = {458, "MyBook", 23.45};
    display(&b1);
    return 0;
}
void display(struct book *b) {
    printf("\nID: %d\nTitle: %s\nPrice: %f\n", b->id, b->title, b->price);
}
/* Output:
ID: 458
Title: MyBook
Price: 23.450001
*/