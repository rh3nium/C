// Create structure using typedef keyword

#include <stdio.h>
// Define structure - typedef struct { values }
typedef struct {
    double real;
    double imag;
} complex;
complex addComplex(complex n1, complex n2) {
    complex sum;
    sum.real = n1.real + n2.real;
    sum.imag = n1.imag + n2.imag;
    return sum;
}
int main() {
    complex n1, n2, sum;
    printf("Enter real and imaginary parts of complex number 1: ");
    scanf("%lf %lf", &n1.real, &n1.imag);
    printf("Enter real and imaginary parts of complex number 2: ");
    scanf("%lf %lf", &n2.real, &n2.imag);
    sum = addComplex(n1, n2);
    printf("After function call: Sum = %.2f + %.2fi\n", sum.real, sum.imag);
    return 0;
}
