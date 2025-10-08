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
    if (newNode==NULL) {
        printf("No memory\n");
        return NULL;
    }
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}


// Insert at front
Node* insertFront(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next=head;
    head=newNode;
    return head;
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

// Delete at front
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

// Delete at rear
Node* deleteRear(Node* head) {
    if (head == NULL) {
        printf("List empty\n");
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


// Display linked list
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
        current = current -> next;
    }
    printf("\n");
}

// MAIN FUNCTION
int main() {
    Node* head = createNode(10);
    printf("Node created with data: %d\n", head->data);
    head = insertFront(head, 20);
    printf("New head data: %d\n", head->data);
    
    // Insert at front
    printf("\nInserting FRONT nodes:\n");
    head = insertFront(head, 5);
    head = insertFront(head, 33);
    head = insertFront(head, 996);
    displayList(head);
    
    // Delete at front
    printf("\nDeleting FRONT node:\n");
    head = deleteFront(head);
    displayList(head);
    
    // Insert at rear
    printf("\nInserting REAR node:\n");
    head = insertRear(head, 222);
    displayList(head);
    
    // Delete at rear
    printf("\nDeleting REAR node:\n");
    head = deleteRear(head);
    head = deleteRear(head);
    head = deleteRear(head);
    head = deleteRear(head);
    head = deleteRear(head);
    displayList(head);
    
    // Check empty list state
    printf("\nFinal State Check:\n");
    head = deleteFront(head);
    head = deleteRear(head);
    displayList(head);
    
    return 0;
}
