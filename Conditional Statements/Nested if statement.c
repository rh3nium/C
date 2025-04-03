// Nested if statement

#include<stdio.h>
int main(){
    int age = 21;
    char gender = 'f';
    if(age>=18){
        if(gender=='f'){
            printf("You are an adult woman");
        }
        else{
            printf("You are an adult");
        }
        }
    else{
        printf("You are younger than 18");
    }
}

/* Output:
You are an adult woman
*/