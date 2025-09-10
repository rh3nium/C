// enqueue() - Adds element to rear of queue

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

// enqueue()
void enqueue(Queue q, int value) {
    if (isFull(q)) {
        printf("Queue Overflow!\n");
        return;
    }
    
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = value;
}

// Function to display queue elements
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
    
    printf("Enqueuing elements:\n");
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);

    display(q);
    
    // Attempt to enqueue another element to show overflow
    printf("\nAttempting to enqueue another element...\n");
    enqueue(q, 60);

    // Free the allocated memory
    free(q);
    
    return 0;
}
