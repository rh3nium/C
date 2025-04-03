// comma (,) Operator
// Separates expressions

#include <stdio.h>
int main()
{
    int num = 30;
    char chr = 'A';
    // Using comma to separate operands
    printf("Address of num: %d \nAddress of chr: %p ", &num, &chr);
}

/* Output:
Address of num: -1316141524
Address of chr: 0x7ff7b18d462b
*/