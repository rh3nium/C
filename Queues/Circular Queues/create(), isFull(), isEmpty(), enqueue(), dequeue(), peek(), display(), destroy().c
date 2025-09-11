#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the struct for the circular queue
typedef struct {
    int* data;
    int size;
    int front;
    int rear;
} CQueue_t;

// Define the CQueue type as a pointer to the struct
typedef CQueue_t* CQueue;

// Function to create and initialize a circular queue
void createCQ(CQueue q, int size) {
    q->size = size;
    q->front = -1;
    q->rear = -1;
    q->data = (int*)malloc(size * sizeof(int));
    if (q->data == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    for (int i = 0; i < size; i++) {
        q->data[i] = 0;
    }
}

// Function to check if the queue is full
bool isFull(CQueue q) {
    return ((q->rear + 1) % q->size == q->front);
}

// Function to check if the queue is empty
bool isEmpty(CQueue q) {
    return (q->front == -1);
}

// Function to add an element to the circular queue (enqueue)
void enqueue(CQueue q, int value) {
    if (isFull(q)) {
        printf("Queue is Full!\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % q->size;
    }
    q->data[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the circular queue (dequeue)
int dequeue(CQueue q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return -1;
    }
    int val = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }
    printf("Dequeued: %d\n", val);
    return val;
}

// Function to get the front element without removing it (peek)
int peek(CQueue q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return -1;
    }
    return q->data[q->front];
}

// Function to display the elements of the circular queue
void display(CQueue q) {
    if (isEmpty(q)) {
        printf("Queue is Empty!\n");
        return;
    }
    int i = q->front;
    printf("Queue: ");
    while (1) {
        printf("%d ", q->data[i]);
        if (i == q->rear)
            break;
        i = (i + 1) % q->size;
    }
    printf("\n");
}

// Function to destroy the queue and free memory
void destroy(CQueue q) {
    if (q != NULL) {
        if (q->data != NULL) {
            free(q->data);
            q->data = NULL;
        }
        q->front = -1;
        q->rear = -1;
        q->size = 0;
        printf("Queue destroyed and memory freed.\n");
    }
}

// Main function to demonstrate the operations
int main() {
    int queueSize = 5;
    // Correct memory allocation: allocate for the struct itself
    CQueue myQueue = (CQueue)malloc(sizeof(CQueue_t)); 
    if (myQueue == NULL) {
        printf("Memory allocation for queue failed!\n");
        return 1;
    }

    createCQ(myQueue, queueSize);

    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    display(myQueue);

    printf("Front element is: %d\n", peek(myQueue));
    dequeue(myQueue);
    display(myQueue);

    enqueue(myQueue, 40);
    enqueue(myQueue, 50);
    enqueue(myQueue, 60); // This will fail as the queue is full
    display(myQueue);

    destroy(myQueue);
    free(myQueue);

    return 0;
}
