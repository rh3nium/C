// Arrays of Structures

#include<stdio.h>
struct Book {
    int id;
    char title[30];
    float price;
};
int main() {
    struct Book b[2];
    printf("Arrays of Structures\n");
    for (int i=0; i<2; i++) {
        printf("Enter id, title, and price of book %d:\n", i+1);
        scanf("%d %s %f", &b[i].id, &b[i].title, &b[i].price);
    }
    for (int i=0; i<2; i++) {
        printf("\nBook %d Details:\n", i+1);
        printf("ID: %d\nTitle: %s\nPrice: %f\n", b[i].id, b[i].title, b[i].price);
    }
    return 0;
}
