// Print elements of stack using function

#include <stdio.h>
#define MAX 100

typedef struct MyStack {
    int data[MAX];
    int top;
} MyStack, *Stack;

int isEmpty(Stack s) {
    return s->top == -1;
}

// display() function
void display(Stack s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = s->top; i >= 0; i--)
        printf("%d\n", s->data[i]);
}

int main() {
    MyStack st;
    st.top = -1; // initialize stack

    // Push some elements manually
    st.data[++(st.top)] = 10;
    st.data[++(st.top)] = 20;
    st.data[++(st.top)] = 30;

    // Display stack
    display(&st);

    // Empty the stack and display to see empty message
    st.top = -1;
    display(&st);

    return 0;
}
