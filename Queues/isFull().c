// isFull() - Checks if queue is full

#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Using a small size to easily demonstrate a full queue

typedef struct {
    int data[MAX];
    int front;
    int rear;
} *Queue;

// Function to check if the queue is full
int isFull(Queue q) {
    return q->rear == MAX - 1;
}

// Function to check if the queue is empty
int isEmpty(Queue q) {
    return q->front == -1;
}

// Function to initialize the queue
void initializeQueue(Queue q) {
    if (q != NULL) {
        q->front = -1;
        q->rear = -1;
        printf("Queue initialized.\n");
    }
}

// Function to add an element to the queue
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

// Function to display the elements of the queue
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
    
    initializeQueue(q);
    
    printf("\nIs the queue full? %s\n\n", isFull(q) ? "Yes" : "No");
    
    // Fill the queue
    for (int i = 1; i <= MAX; i++) {
        enqueue(q, i * 10);
    }
    
    display(q);
    
    // Check if the queue is full after filling it
    printf("\nIs the queue full? %s\n\n", isFull(q) ? "Yes" : "No");

    // Attempt to enqueue another element to show the full check working
    enqueue(q, 60);

    // Clean up memory
    free(q);
    
    return 0;
}
