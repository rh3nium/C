// Reverse string using stack implemented with arrays and structures

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

// Define stack structure
struct Stack {
    int top;
    char arr[MAX];
};

// Initialize stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Check if stack is full
int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

// Check if stack is empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Push operation
void push(struct Stack *s, char ch) {
    if (isFull(s)) {
        printf("Stack Overflow!\n");
        return;
    }
    s->arr[++(s->top)] = ch;
}

// Pop operation
char pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    return s->arr[(s->top)--];
}

// Function to reverse a string using stack
void reverseString(char str[]) {
    int n = strlen(str);
    struct Stack s;
    initStack(&s);

    // Push all characters of string to stack
    for (int i = 0; i < n; i++) {
        push(&s, str[i]);
    }

    // Pop all characters back into string (reversed)
    for (int i = 0; i < n; i++) {
        str[i] = pop(&s);
    }
}

int main() {
    char str[MAX];

    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0';

    reverseString(str);

    printf("Reversed string: %s\n", str);

    return 0;
}
