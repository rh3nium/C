#include <stdio.h>
#include <stdlib.h>

// Singly Linked List Node Structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Create a node
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

// Function to display the linked list
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is currently empty.\n");
        return;
    }
    Node* current = head;
    printf("Linked List: ");
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
    Node* head = createNode(10);
    printf("Node created with data: %d\n", head->data);
    head = insertFront(head, 20);
    printf("New head data: %d\n", head->data);
    
    // Insertions at Front
    head = insertFront(head, 5);
    head = insertFront(head, 33);
    head = insertFront(head, 996);
    printf("List After Initial Insertions\n");
    displayList(head); // Output: 30 -> 20 -> 10

    return 0;
}
