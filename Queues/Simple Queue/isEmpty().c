// isEmpty() - Checks if queue is empty

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int data[MAX];
    int front;
    int rear;
} *Queue;

// isEmpty()
int isEmpty(Queue q) {
    // Condition 1: Initial state of an empty queue
    // Condition 2: All elements have been dequeued
    return q->front == -1 || q->front > q->rear;
}

// isFull()
int isFull(Queue q) {
    return q->rear == MAX - 1;
}

// Function to initialize the queue
void initializeQueue(Queue q) {
    if (q != NULL) {
        q->front = -1;
        q->rear = -1;
        printf("Queue initialized.\n");
    }
}

// enqueue() - Function to add an element to the queue
void enqueue(Queue q, int value) {
    if (isFull(q)) {
        printf("Queue is full! Cannot enqueue %d.\n", value);
    } else {
        if (isEmpty(q)) {
            q->front = 0;
        }
        q->rear++;
        q->data[q->rear] = value;
        printf("%d enqueued.\n", value);
    }
}

// dequeue() - Function to remove an element from the queue
int dequeue(Queue q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    } else {
        int value = q->data[q->front];
        q->front++;
        printf("%d dequeued.\n", value);
        
        // Reset pointers if the queue becomes empty
        if (q->front > q->rear) {
            q->front = -1;
            q->rear = -1;
        }
        return value;
    }
}

// Function to display the elements of queue
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
    
    initializeQueue(q);

    // isEmpty() - Check if queue is empty
    printf("\nIs the queue empty? %s\n", isEmpty(q) ? "Yes" : "No");
    
    // Add elements
    enqueue(q, 10);
    enqueue(q, 20);
    display(q);
    
    printf("\nIs the queue empty? %s\n", isEmpty(q) ? "Yes" : "No");
    
    // Dequeue all elements
    dequeue(q);
    dequeue(q);
    
    display(q);

    printf("\nIs the queue empty? %s\n", isEmpty(q) ? "Yes" : "No");

    // Clean up memory
    free(q);
    
    return 0;
}
