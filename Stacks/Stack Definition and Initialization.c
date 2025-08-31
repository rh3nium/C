// Stack definition and initialization

#include <stdio.h>
#define MAX 100

typedef struct MyStack { // Define stack
    int data[MAX];
    int top;
} MyStack, *Stack;   // struct type and pointer type

void initStack(Stack s) {
    s->top = -1;
}

int main() {
    MyStack st;       // create stack variable
    initStack(&st);   // pass its address
    printf("Top after init: %d\n", st.top);
    return 0;
}
