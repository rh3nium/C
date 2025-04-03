// Display day of the week using if-else if

#include <stdio.h>
int main(){
    int day;
    printf("What day is it today (1-7)? ");
    scanf("%d", &day);
    if(day==1){
        printf("Today is Monday");
        }
    if(day==2){
        printf("Today is Tuesday");
        }
    if(day==3){
        printf("Today is Wednesday");
        }
    else if(day==4){
        printf("Today is Thursday");
        }
    else if(day==5){
        printf("Today is Friday");
        }
    else if(day==6){
        printf("Today is Saturday");
        }
    else if(day==7){
        printf("Today is Sunday");
        }
    else {
        printf("Invalid input");
    }
}