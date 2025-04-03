// Print star pattern using 2D Array

#include <stdio.h>
int main() {
    printf("Print pattern using 2D Array\n\n");
    printarr();
    return 0;
}
int printarr() {
    char array1[5] = {'*', '*', '*', '*', '*'};
    for (int k = 0; k < 5; k++) {
        for (int i = 0; i < 5; i++) {
            printf("%c ", array1[i]);
        }
        printf("\n");
    }
}
/* Output:
* * * * *
* * * * *
* * * * *
* * * * *
* * * * *
*/