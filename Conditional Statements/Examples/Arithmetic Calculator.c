// Arithmetic Calculator 

#include<stdio.h>
int main(){
    int num1, num2, choice;
    printf("Enter number 1: ");
    scanf("%d", &num1);
    printf("Enter number 2: ");
    scanf("%d", &num2);
    printf("Enter your choice of operation: 1 - Addition, 2 - Subtraction, 3 - Multiplication, 4 - Division ");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
        printf("Result: %d", num1+num2);
        break;
        case 2:
        printf("Result: %d", num1-num2);
        break;
        case 3:
        printf("Result: %d", num1*num2);
        break;
        case 4:
        printf("Result: %d", num1/num2);
        break;
    }

}

/* Output:
Grade A
*/