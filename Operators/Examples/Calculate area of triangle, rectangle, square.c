// Calculate area of triangle, rectangle, square

#include <stdio.h>
#include <math.h>
int main()
{
    float b, h, l, w, s, tri, rect, sq;
    
    printf("Calculating area of triangle\n");
    printf("Enter base length: \n");
    scanf("%f", &b);
    printf("Enter height: \n");
    scanf("%f", &h);
    tri = 0.5 * b * h;
    printf("Area = %f\n\n", tri);
  
    printf("Calculating area of rectangle\n");
    printf("Enter length: \n");
    scanf("%f", &l);
    printf("Enter width: \n");
    scanf("%f", &w);
    rect = l * w;
    printf("Area = %f\n\n", rect);
    
    printf("Calculating area of square\n");
    printf("Enter side length: \n");
    scanf("%f", &s);
    sq = s * s;
    printf("Area = %f\n\n", sq);
    
    return 0;
}