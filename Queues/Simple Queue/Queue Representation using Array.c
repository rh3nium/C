// Queue representation using array

#include <stdio.h>
#define MAX 100

int main() {
    int queue[MAX];
    int front = -1, rear = -1;
    int data;

    // --- Enqueue Operation (adding an element) ---
    data = 10;
    if (rear == MAX - 1) {
        printf("Queue is full! Cannot enqueue %d.\n", data);
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = data;
        printf("%d enqueued to queue.\n", data);
    }

    // Display the queue after enqueue
    printf("Current Queue: ");
    if (front != -1) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    }
    printf("\n\n");

    // --- Dequeue Operation (removing an element) ---
    if (front == -1) {
        printf("Queue is empty! Cannot dequeue.\n");
    } else {
        data = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front++;
        }
        printf("%d dequeued from queue.\n", data);
    }

    // Display the queue after dequeue
    printf("Current Queue: ");
    if (front != -1) {
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
    } else {
        printf("Queue is now empty.");
    }
    printf("\n");

    return 0;
}
