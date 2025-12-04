//-- Queue Representation using Structure --//

#include <stdio.h>
#define MAX 100

// Define the structure for the queue
struct Queue {
    int data[MAX];
    int front;
    int rear;
};
struct Queue q; // Declare a global instance of the queue structure

// initializeQueue() - Initializes queue
void initializeQueue() {
    q.front = -1;
    q.rear = -1;
    printf("Queue initialized.\n");
}

// isFull() - Checks if queue is full
int isFull() {
    return q.rear == MAX - 1;
}

// isEmpty() - Checks if queue is empty
int isEmpty() {
    return q.front == -1;
}

// peek() - Returns front element without removing it
int peek() {
    if (isEmpty()) {
        printf("Queue is empty! No front element.\n");
        return -1;
    }
    printf("Front element is: %d\n", q.data[q.front]);
    return q.data[q.front];
}

// enqueue() - Adds element to queue
void enqueue(int data) {
    if (isFull()) {
        printf("Queue is full! Cannot enqueue %d.\n", data);
    } else {
        if (isEmpty()) {
            q.front = 0;
        }
        q.rear++;
        q.data[q.rear] = data;
        printf("%d enqueued to queue.\n", data);
    }
}

// dequeue() - Removes element from queue
int dequeue() {
    int data;
    if (isEmpty()) {
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

// display() - Prints all elements of the queue
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = q.front; i <= q.rear; i++) {
            printf("%d ", q.data[i]);
        }
        printf("\n");
    }
}

// MAIN FUNCTION
int main() {
    initializeQueue();

    // Check before operations
    printf("Is queue empty? %s\n", isEmpty() ? "Yes" : "No");
    printf("Is queue full? %s\n", isFull() ? "Yes" : "No");
    peek();

    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    
    peek();

    dequeue();
    display();
    
    dequeue();
    dequeue();
    dequeue(); // Attempt to dequeue from an empty queue
    
    return 0;
}
