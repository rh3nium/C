

#include <stdio.h>
int main()
{
    double a, b, c, d, x, y, z;
    printf("Enter value of a: ");
    scanf("%lf", &a);
    printf("Enter value of b: ");
    scanf("%lf", &b);
    printf("Enter value of c: ");
    scanf("%lf", &c);
    printf("Enter value of d: ");
    scanf("%lf", &d);
    x = a * b -c;
    y = b / c * 5;
    z = a - b / c + d;
    printf("x =%lf", x, "\n");
    printf("y =%lf", y, "\n");
    printf("z =%lf", z);

}