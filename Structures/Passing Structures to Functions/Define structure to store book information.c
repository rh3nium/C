// Define structure to store book information

#include <stdio.h>
struct Book {
    char title[50];
    char author[50];
    float price;
};
int main() {
    int N;
    printf("Enter the number of books: ");
    scanf("%d", &N);
    struct Book b[N];
    for (int i=0; i<N; i++) {
        printf("\nEnter details for book %d:", i+1);
        printf("\nTitle: ");
        scanf("%s", b[i].title);
        printf("Author: ");
        scanf("%s", b[i].author);
        printf("Price: ");
        scanf("%f", &b[i].price);
    };
    printf("\nBook Details:");
    for (int i=0; i<N; i++) {
        printf("\n%d:\n", i+1);
        printf("Title: %s\nAuthor: %s\nPrice: %.2f\n", b[i].title, b[i].author, b[i].price);
    }
    return 0;
}