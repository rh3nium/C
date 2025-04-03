// Calculate income tax from monthly salary

#include<stdio.h>
int main () {
    int salary, tax;
    printf("Calculate income tax from monthly salary\n");
    printf("Enter monthly salary: \n");
    scanf("%d", &salary);
    if (salary>=10000) {
        tax = (0.4)*salary;
        printf("Income tax: %d", tax);
    }
    else if (salary>=7500 & salary<=9999) {
        tax = (0.3)*salary;
        printf("Income tax: %d", tax);
    }
    else if (salary <= 7499) {
        tax = (0.2)*salary;
        printf("Income tax: %d", tax);
    }
}