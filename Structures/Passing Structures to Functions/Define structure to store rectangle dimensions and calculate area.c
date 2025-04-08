// Define structure to store rectangle dimensions and calculate area

#include <stdio.h>
struct Rect {
    float length;
    float breadth;
    float area;
};
int main() {
    float calcArea(struct Rect r) {
        return r.length * r.breadth;
    }
    struct Rect r;
    printf("Enter length of rectangle: ");
    scanf("%f", &r.length);
    printf("Enter breadth of rectangle: ");
    scanf("%f", &r.breadth);
    printf("Area of rectangle = %.2f\n", calcArea(r));
    return 0;
}
