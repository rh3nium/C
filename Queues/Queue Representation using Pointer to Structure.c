// Queue Representation using Pointer to Structure

#include <stdio.h>
#include <stdlib.h> // Required for malloc() and free()

#define MAX 100

// Using typedef struct to define a new type 'Queue' as a pointer to a struct
typedef struct {
    int data[MAX];
    int front;
    int rear;
} *Queue;

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
    if (q == NULL) {
        printf("Queue is not initialized.\n");
        return;
    }
    if (q->rear == MAX - 1) {
        printf("Queue is full! Cannot enqueue %d.\n", value);
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->data[q->rear] = value;
        printf("%d enqueued to queue.\n", value);
    }
}

// Function to remove an element from the queue
int dequeue(Queue q) {
    if (q == NULL) {
        printf("Queue is not initialized.\n");
        return -1;
    }
    int value;
    if (q->front == -1) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    } else {
        value = q->data[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
        printf("%d dequeued from queue.\n", value);
        return value;
    }
}

// Function to display the elements of the queue
void display(Queue q) {
    if (q == NULL) {
        printf("Queue is not initialized.\n");
        return;
    }
    if (q->front == -1) {
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
    // 1. Declare a Queue pointer
    Queue q = NULL;

    // 2. Allocate memory for the queue structure
    q = (Queue) malloc(sizeof(struct Queue));
    if (q == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // 3. Perform queue operations
    initializeQueue(q);
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);

    dequeue(q);
    display(q);
    
    // 4. Free the allocated memory
    free(q);
    q = NULL; // Best practice to prevent dangling pointer
    printf("\nMemory freed.\n");

    return 0;
}
