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

// Insert at Front
Node* insertFront(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next=head;
    head=newNode;
    return head;
}

// Insert at Rear
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

// Delete at Front
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

// Delete at Rear
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

// Insert by Position
Node* insertByPosition (Node* head, int data, int position) {
    if (position<1) {
        printf("Invalid position. Position must be >= 1");
        return head;
    }
    // Insert at beginning (position 1)
    if (position == 1) {
        return insertFront(head, data);
    }
    Node* newNode = createNode(data);
    if (newNode == NULL) return head;

    Node* current = head;
    Node* previous = NULL;
    int current_position = 1;
    
    // Traverse to the node before the target insert position
    while (current != NULL && current_position < position) {
        previous = current;
        current = current->next;
        current_position++;
    }
    // If position is out of bounds
    if (current_position < position) {
        printf("Position %d is out of bounds. List length is %d\n", position, current_position - 1);
        free(newNode);
        return head;
    }
    // Insert new node
    newNode->next = current;
    if (previous != NULL) {
        previous->next = newNode;
    } else {
        head = newNode;
    }
    return head;
}

// Delete by Position
Node* deletebyPosition(Node* head, int position) {
    if (head==NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (position < 1) {
        printf("Invalid position. Position must be >= 1\n");
        return head;
    }
    if (position==1) {
        return deleteFront(head);
    }
    Node* current = head;
    Node* previous = NULL;
    int current_position = 1;
    
    while (current != NULL && current_position < position) {
        previous = current;
        current = current->next;
        current_position++;
    }
    if (current==NULL) {
        printf("Position %d is out of bounds. List length is %d\n", position, current_position-1);
        return head;
    }
    previous->next = current->next;
    free(current);
    return head;
}

// Search by Position
int searchByPosition(Node* head, int position) {
    if (position < 1) {
        printf("Invalid position. Must be >= 1\n");
        return -1;
    }
    Node* current = head;
    int current_position = 1;
    while(current != NULL && current_position < position) {
        current = current->next;
        current_position++;
    }
    if (current != NULL) {
        return current->data;
    } else {
        printf("Position %d is out of bounds. Node not found\n", position);
        return -1;
    }
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
    
    // Insert at Front
    printf("\nInserting FRONT nodes:\n");
    head = insertFront(head, 5);
    head = insertFront(head, 33);
    head = insertFront(head, 996);
    displayList(head);
    
    // Delete at Front
    printf("\nDeleting FRONT node:\n");
    head = deleteFront(head);
    displayList(head);
    
    // Insert at Rear
    printf("\nInserting REAR node:\n");
    head = insertRear(head, 222);
    displayList(head);
    
    // Delete at Rear
    printf("\nDeleting REAR node:\n");
    head = deleteRear(head);
    head = deleteRear(head);
    head = deleteRear(head);
    head = deleteRear(head);
    head = deleteRear(head);
    displayList(head);
        
    // Insert at Position
    printf("\nInserting 88 at position 3:\n");
    head = insertByPosition(head, 88, 3); // List: 996 -> 33 -> 88 -> 5 -> 20 -> 10
    displayList(head);
    
    printf("Inserting 1 at position 1 (front):\n");
    head = insertByPosition(head, 1, 1); // List: 1 -> 996 -> 33 -> 88 -> 5 -> 20 -> 10
    displayList(head);
    
    // Delete at Position
    printf("\nDeleting node at position 3 (88):\n");
    head = deletebyPosition(head, 3); // Removes 88
    displayList(head); // List: 996 -> 33 -> 5 -> 20 -> 10

    printf("Deleting node at position 1 (996):\n");
    head = deletebyPosition(head, 1); // Removes 996
    displayList(head); // List: 33 -> 5 -> 20 -> 10
    
    // Search by Position
    int data_pos3 = searchByPosition(head, 3); // Should find 33
    if (data_pos3 != -1) printf("\nData at position 3 is: %d\n", data_pos3);
    
    int data_pos7 = searchByPosition(head, 7); // Should find 10
    if (data_pos7 != -1) printf("Data at position 7 is: %d\n", data_pos7);
    
    printf("\nSearching out-of-bounds position 10:\n");
    searchByPosition(head, 10);
    
    
    // Check Empty list state
    printf("\nFinal State Check:\n");
    head = deleteFront(head);
    head = deleteRear(head);
    displayList(head);
    
    return 0;
}
