// Calculate tax if salary>10000

#include<stdio.h>
int main () {
    int salary, tax;
    printf("Enter salary: \n");
    scanf("%d", &salary);
    if (salary>10000) {
        tax = (0.2)*salary;
        printf("Tax: %d", tax);
    }
    else {printf("No tax applied");}
}