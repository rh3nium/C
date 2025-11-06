// --- Circular Doubly Linked List (Without Tail) --- //

#include <stdio.h>
#include <stdlib.h>

// Structure of a Node - Circular Doubly Linked List (CDLL)
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} *NODE;

// --- Create a Node ---
NODE createNode(int data) {
    NODE NN = (NODE)malloc(sizeof(struct Node)); 
    if (NN == NULL) {
        printf("No Memory\n");
        exit(1);
    }
    NN->data = data;
    NN->prev = NN; 
    NN->next = NN; 
    return NN;
}

// --- Traversal (Forward) ---
void displayCDLL(NODE Head) {
    if (Head == NULL) {
        printf("List Empty\n");
        return;
    }
    
    NODE Temp = Head;
    printf("CDLL (Version 2 - Forward): ");
    
    do {
        printf("%d <-> ", Temp->data);
        Temp = Temp->next;
    } while (Temp != Head); 
    
    printf("(Head)\n");
}

// --- Insert Front ---
NODE insertFrontCDLL_V2(NODE Head, int data) {
    NODE NN = createNode(data);
    
    // 2. if Head == NULL then
    if (Head == NULL) {
        // 3. return NN
        return NN;
    }
    
    // Find the Tail (last node) by traversing: O(N) operation
    NODE Temp = Head;
    while (Temp->next != Head) {
        Temp = Temp->next;
    } 
    // Temp is now the Tail

    // 7. Set NN->next = Head
    NN->next = Head;
    
    // 8. Set NN->prev = Temp (Tail)
    NN->prev = Temp;
    
    // 9. Set Temp->next = NN
    Temp->next = NN;
    
    // 10. Set Head->prev = NN
    Head->prev = NN;
    
    // 11. Set Head = NN
    Head = NN;
    
    // 12. return Head
    return Head;
}

// --- Insert Rear ---
NODE insertRearCDLL_V2(NODE Head, int data) {
    NODE NN = createNode(data);

    // 2. if Head == NULL then
    if (Head == NULL) {
        // 3. return NN
        return NN;
    }
    
    // Find the Tail (last node) by traversing: O(N) operation
    NODE Temp = Head;
    while (Temp->next != Head) {
        Temp = Temp->next;
    } 
    // Temp is now the Tail

    // 7. Set NN->prev = Temp (Tail)
    NN->prev = Temp;
    
    // 8. Set NN->next = Head
    NN->next = Head;
    
    // 9. Set Temp->next = NN
    Temp->next = NN;
    
    // 10. Set Head->prev = NN
    Head->prev = NN;
    
    // 11. return Head
    return Head;
}

// --- Delete Front ---
NODE deleteFrontCDLL_V2(NODE Head) {
    // 1. if Head == NULL then
    if (Head == NULL) {
        printf("List Empty\n"); 
        return NULL;
    }
    
    // 3. if Head-¿next == Head then (Single node list)
    if (Head->next == Head) {
        // 4. Free Head return NULL
        free(Head);
        return NULL;
    }
    
    // 5. Set Temp = Head
    NODE Temp = Head;
    
    // Find the Tail by traversing: O(n) operation
    NODE Tail = Head;
    while (Tail->next != Head) {
        Tail = Tail->next;
    }
    
    // 9. Set Head = Head->next
    Head = Head->next;
    
    // 10. Set Head->prev = Tail
    Head->prev = Tail;
    
    // 11. Set Tail->next = Head
    Tail->next = Head;
    
    // 12. Free Temp
    free(Temp);
    
    // 13. return Head
    return Head;
}

// --- Delete Rear ---
NODE deleteRearCDLL_V2(NODE Head) {
    // 1. if Head == NULL then
    if (Head == NULL) {
        printf("List Empty\n"); 
        return NULL;
    }
    
    // 3. if Head-next == Head then (Single node list)
    if (Head->next == Head) {
        // 4. Free Head return NULL
        free(Head);
        return NULL;
    }
    
    // Traverse to the node before the Tail (Temp)
    NODE Temp = Head;
    while (Temp->next->next != Head) {
        Temp = Temp->next;
    } // Temp is now the node before the Tail

    // 8. Set Del = Temp->next (Tail node)
    NODE Del = Temp->next;
    
    // 9. Set Temp->next = Head
    Temp->next = Head;
    
    // 10. Set Head->prev = Temp
    Head->prev = Temp;
    
    // 11. Free Del
    free(Del);
    
    // 12. return Head
    return Head;
}


// --- MAIN FUNCTION --- //
int main() {
    NODE Head = NULL;

    printf("Circular Doubly Linked List Demonstration (Without Tail)\n\n");

    // Insert Front (O(n))
    Head = insertFrontCDLL_V2(Head, 10);
    Head = insertFrontCDLL_V2(Head, 20); 
    displayCDLL(Head); // List: 20 <-> 10

    // Insert Rear (O(n))
    Head = insertRearCDLL_V2(Head, 30);  
    displayCDLL(Head); // List: 20 <-> 10 <-> 30

    // Delete Rear (O(n))
    Head = deleteRearCDLL_V2(Head);
    printf("\nAfter deleting rear (30):\n");
    displayCDLL(Head); // List: 20 <-> 10

    // Delete Front (O(n))
    Head = deleteFrontCDLL_V2(Head);
    printf("After deleting front (20):\n");
    displayCDLL(Head); // List: 10
    
    // Delete single node
    Head = deleteFrontCDLL_V2(Head);
    printf("\nAfter deleting single node (10):\n");
    displayCDLL(Head); // List: Empty

    return 0;
}
