// Stack peek() function

#include <stdio.h>
#define MAX 100

typedef struct MyStack {
    int data[MAX];
    int top;
} MyStack, *Stack;

int isEmpty(Stack s) {
    return s->top == -1;
}

// peek() function
int peek(Stack s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1;
    }
    return s->data[s->top];
}

int main() {
    MyStack st;
    st.top = -1; // initialize stack

    // Push some elements manually
    st.data[++(st.top)] = 10;
    st.data[++(st.top)] = 20;
    st.data[++(st.top)] = 30;

    // Peek top element
    printf("Top element: %d\n", peek(&st));

    // Empty the stack and peek to see underflow
    st.top = -1;
    printf("Top element: %d\n", peek(&st));

    return 0;
}
