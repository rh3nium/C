#include <stdio.h>
#include <stdlib.h>

// Define node
typedef struct Node {
    int data;
    struct Node* next;
} Node;
// Create node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("No memory\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at front
Node* insertFront(Node* head, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return head;
    newNode->next = head;
    return newNode;
}

// Insert at rear
Node* insertRear(Node* head, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return head;

    if (head == NULL) {
        return newNode;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    return head;
}

// Delete from front
Node* deleteFront(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Delete from rear
Node* deleteRear(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }

    if (head->next == NULL) {
        free(head);
        return NULL;
    }

    Node* current = head;
    Node* previous = NULL;

    while (current->next != NULL) {
        previous = current;
        current = current->next;
    }

    previous->next = NULL;
    free(current); 
    return head;
}

// Display linked list elements
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is currently empty\n");
        return;
    }
    Node* current = head;
    printf("Linked list: ");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

// MAIN FUNCTION
int main() {
    Node* head = NULL;

    printf("Start of Operations\n");
    displayList(head);

    // Insert at Front
    printf("\nINSERT FRONT OPERATIONS\n");
    head = insertFront(head, 10);
    printf("Inserted 10 at front. "); displayList(head);
    
    head = insertFront(head, 5);
    printf("Inserted 5 at front. "); displayList(head);
    
    // Insert at Rear
    printf("\nINSERT REAR OPERATIONS\n");
    head = insertRear(head, 20);
    printf("Inserted 20 at rear. "); displayList(head);
    
    head = insertRear(head, 30);
    printf("Inserted 30 at rear. "); displayList(head);

    // Delete at Front
    printf("\nDELETE FRONT OPERATIONS\n");
    head = deleteFront(head);
    printf("Deleted from front (5). "); displayList(head);
    
    head = deleteFront(head);
    printf("Deleted from front (10). "); displayList(head);
    
    // Delete at Rear
    printf("\nDELETE REAR OPERATIONS\n");
    head = deleteRear(head);
    printf("Deleted from rear (30). "); displayList(head);
    
    head = deleteRear(head);
    printf("Deleted from rear (20). "); displayList(head);

    // Check empty list state
    printf("\nFinal State Check\n");
    head = deleteFront(head);
    head = deleteRear(head);
    displayList(head);

    return 0;
}
