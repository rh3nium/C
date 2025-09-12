// Infix to Postfix conversion

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Define stack structure
typedef struct {
    char items[MAX_SIZE];
    int top;
} Stack;

// Function to intialize the stack
void initStack(Stack* s) {
    s->top = -1;
}

// isEmpty()
int isEmpty(Stack* s) {
    return s->top == -1;
}

// push()
void push(Stack* s, char item) {
    if (s->top >= MAX_SIZE -1) {
        printf("Stack overflow\n");
        return;
    }
    s->items[++s->top] = item;
}

// pop()
char pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow\n");
        return '\0';
    }
    return s->items[s->top--];
}

// peek()
char peek(Stack* s) {
    if (isEmpty(s)) {
        return '\0';
    }
    return s->items[s->top];
}

// Function to get precedence of an operator
int getPrec(char op) {
    switch(op) {
        case '+':
        case '-':
        return 1;
        case '*':
        case '/':
        return 2;
        case '^':
        return 3;
        default:
        return 0;
    }
}

// Function to check if character is an operand
int isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

// Function for Infix to Postfix conversion
void inToPost(char* infix, char* postfix) {
    Stack opStack;
    initStack(&opStack);
    int i, j;
    i = 0;
    j = 0;
    
    while (infix[i] != '\0') {
        char ch = infix[i];
        
        if (isOperand(ch)) {
            postfix[j++] = ch;
        }
        
        else if (ch == '(') {
            push(&opStack, ch);
        }
        
        else if (ch == ')') {
            while (!isEmpty(&opStack) && peek(&opStack) != '(') {
                postfix[j++] = pop(&opStack);
            }
            if (!isEmpty(&opStack) && peek(&opStack) == '(') {
                pop(&opStack);
            }
        }
        else {
            while (!isEmpty(&opStack) && peek(&opStack) != '(' && getPrec(peek(&opStack)) >= getPrec(ch)) {
                postfix[j++] = pop(&opStack);
            }
            push(&opStack, ch);
        }
        i++;
    }
    // Pop any remaining operators from stack
    while (!isEmpty(&opStack)) {
        postfix[j++] = pop(&opStack);
    }
    postfix[j] = '\0'; // Null-terminate the postfix string
}

int main() {
    char infix1[MAX_SIZE] = "a+b*(c-d)/e";
    char postfix1[MAX_SIZE];
    printf("Infix expression 1: %s\n", infix1);
    inToPost(infix1, postfix1);
    printf("Postfix expression: %s\n", postfix1); // Output: abcd-*e/+

    char infix2[MAX_SIZE] = "(p+q)*(r-s)";
    char postfix2[MAX_SIZE];
    printf("Infix expression 2: %s\n", infix2);
    inToPost(infix2, postfix2);
    printf("Postfix expression: %s\n", postfix2); // Output: pq+rs-*
    
    return 0;
}

