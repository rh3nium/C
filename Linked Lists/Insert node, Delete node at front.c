#include <stdio.h>
#include <stdlib.h>

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

// Insert at front
Node* insertFront(Node* head, int data) {
  Node* newNode = createNode(data);
  newNode->next = head;
  head = newNode;
  return head;
}
/* New node points to the old head.
head pointer is updated to the new node
Time Complexity - O(1)
*/

// Delete at front
Node* deleteFront(Node* head) {
    if (head == NULL) {
        printf("List is empty, nothing to delete.\n");
        return NULL;
    }
    // 1. Save the pointer to the current head node
    Node* temp = head;
    // 2. Move the head pointer to the next node
    head = head->next;
    // 3. Free the original head node's memory
    free(temp);
    // 4. Return the new head of the list
    return head;
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


int main() {
    Node* head = createNode(10);
    printf("Node created with data: %d\n", head->data);
    head = insertFront(head, 20);
    printf("New head data: %d\n", head->data);
    
    // Insertion at Front
    head = insertFront(head, 5);
    head = insertFront(head, 33);
    head = insertFront(head, 996);
    printf("List After Insertions\n");
    displayList(head); // Output: 30 -> 20 -> 10
    
    // Deletion at Front
    printf("\nDeleting Front Node\n");
    head = deleteFront(head); // Deletes 30
    printf("List after 1st deletion:\n");
    displayList(head); // Output: 20 -> 10
    // Delete again
    head = deleteFront(head); // Deletes 20
    printf("\nList after 2nd deletion:\n");
    displayList(head); // Output: 10
    // Delete the last node
    head = deleteFront(head); // Deletes 10
    printf("\nList after 3rd deletion:\n");
    displayList(head); // Output: List is currently empty.
    // Attempt to delete from an empty list
    head = deleteFront(head);

    return 0;
}
