// --- Circular Singly Linked List (CSLL) --- //

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

// Structure of a Node — Circular Singly Linked List
typedef struct Node {
    int data;
    struct Node *next;
} Node; 

// --- Create a Node ---
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    if (!newNode) {
        printf("No Memory\n");
        exit(1);
    }
    
    newNode->data = data;
    newNode->next = newNode;  // Points to itself
    
    return newNode;
}

// --- Traversal / Display ---
void displayList(Node* Head) {
    if (Head == NULL) {
        printf("List Empty\n");
        return;
    }
    
    Node* Temp = Head;
    printf("CSLL: ");
    
    do {
        printf("%d -> ", Temp->data);
        Temp = Temp->next;
    } while (Temp != Head);
    
    printf("(Head)\n");
}

// --- Insert at Front ---
Node* insertAtFront(Node* Head, int data) {
    Node* newNode = createNode(data);

    if (Head == NULL) {
        return newNode;
    }
    
    // Find the last node (Tail)
    Node* last = Head;
    while (last->next != Head) {
        last = last->next;
    }
    
    newNode->next = Head;
    last->next = newNode;
    
    return newNode;  // New node becomes Head
}

// --- Insert at Rear ---
Node* insertAtRear(Node* Head, int data) {
    Node* newNode = createNode(data);

    if (Head == NULL) {
        return newNode;
    }
    
    // Find the last node (Tail)
    Node* last = Head;
    while (last->next != Head) {
        last = last->next;
    }
    
    last->next = newNode;
    newNode->next = Head;
    
    return Head;
}

// --- Delete at Front ---
Node* deleteAtFront(Node* Head) {
    if (Head == NULL) {
        printf("List Empty\n");
        return NULL;
    }

    Node* Temp = Head;
    
    // Only one node
    if (Temp->next == Head) {
        free(Temp);
        return NULL;
    }

    // Find last node
    Node* last = Head;
    while (last->next != Head) {
        last = last->next;
    }
    
    Head = Temp->next;   // New head
    last->next = Head;   // Fix tail link
    free(Temp);

    return Head; 
}

// --- Delete at Rear ---
Node* deleteAtRear(Node* Head) {
    if (Head == NULL) {
        printf("List Empty\n");
        return NULL;
    }

    Node* Temp = Head;

    // Only one node
    if (Temp->next == Head) {
        free(Temp);
        return NULL;
    }

    Node* Prev = NULL;
    while (Temp->next != Head) {
        Prev = Temp;
        Temp = Temp->next;  // Temp reaches last node
    }

    Prev->next = Head;  
    free(Temp);

    return Head;
}

// --- MAIN FUNCTION --- //
int main() {
    Node* Head = NULL;

    printf("Circular Singly Linked List\n");

    // Insertions
    Head = insertAtFront(Head, 10);
    Head = insertAtFront(Head, 20); 
    Head = insertAtRear(Head, 30);  
    
    printf("\nInitial List (20, 10, 30):\n");
    displayList(Head);

    // Deletions
    Head = deleteAtRear(Head); // Delete 30
    printf("\nAfter deleting rear (30):\n");
    displayList(Head); 

    Head = deleteAtFront(Head); // Delete 20
    printf("After deleting front (20):\n");
    displayList(Head); 
    
    Head = insertAtRear(Head, 40);
    printf("\nAfter inserting rear (40):\n");
    displayList(Head); 
    
    // Delete remaining nodes
    Head = deleteAtFront(Head);
    Head = deleteAtFront(Head);
    printf("\nAfter deleting remaining nodes:\n");
    displayList(Head);
    
    return 0;
}
