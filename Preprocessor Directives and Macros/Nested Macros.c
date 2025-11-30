// -- Nested Macro -- //

#include <stdio.h>
#define PI 3.14159
#define SQUARE(x) ((x) * (x))
// Nested macro
#define CYLINDER_VOLUME(radius, height) (PI * SQUARE(radius) * (height))
int main() {
    float radius, height, volume;
    printf("Enter radius of the cylinder: ");
    scanf("%f", &radius);
    printf("Enter height of the cylinder: ");
    scanf("%f", &height);
    volume = CYLINDER_VOLUME(radius, height);
    printf("The volume of the cylinder with radius %.2f and height %.2f is: %.2f\n", radius, height, volume);
    return 0;
}
