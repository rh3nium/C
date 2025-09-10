// Simulate browser backtracking using a single stack of URLs using arrays

#include <stdio.h>
# include<string.h>

#define MAX_STACK_SIZE 10
#define MAX_URL_LEN 50

char urlStack[MAX_STACK_SIZE][MAX_URL_LEN];
int top = -1;

void push(const char* url) {
    if (top >= MAX_STACK_SIZE -1) {
        printf("Stack overflow\n");
        return;
    }
    top++;
    strcpy(urlStack[top], url);
    printf("Visited: %s\n", url);
}

void pop() {
    if(top < 0) {
        printf("Stack underflow, no pages to navugate back to.\n");
        return;
    }
    printf("Going back from: %s\n", urlStack[top]);
    top--;
    if (top >= 0) {
        printf("Currently at: %s\n", urlStack[top]);
    } else {
        printf("Browser history empty.\n");
    }
}

int main() {
    push("www.google.com");
    push("www.sheets.google.com");
    push("www.forms.google.com");
    
    pop();
    pop();
    pop();
    pop();
    
    return 0;
}
