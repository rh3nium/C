// Queue Representation using typedef

#include <stdio.h>
#define MAX 100

// Use typedef to create a new type "Queue"
typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

// Function prototypes
void initializeQueue(Queue* q);
void enqueue(Queue* q, int data);
int dequeue(Queue* q);
void display(Queue* q);

int main() {
    Queue q1, q2;

    // Initialize both queues
    initializeQueue(&q1);
    initializeQueue(&q2);

    // Operations on Queue 1
    printf("--- Operations on Queue 1 ---\n");
    enqueue(&q1, 10);
    enqueue(&q1, 20);
    enqueue(&q1, 30);
    display(&q1);

    dequeue(&q1);
    display(&q1);

    printf("\n");

    // Operations on Queue 2
    printf("--- Operations on Queue 2 ---\n");
    enqueue(&q2, 100);
    enqueue(&q2, 200);
    display(&q2);

    return 0;
}

// Function to initialize a queue
void initializeQueue(Queue* q) {
    q->front = -1;
    q->rear = -1;
    printf("A queue has been initialized.\n");
}

// Function to add an element to a queue
void enqueue(Queue* q, int data) {
    if (q->rear == MAX - 1) {
        printf("Queue is full! Cannot enqueue %d.\n", data);
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->data[q->rear] = data;
        printf("%d enqueued.\n", data);
    }
}

// Function to remove an element from a queue
int dequeue(Queue* q) {
    int data;
    if (q->front == -1) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1;
    } else {
        data = q->data[q->front];
        if (q->front == q->rear) {
            q->front = -1;
            q->rear = -1;
        } else {
            q->front++;
        }
        printf("%d dequeued.\n", data);
        return data;
    }
}

// Function to display the elements of a queue
void display(Queue* q) {
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
