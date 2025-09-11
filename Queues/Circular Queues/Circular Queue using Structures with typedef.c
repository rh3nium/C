// Circular Queue using Structures with typedef

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct CQueue {
    int data[MAX];
    int front;
    int rear;
} *CQueue;

int isFull(CQueue queue) {
    if ((queue->front == 0 && queue->rear == MAX - 1) || (queue->front == queue->rear + 1)) {
        return 1;
    }
    return 0;
}

int isEmpty(CQueue queue) {
    if (queue->front == -1) {
        return 1;
    }
    return 0;
}

void enqueue(CQueue queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full, cannot enqueue!\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX;
        queue->data[queue->rear] = item;
        printf("Enqueued: %d\n", item);
    }
}

int dequeue(CQueue queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot dequeue!\n");
        return -1;
    } else {
        item = queue->data[queue->front];
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX;
        }
        printf("Dequeued: %d\n", item);
        return item;
    }
}

void display(CQueue queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Elements in the queue are: ");
        for (i = queue->front; i != queue->rear; i = (i + 1) % MAX) {
            printf("%d ", queue->data[i]);
        }
        printf("%d\n", queue->data[i]);
    }
}

int main() {
    CQueue myQueue = (CQueue)malloc(sizeof(struct CQueue));
    if (myQueue == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
    myQueue->front = -1;
    myQueue->rear = -1;

    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    display(myQueue);

    dequeue(myQueue);
    display(myQueue);

    enqueue(myQueue, 40);
    enqueue(myQueue, 50);
    enqueue(myQueue, 60);
    display(myQueue);

    free(myQueue);
    return 0;
}
