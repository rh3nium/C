// peek() -  Return front element of queue without removing it

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Define Queue structure
typedef struct {
    int data[MAX];
    int front;
    int rear;
} *Queue;

// isEmpty()
int isEmpty(Queue q) {
    return q->front == -1;
}

// isFull()
int isFull(Queue q) {
    return q->rear == MAX - 1;
}

// enqueue() - Function to add an element to the queue
void enqueue(Queue q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow! Cannot enqueue %d.\n", value);
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = value;
    printf("%d enqueued.\n", value);
}

// peek() - Peek Operation
int peek(Queue q) {
    if (isEmpty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }
    return q->data[q->front];
}

// Function to display the queue elements
void display(Queue q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d ", q->data[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue q = (Queue)malloc(sizeof(struct Queue));
    if (q == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialize the queue
    q->front = -1;
    q->rear = -1;

    // Enqueue some elements
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    
    printf("\n");
    display(q);

    // peek() -  Return front element of queue without removing it
    printf("\nValue at the front of the queue is: %d\n", peek(q));
    
    printf("Queue after peek operation: ");
    display(q); // The queue remains unchanged

    // Clean up memory
    free(q);

    return 0;
}
