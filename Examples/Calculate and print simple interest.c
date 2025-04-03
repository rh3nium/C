// Calculate and print simple interest

#include<stdio.h>
int main (){
    double p, t, r, si;
    printf("Enter principal amount: \n");
    scanf("%lf", &p);
    printf("Enter time period in years: \n");
    scanf("%lf", &t);
    printf("Enter rate of interest: \n");
    scanf("%lf", &r);
    si = (p*t*r)/100;
    printf("Simple interest = %lf", si);
    
}