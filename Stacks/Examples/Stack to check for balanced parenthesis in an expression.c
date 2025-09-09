// Structure-based implementation of stack to check for balanced parentheses in an expression

#include <stdio.h>
#include <string.h>

#define MAX 100

struct Stack {
    int top;
    char arr[MAX];
};

void push(struct Stack *s, char ch) {
    s->arr[++(s->top)] = ch;
}

char pop(struct Stack *s) {
    return s->arr[(s->top)--];
}

int isBalanced(char expr[]) {
    struct Stack s;
    s.top = -1;

    for (int i = 0; expr[i]; i++) {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            push(&s, ch);
        } 
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.top == -1) return 0;   // empty stack
            char open = pop(&s);
            if ((open == '(' && ch != ')') ||
                (open == '{' && ch != '}') ||
                (open == '[' && ch != ']'))
                return 0;  // mismatch
        }
    }

    return s.top == -1; // if empty → balanced
}

int main() {
    char expr[MAX];
    printf("Enter expression: ");
    fgets(expr, MAX, stdin);

    expr[strcspn(expr, "\n")] = '\0'; // remove newline

    if (isBalanced(expr))
        printf("Balanced\n");
    else
        printf("Not balanced\n");

    return 0;
}
