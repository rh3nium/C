// Print even numbers from 1-20

#include<stdio.h>
int main(){
    for (int i = 1; i <= 20; i++) {
        if (i % 2 == 0) {
            printf("%d \n", i);
        }
    }
    return 0;
}

/* Output:
2
4
6
8
10
12
14
16
18
20
*/