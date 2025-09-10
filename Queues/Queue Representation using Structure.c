// Queue Representation using Structure

#include <stdio.h>
#define MAX 100

// Define the structure for the queue
struct Queue {
    int data[MAX];
    int front;
    int rear;
};

// Declare a global instance of the queue structure
struct Queue q;

// Function to initialize the queue
void initializeQueue() {
    q.front = -1;
    q.rear = -1;
    printf("Queue initialized.\n");
}

// Function to add an element to the queue
void enqueue(int data) {
    if (q.rear == MAX - 1) {
        printf("Queue is full! Cannot enqueue %d.\n", data);
    } else {
        if (q.front == -1) {
            q.front = 0;
        }
        q.rear++;
        q.data[q.rear] = data;
        printf("%d enqueued to queue.\n", data);
    }
}

// Function to remove an element from the queue
int dequeue() {
    int data;
    if (q.front == -1) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    } else {
        data = q.data[q.front];
        if (q.front == q.rear) {
            q.front = -1;
            q.rear = -1;
        } else {
            q.front++;
        }
        printf("%d dequeued from queue.\n", data);
        return data;
    }
}

// Function to display the elements of the queue
void display() {
    if (q.front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = q.front; i <= q.rear; i++) {
            printf("%d ", q.data[i]);
        }
        printf("\n");
    }
}

int main() {
    initializeQueue();
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    
    dequeue();
    display();
    
    dequeue();
    dequeue();
    dequeue(); // Attempt to dequeue from an empty queue
    
    return 0;
}
