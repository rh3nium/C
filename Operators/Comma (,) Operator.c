// -- Comma (,) Operator -- //

/*
This operator has two contexts:

1. - Function Argument Context -  
When used to separate function arguments, the **order of evaluation is unspecified**.  
Example: func_with_parameters(ret_print_1(), ret_print_2(), ret_print_3());
The output might be 2, 1, 3, depending on the compiler,  
but it is guaranteed that the correct value is passed to each argument.

2. - Expression Chaining Context -
When used as an expression chain, the comma operator evaluates expressions **from left to right**  
and the value of the **last expression** is returned.  
Example: int a = (ret_print_1(), ret_print_2(), ret_print_3());
Here, it will always print 1, 2, 3, and `a` will store 3,  
because that is the value of the last expression in the chain.
*/

#include <stdio.h> // This is for printf()
int print_return_num(int num) {
    printf("in print_return_num(%d)\n", num);

    return num;
}


void print_before_eval() {
    printf("in print_before_eval()\n");
}

int main()
{
    // This is the expression chaining context and is not well known
    // 30 basically does nothing here and the compiler will warn on this
    int num = (30, print_before_eval(), print_return_num(63)); 
    printf("num: %d\n", num); // this will print 63

    return 0;
}

/* Output:
in print_before_eval()
in print_return_num(63)
num: 63
*/