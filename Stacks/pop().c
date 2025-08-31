// Stack pop() function

#include <stdio.h>
#define MAX 100

typedef struct MyStack {
    int data[MAX];
    int top;
} MyStack, *Stack;

int isEmpty(Stack s) {
    return s->top == -1;
}

// pop()
int pop(Stack s) {
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[(s->top)--];
}

int main() {
    MyStack st;
    st.top = -1; // initialize stack

    // Push some elements manually
    st.data[++(st.top)] = 10;
    st.data[++(st.top)] = 20;
    st.data[++(st.top)] = 30;

    // Pop elements
    printf("Popped: %d\n", pop(&st));
    printf("Popped: %d\n", pop(&st));
    printf("Popped: %d\n", pop(&st));
    printf("Popped: %d\n", pop(&st)); // underflow example

    return 0;
}
