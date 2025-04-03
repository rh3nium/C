#include <stdio.h>
int main(){
    int score;
    char gender[5];
    printf("Enter your score (1-5):");
    scanf("%d", &score);
    switch(score){
        case 1:
            printf("Your score is 1");
            break;
        case 2:
            printf("Your score is 2");
            break;
        case 3:
            printf("Your score is 3");
            break;
        case 4:
            printf("Your score is 4");
            break;
        case 5:
            printf("Your score is 5");
            break;
        default:
        printf("Invalid");
        }
}

/* Output:
Your score is x
*/