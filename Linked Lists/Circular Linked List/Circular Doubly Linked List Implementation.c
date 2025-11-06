// --- Circular Doubly Linked List -- //

#include <stdio.h>
#include <stdlib.h>
#include <limits.h> 

// Structure of a Node — Circular Doubly Linked List
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} *NODE; // NODE is a pointer to struct Node

// Structure to return both Head and Tail pointers
typedef struct {
    NODE head;
    NODE tail;
} CDLL_Pointers; 

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

// --- Insert Front (Version 1: with Tail) ---
CDLL_Pointers insertFrontCDLL(NODE Head, NODE Tail, int data) {
    NODE NN = createNode(data);
    CDLL_Pointers result = {Head, Tail};

    if (Head == NULL) {
        result.head = result.tail = NN;
        return result;
    }
    
    NN->next = Head;
    NN->prev = Tail;
    Tail->next = NN;
    Head->prev = NN;
    result.head = NN;
    
    return result;
}

// --- Insert Rear (Version 1: with Tail) ---
CDLL_Pointers insertRearCDLL(NODE Head, NODE Tail, int data) {
    NODE NN = createNode(data);
    CDLL_Pointers result = {Head, Tail};

    if (Head == NULL) {
        result.head = result.tail = NN;
        return result;
    }
    
    NN->prev = Tail;
    NN->next = Head;
    Tail->next = NN;
    Head->prev = NN;
    result.tail = NN;
    
    return result;
}

// --- Delete Front (Version 1: with Tail) ---
CDLL_Pointers deleteFrontCDLL(NODE Head, NODE Tail) {
    CDLL_Pointers result = {Head, Tail};
    
    if (Head == NULL) {
        printf("List Empty\n");
        result.head = result.tail = NULL;
        return result;
    }
    
    NODE Temp = Head;

    if (Head == Tail) {
        free(Temp);
        result.head = result.tail = NULL;
        return result;
    }
    
    result.head = Head->next;
    result.head->prev = Tail;
    Tail->next = result.head;
    
    free(Temp);
    
    return result;
}

// --- Delete Rear (Version 1: with Tail) ---
CDLL_Pointers deleteRearCDLL(NODE Head, NODE Tail) {
    CDLL_Pointers result = {Head, Tail};
    
    if (Head == NULL) {
        printf("List Empty\n");
        result.head = result.tail = NULL;
        return result;
    }
    
    NODE Temp = Tail;

    if (Head == Tail) {
        free(Temp);
        result.head = result.tail = NULL;
        return result;
    }
    
    result.tail = Tail->prev;
    result.tail->next = Head;
    Head->prev = result.tail;
    
    free(Temp);
    
    return result;
}

// --- Insert at Position (Version 1: with Tail) ---
CDLL_Pointers insertAtPosCDLL(NODE Head, NODE Tail, int pos, int data) {
    CDLL_Pointers result = {Head, Tail};
    
    if (Head == NULL && pos != 1) {
        printf("Invalid Position: List Empty\n"); 
        return result;
    }

    if (pos == 1) {
        return insertFrontCDLL(Head, Tail, data);
    }
    
    NODE Temp = Head;
    int count = 1;
    
    // Traverse to the node *before* the desired position (pos-1)
    while (count < pos - 1 && Temp->next != Head) {
        Temp = Temp->next; 
        count++;
    }

    // Check if we reached the end prematurely
    if (count != pos - 1 && pos > 1) {
        printf("Invalid Position\n");
        return result;
    }
    
    // Insertion is at the last position (Tail), handled by insertRear
    if (Temp == Tail) {
        return insertRearCDLL(Head, Tail, data);
    }

    NODE NN = createNode(data);
    NN->next = Temp->next;
    NN->prev = Temp;
    Temp->next->prev = NN;
    Temp->next = NN;

    return result;
}

// --- Delete at Position (Version 1: with Tail) ---
CDLL_Pointers deleteAtPosCDLL(NODE Head, NODE Tail, int pos) {
    CDLL_Pointers result = {Head, Tail};
    
    if (Head == NULL) {
        printf("List Empty\n"); 
        return result;
    }
    
    if (pos == 1) {
        return deleteFrontCDLL(Head, Tail);
    }
    
    NODE Curr = Head;
    int count = 1;
    
    // Traverse to the node *to be deleted* (pos)
    do {
        if (count == pos) break;
        Curr = Curr->next;
        count++;
    } while (Curr != Head);

    // Check if position is valid
    if (count != pos) {
        printf("Invalid Position\n"); 
        return result;
    }

    // Handle deletion of the Tail node
    if (Curr == Tail) {
        return deleteRearCDLL(Head, Tail);
    }

    // Delete node at intermediate position
    Curr->prev->next = Curr->next;
    Curr->next->prev = Curr->prev;
    free(Curr);

    return result;
}

// --- Traversal (Forward) ---
void displayCDLL(NODE Head) {
    if (Head == NULL) {
        printf("List Empty\n");
        return;
    }
    
    NODE Temp = Head;
    printf("CDLL (Forward): ");
    
    do {
        printf("%d <-> ", Temp->data);
        Temp = Temp->next;
    } while (Temp != Head); 
    
    printf("(Head)\n");
}

// --- Traversal (Backward) ---
void reverseDisplayCDLL(NODE Head) {
    if (Head == NULL) {
        printf("List Empty\n");
        return;
    }
    
    NODE Tail = Head->prev; 
    NODE Temp = Tail;
    printf("CDLL (Backward): ");
    
    do {
        printf("%d <-> ", Temp->data);
        Temp = Temp->prev;
    } while (Temp != Tail); 
    
    printf("(Tail)\n");
}

// --- Count Nodes ---
int countNodesCDLL(NODE Head) {
    if (Head == NULL) {
        return 0;
    }
    
    NODE Temp = Head;
    int count = 0;
    
    do {
        count++;
        Temp = Temp->next;
    } while (Temp != Head);
    
    return count;
}

// --- Search Element ---
int searchCDLL(NODE Head, int key) {
    if (Head == NULL) {
        printf("Empty List\n"); 
        return -1; 
    }
    
    NODE Temp = Head;
    int pos = 1;

    do {
        if (Temp->data == key) {
            printf("Found at position: %d\n", pos); 
            return pos;
        }
        Temp = Temp->next; 
        pos++;
    } while (Temp != Head);

    printf("Not Found\n"); 
    return -1;
}

// --- MAIN FUNCTION --- //
int main() {
    NODE Head = NULL;
    NODE Tail = NULL;
    CDLL_Pointers list_ptrs = {Head, Tail};

    printf("Circular Doubly Linked List\n");

    // Insertions
    list_ptrs = insertFrontCDLL(list_ptrs.head, list_ptrs.tail, 10);
    list_ptrs = insertFrontCDLL(list_ptrs.head, list_ptrs.tail, 20); 
    list_ptrs = insertRearCDLL(list_ptrs.head, list_ptrs.tail, 30);  
    list_ptrs = insertAtPosCDLL(list_ptrs.head, list_ptrs.tail, 2, 15); // Insert 15 at pos 2
    Head = list_ptrs.head; Tail = list_ptrs.tail;
    
    printf("\nInitial List (20, 15, 10, 30):\n");
    displayCDLL(Head);
    reverseDisplayCDLL(Head);
    printf("Node Count: %d\n", countNodesCDLL(Head));

    // Deletions
    // Delete 10 (at pos 3: 20 -> 15 -> **10** -> 30)
    list_ptrs = deleteAtPosCDLL(Head, Tail, 3); 
    Head = list_ptrs.head; Tail = list_ptrs.tail;
    printf("\nAfter deleting node at position 3 (10):\n");
    displayCDLL(Head); 

    // Delete 30 (Tail)
    list_ptrs = deleteRearCDLL(Head, Tail); 
    Head = list_ptrs.head; Tail = list_ptrs.tail;
    printf("After deleting rear node (30):\n");
    displayCDLL(Head); 
    
    // Search element
    printf("\nSearching element:\n");
    searchCDLL(Head, 15);
    
    return 0;
}
