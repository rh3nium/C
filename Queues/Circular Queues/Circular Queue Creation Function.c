// Circular Queue Creation Function

#include <stdio.h>
#include <stdlib.h>

// Define the Circular Queue structure
typedef struct {
    int *data;
    int size;
    int front;
    int rear;
} *CQueue;

// Function to create and initialize a circular queue
void createCQ(CQueue q, int size) {
    q->size = size;
    q->front = -1;
    q->rear = -1;
    // Dynamically allocate memory for the data array
    q->data = (int *)malloc(size * sizeof(int));
    if (q->data == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    // Initialize data array to zeros (as per the code snippet)
    for (int i = 0; i < size; i++) {
        q->data[i] = 0;
    }
}

// Function to check if the queue is full
int isFull(CQueue q) {
    if ((q->rear + 1) % q->size == q->front) {
        return 1;
    }
    return 0;
}

// Function to check if the queue is empty
int isEmpty(CQueue q) {
    if (q->front == -1) {
        return 1;
    }
    return 0;
}

// Function to add an element to the circular queue (enqueue)
void enqueue(CQueue q, int item) {
    if (isFull(q)) {
        printf("Queue is full, cannot enqueue!\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear = (q->rear + 1) % q->size;
        q->data[q->rear] = item;
        printf("Enqueued: %d\n", item);
    }
}

// Function to remove an element from the circular queue (dequeue)
int dequeue(CQueue q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty, cannot dequeue!\n");
        return -1;
    } else {
        item = q->data[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front = (q->front + 1) % q->size;
        }
        printf("Dequeued: %d\n", item);
        return item;
    }
}

// Function to display the elements of the circular queue
void display(CQueue q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Elements in the queue are: ");
        int i = q->front;
        while (1) {
            printf("%d ", q->data[i]);
            if (i == q->rear) break;
            i = (i + 1) % q->size;
        }
        printf("\n");
    }
}

// Main function to demonstrate the operations
int main() {
    int queueSize = 5;
    CQueue myQueue = (CQueue)malloc(sizeof(struct CircularQueue));
    if (myQueue == NULL) {
        printf("Memory allocation for queue failed!\n");
        return 1;
    }

    createCQ(myQueue, queueSize);

    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    display(myQueue);

    dequeue(myQueue);
    display(myQueue);

    enqueue(myQueue, 40);
    enqueue(myQueue, 50);
    enqueue(myQueue, 60); // This will fail as the queue is full
    display(myQueue);

    // Free the dynamically allocated memory
    if (myQueue->data != NULL) {
        free(myQueue->data);
    }
    free(myQueue);

    return 0;
}
