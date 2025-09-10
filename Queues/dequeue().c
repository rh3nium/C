// dequeue() - Removes element at front of queue

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

// dequeue() - Function to remove element at front of queue
int dequeue(Queue q) {
    if (isEmpty(q)) {
        printf("Queue Underflow!\n");
        return -1;
    }
    int val = q->data[q->front];
    q->front++;
    
    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
    return val;
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
    Queue q = (Queue)malloc(sizeof(*q));
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
    
    // dequeue() - Dequeue elements
    printf("\nDequeuing elements:\n");
    printf("Dequeued value: %d\n", dequeue(q));
    printf("Dequeued value: %d\n", dequeue(q));
    
    printf("\n");
    display(q);
    
    // Dequeue the last element and show pointers reset
    printf("\nDequeuing last element:\n");
    printf("Dequeued value: %d\n", dequeue(q));
    
    printf("\n");
    display(q);
    
    // Attempt to dequeue from an empty queue
    printf("\nAttempting to dequeue from an empty queue:\n");
    printf("Dequeued value: %d\n", dequeue(q));
    
    // Clean up memory
    free(q);
    
    return 0;
}
