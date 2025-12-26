#include <stdio.h>
#include <stdlib.h>

// Define max queue size
#define MAX 10

// Priority queue structure
typedef struct {
    int items[MAX];
    int size;
} PriorityQueue;


// enqueue() - insert element at the end
void enqueue(PriorityQueue* pq, int value)
{
    if (pq->size == MAX) {
        printf("Priority Queue is full\n");
        return;
    }

    pq->items[pq->size++] = value;
}

// dequeue() - remove element with highest priority (smallest value)
int dequeue(PriorityQueue* pq)
{
    if (pq->size == 0) {
        printf("Priority Queue is empty\n");
        return -1;
    }

    int minIndex = 0;

    // Find index of smallest element
    for (int i = 1; i < pq->size; i++) {
        if (pq->items[i] < pq->items[minIndex]) {
            minIndex = i;
        }
    }

    int item = pq->items[minIndex];

    // Shift elements left
    for (int i = minIndex; i < pq->size - 1; i++) {
        pq->items[i] = pq->items[i + 1];
    }

    pq->size--;
    return item;
}

// peek() - return highest priority element
int peek(PriorityQueue* pq)
{
    if (pq->size == 0) {
        printf("Priority Queue is empty\n");
        return -1;
    }

    int min = pq->items[0];
    for (int i = 1; i < pq->size; i++) {
        if (pq->items[i] < min) {
            min = pq->items[i];
        }
    }
    return min;
}


// MAIN FUNCTION //
int main()
{
    PriorityQueue pq = {{0}, 0};

    enqueue(&pq, 3);
    enqueue(&pq, 2);
    enqueue(&pq, 15);
    enqueue(&pq, 5);
    enqueue(&pq, 4);
    enqueue(&pq, 45);

    printf("%d dequeued from queue\n", dequeue(&pq));
    printf("Top element is %d\n", peek(&pq));

    return 0;
}
