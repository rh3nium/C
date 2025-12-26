// Queue initialization and create function

#include<stdio.h>
#include<stdlib.h>
#define MAX 5

typedef struct MyQueue {
    int data[MAX];
    int front, rear;
} *Queue;

Queue createQueue() {
    Queue q = (Queue)malloc(sizeof(struct MyQueue));
    if (q != NULL) {
        q->front = -1;
        q->rear= -1;
    }
    return q;
}

int main() {
    Queue my_queue = createQueue();
    if (my_queue == NULL) {
        printf("Memeory allocation failed\n");
        return 1;
    }
    free(my_queue);
    my_queue = NULL;
    return 0;
}
