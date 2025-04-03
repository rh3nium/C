// Menu with options for operations

#include<stdio.h>
int main(){
    int choice;
    printf("Menu: \n");
    printf("1: Case 1 \n");
    printf("2. Case 2 \n");
    printf("3. Case 3 \n");
    printf("Enter your choice number: ");
    scanf("%d" , &choice);
    if ((choice==1) | (choice==2) | (choice==3)) {
        switch (choice) {
            case 1:
            printf("Welcome to case 1 \n");
            break;
            case 2:
            printf("Welcome to case 2 \n");
            break;
            case 3:
            printf("Welcome to case 3 \n");
            break;
        }}
    // Handle invalid input
    else {
        printf("Invalid input \n");
    }
}