// Postfix Expression Evaluation

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

// Define stack structure
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// isEmpty()
int isEmpty(Stack* s) {
    return s->top == -1;
}

// push()
void push(Stack* s, int item) {
    if (s->top >= MAX_SIZE -1) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++s->top] = item;
}

// pop()
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return -1;
    }
    return s->items[s->top--];
}

// Function to perform arithmetic operation
int oper(int op1, int op2, char op) {
    switch(op) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        default: return 0;
    }
}

// Function to evaluate postfix expression
int evalPost(char* exp) {
    Stack s;
    initStack(&s);
    int i;
    
    for (i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
        
        // If operand, convert to int and push
        if (isdigit(ch)) {
            push(&s, ch - '0');
        }
        
        // If operator, pop 2 operands, operate, and push result
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int op2 = pop(&s);
            int op1 = pop(&s);
            int result = oper(op1, op2, ch);
            push(&s, result);
        }
    }
    // Result: 1 item left in stack
    return pop(&s);
}

int main() {
    // Expression 1: 23*5+
    char exp1[] = "23*5+";
    int result1 = evalPost(exp1);
    printf("Postfix expression 1: %s\n", exp1);
    printf("Result: %d\n\n", result1); // Output: 11
    
    // Expression 2: 12+34-*
    char exp2[] = "12+34-*";
    int result2 = evalPost(exp2);
    printf("Postfix expression 2: %s\n", exp2);
    printf("Result: %d\n\n", result2); // Output: -3
    
    return 0;
}
