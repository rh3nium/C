#include <stdio.h>
#define MAX 100

typedef struct MyStack {
    int data[MAX];
    int top;
} MyStack, *Stack;

int isFull(Stack s) {
    return s->top == MAX - 1;
}

int isEmpty(Stack s) {
    return s->top == -1;
}

int main() {
    MyStack st;
    st.top = -1;   // set manually for testing

    printf("isEmpty: %d\n", isEmpty(&st));
    printf("isFull: %d\n", isFull(&st));

    return 0;
}
