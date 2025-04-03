// addressof() Operator
// Finds memory address of a variable

#include <stdio.h>
int main()
{
    printf("addressof() Operator\n\n");
    int num = 30;
    char chr = 'A';
    printf("Address of num: %d \n", &num);
    printf("Address of chr: %p \n", &chr);
}