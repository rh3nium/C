// Stack push() function

#include <stdio.h>
#define MAX 100

typedef struct MyStack {
    int data[MAX];
    int top;
} MyStack, *Stack;


int isFull(Stack s) {
    return s->top == MAX - 1;
}

// push() function
void push(Stack s, int value) {
    // Using isFull
    if (isFull(s)) {
        printf("Stack Overflow (checked via isFull)\n");
        return;
    }
  
    // Direct check as well (optional)
    if (s->top == MAX - 1) {
        printf("Stack Overflow (checked directly)\n");
        return;
    }

    s->data[++(s->top)] = value;
}

int main() {
    MyStack st;
    st.top = -1; // initialize stack

    push(&st, 10);
    push(&st, 20);
    push(&st, 30);

    printf("Top element: %d\n", st.data[st.top]);

    return 0;
}
