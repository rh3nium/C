// Passing Structures to Functions using Pointers - Example

#include<stdio.h>
struct Car {
    int id;
    char brand[30];
    float price;
};
int main() {
    struct Car c = {42, "SomeBrand", 20999.49};
    display(&c);
    return 0;
}
void display(struct Car *c) {
    printf("Car Details:\n");
    printf("\nID: %d\nBrand: %s\nPrice: %f\n", c->id, c->brand, c->price);
}
/* Output:
Car Details:
ID: 42
Brand: SomeBrand
Price: 20999.490234
*/