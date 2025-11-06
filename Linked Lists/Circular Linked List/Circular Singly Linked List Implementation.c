// --- Circular Singly Linked List (CSLL) --- //

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

// Structure of a Node — Circular Singly Linked List
typedef struct CSLL_Node {
    int data;
    struct CSLL_Node *next;
} CSLL_Node; 

// --- Create a Node ---
CSLL_Node* createCSLLNode(int data) {
    CSLL_Node* newNode = (CSLL_Node*)malloc(sizeof(CSLL_Node));
    
    if (!newNode) {
        printf("No Memory\n");
        exit(1);
    }
    
    newNode->data = data;
    newNode->next = newNode; // Points to itself for a single node
    
    return newNode;
}

// --- Traversal (Display) ---
void displayCSLL(CSLL_Node* Head) {
    if (Head == NULL) {
        printf("List Empty\n");
        return;
    }
    
    CSLL_Node* Temp = Head;
    printf("CSLL: ");
    
    do {
        printf("%d -> ", Temp->data);
        Temp = Temp->next;
    } while (Temp != Head);
    
    printf("(Head)\n");
}

// --- Insert Front ---
CSLL_Node* insertFrontCSLL(CSLL_Node* Head, int data) {
    CSLL_Node* newNode = createCSLLNode(data);

    if (Head == NULL) {
        return newNode;
    }
    
    // Find the last node (Tail)
    CSLL_Node* last = Head;
    while (last->next != Head) {
        last = last->next;
    }
    
    // Link the new node
    newNode->next = Head;
    last->next = newNode;
    
    return newNode; // New node becomes the Head
}

// --- Insert Rear ---
CSLL_Node* insertRearCSLL(CSLL_Node* Head, int data) {
    CSLL_Node* newNode = createCSLLNode(data);

    if (Head == NULL) {
        return newNode;
    }
    
    // Find the last node (Tail)
    CSLL_Node* last = Head;
    while (last->next != Head) {
        last = last->next;
    }
    
    // Link the new node
    newNode->next = Head;
    last->next = newNode;
    
    return Head; // Head remains the same
}

// --- Delete Front ---
CSLL_Node* deleteFrontCSLL(CSLL_Node* Head) {
    if (Head == NULL) {
        printf("List Empty\n");
        return NULL;
    }

    CSLL_Node* Temp = Head;
    
    if (Temp->next == Head) { // Only one node
        free(Temp);
        return NULL;
    }

    // Find the last node (Tail)
    CSLL_Node* last = Head;
    while (last->next != Head) {
        last = last->next;
    }
    
    Head = Temp->next;  // New Head
    last->next = Head;  // Update Tail to point to new Head
    free(Temp);         // Delete old Head
    
    return Head; 
}

// --- Delete Rear ---
CSLL_Node* deleteRearCSLL(CSLL_Node* Head) {
    if (Head == NULL) {
        printf("List Empty\n");
        return NULL;
    }

    CSLL_Node* Temp = Head;
    
    if (Temp->next == Head) { // Only one node
        free(Temp);
        return NULL;
    }

    // Traverse to the node before the last node
    CSLL_Node* Prev = NULL;
    while (Temp->next != Head) {
        Prev = Temp;
        Temp = Temp->next; // Temp is the node to delete (Tail)
    }

    Prev->next = Head; // New Tail points to Head
    free(Temp);
    
    return Head; 
}


// --- MAIN FUNCTION --- //
int main() {
    CSLL_Node* Head = NULL;

    printf("Circular Singly Linked List\n");

    // Insertions
    Head = insertFrontCSLL(Head, 10);
    Head = insertFrontCSLL(Head, 20); 
    Head = insertRearCSLL(Head, 30);  
    
    printf("\nInitial List (20, 10, 30):\n");
    displayCSLL(Head);

    // Deletions
    Head = deleteRearCSLL(Head); // Delete 30
    printf("\nAfter deleting rear (30):\n");
    displayCSLL(Head); 

    Head = deleteFrontCSLL(Head); // Delete 20
    printf("After deleting front (20):\n");
    displayCSLL(Head); 
    
    Head = insertRearCSLL(Head, 40);
    printf("\nAfter inserting rear (40):\n");
    displayCSLL(Head); 
    
    // Delete remaining nodes
    Head = deleteFrontCSLL(Head);
    Head = deleteFrontCSLL(Head);
    printf("After deleting remaining nodes:\n");
    displayCSLL(Head);
    
    return 0;
}
