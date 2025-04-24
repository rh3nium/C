// Check student grade using if-else if-else

#include<stdio.h>
int main(){
    int result = 95;
    if(result>=90){
        printf("Grade A");
    }
    else if(result>=80){
        printf("Grade B");
    }
    else if(result>=70){
        printf("Grade C");
    }
    else if(result>=50){
        printf("Grade D");
    }
    else{
        printf("Fail");
    }
}

/* Output:
Grade A
*/