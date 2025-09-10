// Stack Representation Using Structures with typedef

#include <stdio.h>

// Define structure with typedef
typedef struct {
    int data[100];
    int top;
} Stack;

int main() {
    Stack s;
    s.top = -1;

    printf("Stack initialized. Top = %d\n", s.top);

    return 0;
}
