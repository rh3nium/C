// Print pattern -

#include<stdio.h>
int main(){
    int min = 0;
    for (int i = 5; i >= min; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}

/* Output:

* * * * *
* * * *
* * *
* *
*

*/