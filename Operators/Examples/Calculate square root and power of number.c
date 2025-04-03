// Calculate square root and power of number

#include <stdio.h>
#include <math.h>
int main()
{
    float num, squareRoot, power;
    printf("Enter a number: ");
    scanf("%f", &num);

    squareRoot = sqrt(num);
    printf("Square root of %f = %f\n", num, squareRoot);

    power = pow(num, 3);
    printf("%f\n", power);

    return 0;
}