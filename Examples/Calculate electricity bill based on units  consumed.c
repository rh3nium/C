// Calculate electricity bill using switch case

#include <stdio.h>
int main() {
    int units;
    float bill;
    int slab;
    printf("Enter number of units consumed: ");
    scanf("%d", &units);
    if (units <= 0) {
        printf("Invalid input. Units consumed must be positive.\n");
        return 1;
    }
    if (units <= 100) {
        slab = 1;
    } else if (units <= 200) {
        slab = 2;
    } else if (units <= 300) {
        slab = 3;
    } else {
        slab = 4;
    }
    switch (slab) {
        case 1: // 0-100 units
            bill = units * 3;
            break;
        case 2: // 101-200 units
            bill = units * 5;
            break;
        case 3: // 201-300 units
            bill = units * 7;
            break;
        case 4: // Above 300 units
            bill = units * 10;
            break;
        default:
            printf("Invalid slab.\n");
            return 1;
    }
    printf("Electricity bill: %.2f\n", bill);
    return 0;
}