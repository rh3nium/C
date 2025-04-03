// Nested loop

#include<stdio.h>
// Main loop
int main(){
    int i = 1;
    // Outer loop
    while(i<=3)
    {
        // Inner loop
        for(int j = 1; j <= 2; j++)
        {
            printf("Outer: %d, Inner: %d\n", i, j);
        }
        i++;
    }
    return 0;
}

/* Output:
Outer: 1, Inner: 1
Outer: 1, Inner: 2
Outer: 2, Inner: 1
Outer: 2, Inner: 2
Outer: 3, Inner: 1
Outer: 3, Inner: 2
*/