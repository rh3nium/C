// Arrays of strings

#include<stdio.h>
#include<string.h>
int main(){
    printf("Arrays of strings\n\n");
    char cities[3][20] = {"Paris", "Cali", "Goa"};
    printf("City 1: %s\n", cities[0]);
    printf("City 2: %s\n", cities[1]);
    printf("City 3: %s\n", cities[2]);
    return 0;
}

/* Output:
City 1: Paris
City 2: Cali
City 3: Goa
*/