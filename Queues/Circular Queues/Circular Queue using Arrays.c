// Circular Queue using Arrays

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// Define the CircularQueue structure
typedef struct {
    int data[MAX];
    int front;
    int rear;
} CircularQueue;

// Function to initialize the queue
void initializeQueue(CircularQueue* q) {
    q->front = -1;
    q->rear = -1;
}

// Function to check if the queue is full
int isFull(CircularQueue* q) {
    if ((q->rear + 1) % MAX == q->front) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty(CircularQueue* q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

// Function to add an element to the circular queue (enqueue)
void enqueue(CircularQueue* q, int item) {
    if (isFull(q)) {
        printf("Queue is full, cannot enqueue!\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % MAX;
        q->data[q->rear] = item;
        printf("Enqueued: %d\n", item);
    }
}

// Function to remove an element from the circular queue (dequeue)
int dequeue(CircularQueue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty, cannot dequeue!\n");
        return -1; // Sentinel value for an error
    } else {
        item = q->data[q->front];
        if (q->front == q->rear) {
            // Queue has only one element, reset
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % MAX;
        }
        printf("Dequeued: %d\n", item);
        return item;
    }
}

// Function to display the elements of the circular queue
void display(CircularQueue* q) {
    int i;
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Elements in the queue are: ");
        for (i = q->front; i != q->rear; i = (i + 1) % MAX) {
            printf("%d ", q->data[i]);
        }
        printf("%d\n", q->data[i]);
    }
}

// Main function to demonstrate the operations
int main() {
    CircularQueue myQueue;
    initializeQueue(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);
    display(&myQueue);

    dequeue(&myQueue);
    display(&myQueue);

    enqueue(&myQueue, 40);
    enqueue(&myQueue, 50);
    enqueue(&myQueue, 60); // This will fail as the queue is full
    display(&myQueue);

    return 0;
}
