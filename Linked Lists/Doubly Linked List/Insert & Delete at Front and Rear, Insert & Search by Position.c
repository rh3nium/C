#include <stdio.h>
#include <stdlib.h>

// Doubly Linked List Node Structure
typedef struct Node {
    int data;
    struct Node* prev; // Pointer to previous node
    struct Node* next; // Pointer to next node
} Node;

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Error: No memory available\n");
        return NULL;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at Front
Node* insertFront(Node* head, int data) {
    Node* newNode = createNode(data);
    if (newNode == NULL) return head;

    if (head != NULL) {
        head->prev = newNode;
    }
    newNode->next = head;
    head = newNode;
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
    newNode->prev = current;
    
    return head;
}

// Delete at front
Node* deleteFront(Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from front.\n");
        return NULL;
    }

    Node* temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
    return head;
}

// Delete at Rear
Node* deleteRear(Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from rear.\n");
        return NULL;
    }

    if (head->next == NULL) { // Only one node
        free(head);
        return NULL;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    // current is the last node
    current->prev->next = NULL;

    free(current);
    return head;
}

// Insert at Position
Node* insertByPosition (Node* head, int data, int position) {
    if (position < 1) {
        printf("Invalid position. Position must be >= 1\n");
        return head;
    }

    if (position == 1) {
        return insertFront(head, data);
    }
    Node* newNode = createNode(data);
    if (newNode == NULL) return head;

    Node* current = head;
    int current_position = 1;

    // Traverse to the node before the target insert position
    while (current != NULL && current_position < position - 1) {
        current = current->next;
        current_position++;
    }
    
    if (current == NULL) {
        printf("Position %d is out of bounds. Cannot insert.\n", position);
        free(newNode);
        return head;
    }

    Node* node_at_pos = current->next; 

    // Update new node's links
    newNode->next = node_at_pos;
    newNode->prev = current;

    // Update links of neighboring nodes
    current->next = newNode;
    if (node_at_pos != NULL) {
        node_at_pos->prev = newNode;
    }

    return head;
}

// Delete at Position
Node* deleteByPosition(Node* head, int position) {
    if (head == NULL || position < 1) {
        printf(head == NULL ? "List is empty. Cannot delete.\n" : "Invalid position. Position must be >= 1\n");
        return head;
    }

    if (position == 1) {
        return deleteFront(head);
    }
    Node* current = head;
    int current_position = 1;

    while (current != NULL && current_position < position) {
        current = current->next;
        current_position++;
    }
    
    if (current == NULL) {
        printf("Position %d is out of bounds. Cannot delete.\n", position);
        return head;
    }

    // current is the node to be deleted
    if (current->prev != NULL) {
        current->prev->next = current->next;
    }
    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

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

// Search node by Value
int searchByValue(Node* head, int value) {
    Node* current = head;
    int position = 1;

    // Traverse the list until the end or until the value is found
    while (current != NULL) {
        if (current->data == value) {
            return position; // Return the 1-based position of the first occurrence
        }
        current = current->next;
        position++;
    }

    // If the loop finishes without finding the value
    return -1; // Value not found
}

// Display linked list (forward traversal)
void displayList(Node* head) {
    if (head == NULL) {
        printf("List is currently empty\n");
        return;
    }
    Node* current = head;
    printf("DLL (Forward): ");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" <-> ");
        }
        current = current->next;
    }
    printf("\n");
}


// MAIN FUNCTION
int main() {
    Node* head = NULL; 

    // Insert at Front/Rear
    printf("INSERT FRONT (10, 20) & REAR (30, 40):\n");
    head = insertFront(head, 10);
    head = insertFront(head, 20);
    head = insertRear(head, 30);
    head = insertRear(head, 40); // List: 20 <-> 10 <-> 30 <-> 40
    displayList(head); 

    // Insert at Position
    printf("\nINSERT 55 at POSITION 3:\n");
    head = insertByPosition(head, 55, 3); // Inserts 55 between 10 and 30
    displayList(head); // List: 20 <-> 10 <-> 55 <-> 30 <-> 40

    // Delete at Position
    printf("DELETE at POSITION 2:\n");
    head = deleteByPosition(head, 2); // Deletes 10
    displayList(head); // List: 20 <-> 55 <-> 30 <-> 40

    // Delete at Front/Rear
    printf("\nDELETE at FRONT & REAR:\n");
    head = deleteFront(head); // Deletes 20
    head = deleteRear(head);  // Deletes 40
    displayList(head); // List: 55 <-> 30

    // Search by Position
    printf("\nSEARCH by POSITION 1:\n");
    int data = searchByPosition(head, 1);
    if (data != -1) printf("Node found: %d\n", data);

    // Search by Value
    printf("\n3. SEARCH for VALUE 55:\n");
    int pos_val = searchByValue(head, 55);
    if (pos_val != -1) {
        printf("Value 55 found at position: %d\n", pos_val);
    } else {
        printf("Value 55 not found.\n");
    }

    // Cleanup
    printf("\nFinal Cleanup:\n");
    while (head != NULL) {
        head = deleteFront(head);
    }
    displayList(head); // Output: "List is currently empty"
    
    return 0;
}
