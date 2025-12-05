// --- Circular Doubly Linked List (CDLL) -- //

#include <stdio.h>
#include <stdlib.h>

// Structure of a Node
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} *Node; // 'Node' is now a pointer to struct Node

// 

// --- Create a Node ---
Node createNode(int data) {
    Node newNode = (Node)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("No Memory\n");
        exit(1);
    }
    
    newNode->data = data;
    newNode->prev = newNode; 
    newNode->next = newNode; 
    
    return newNode;
}

// --- Insert Front ---
Node insertFront(Node Head, int data) {
    Node newNode = createNode(data);

    if (Head == NULL) {
        return newNode;
    }
    
    // In a Circular Doubly Linked List, Tail is always Head->prev
    Node Tail = Head->prev;

    newNode->next = Head;
    newNode->prev = Tail;
    Tail->next = newNode;
    Head->prev = newNode;
    
    // newNode becomes the new Head
    return newNode;
}

// --- Insert Rear ---
Node insertRear(Node Head, int data) {
    Node newNode = createNode(data);

    if (Head == NULL) {
        return newNode;
    }
    
    Node Tail = Head->prev;

    newNode->prev = Tail;
    newNode->next = Head;
    Tail->next = newNode;
    Head->prev = newNode;
    
    // Head remains the same, newNode is attached to the end
    return Head;
}

// --- Delete Front ---
Node deleteFront(Node Head) {
    if (Head == NULL) {
        printf("List Empty\n");
        return NULL;
    }
    
    Node Tail = Head->prev;
    Node Temp = Head;

    // Only one node in the list
    if (Head == Tail) {
        free(Temp);
        return NULL;
    }
    
    // Update links
    Head = Head->next;
    Head->prev = Tail;
    Tail->next = Head;
    
    free(Temp);
    
    return Head;
}

// --- Delete Rear ---
Node deleteRear(Node Head) {
    if (Head == NULL) {
        printf("List Empty\n");
        return NULL;
    }
    
    Node Tail = Head->prev;

    // Only one node in the list
    if (Head == Tail) {
        free(Tail);
        return NULL;
    }
    
    Node NewTail = Tail->prev;
    
    NewTail->next = Head;
    Head->prev = NewTail;
    
    free(Tail);
    
    // Head does not change
    return Head;
}

// --- Insert at Position ---
Node insertAtPos(Node Head, int pos, int data) {
    if (Head == NULL && pos != 1) {
        printf("Invalid Position: List Empty\n"); 
        return NULL;
    }

    if (pos == 1) {
        return insertFront(Head, data);
    }
    
    Node Temp = Head;
    int count = 1;
    
    // Traverse to the node *before* the desired position (pos-1)
    // Note: We stop if we loop back to Head to avoid infinite loop
    while (count < pos - 1 && Temp->next != Head) {
        Temp = Temp->next; 
        count++;
    }

    // If pos is exactly count + 1, and we are at the last node, it's an insertRear
    if (Temp->next == Head && count == pos - 1) {
          return insertRear(Head, data);
    }

    // Check if valid position (if we wrapped around and count is still less)
    if (count != pos - 1) {
        printf("Invalid Position\n");
        return Head;
    }
    
    Node newNode = createNode(data);
    newNode->next = Temp->next;
    newNode->prev = Temp;
    Temp->next->prev = newNode;
    Temp->next = newNode;

    return Head;
}

// --- Delete at Position ---
Node deleteAtPos(Node Head, int pos) {
    if (Head == NULL) {
        printf("List Empty\n"); 
        return NULL;
    }
    
    if (pos == 1) {
        return deleteFront(Head);
    }
    
    Node Curr = Head;
    int count = 1;
    
    // Traverse to the node *to be deleted* (pos)
    do {
        if (count == pos) break;
        Curr = Curr->next;
        count++;
    } while (Curr != Head);

    // Check if position is valid
    if (count != pos || (Curr == Head && count != 1)) {
        printf("Invalid Position\n"); 
        return Head;
    }

    // Handle deletion of the Tail node (last node)
    if (Curr->next == Head) {
        return deleteRear(Head);
    }

    // Delete node at intermediate position
    Curr->prev->next = Curr->next;
    Curr->next->prev = Curr->prev;
    free(Curr);

    return Head;
}

// --- Traversal (Forward) ---
void display(Node Head) {
    if (Head == NULL) {
        printf("List Empty\n");
        return;
    }
    
    Node Temp = Head;
    printf("List (Forward): ");
    
    do {
        printf("%d <-> ", Temp->data);
        Temp = Temp->next;
    } while (Temp != Head); 
    
    printf("(Head)\n");
}

// --- Traversal (Backward) ---
void reverseDisplay(Node Head) {
    if (Head == NULL) {
        printf("List Empty\n");
        return;
    }
    
    Node Tail = Head->prev; 
    Node Temp = Tail;
    printf("List (Backward): ");
    
    do {
        printf("%d <-> ", Temp->data);
        Temp = Temp->prev;
    } while (Temp != Tail); 
    
    printf("(Tail)\n");
}

// --- Count Nodes ---
int countNodes(Node Head) {
    if (Head == NULL) {
        return 0;
    }
    
    Node Temp = Head;
    int count = 0;
    
    do {
        count++;
        Temp = Temp->next;
    } while (Temp != Head);
    
    return count;
}

// --- Search Element ---
int search(Node Head, int key) {
    if (Head == NULL) {
        printf("Empty List\n"); 
        return -1; 
    }
    
    Node Temp = Head;
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
    Node Head = NULL;

    printf("Circular Doubly Linked List\n");

    // Insertions
    Head = insertFront(Head, 10);
    Head = insertFront(Head, 20); 
    Head = insertRear(Head, 30);  
    Head = insertAtPos(Head, 2, 15); // Insert 15 at pos 2
    
    printf("\nInitial List (20, 15, 10, 30):\n");
    display(Head);
    reverseDisplay(Head);
    printf("Node Count: %d\n", countNodes(Head));

    // Deletions
    // Delete 10 (at pos 3: 20 -> 15 -> **10** -> 30)
    Head = deleteAtPos(Head, 3); 
    printf("\nAfter deleting node at position 3 (10):\n");
    display(Head); 

    // Delete 30 (which is now at the Rear)
    Head = deleteRear(Head); 
    printf("After deleting rear node (30):\n");
    display(Head); 
    
    // Search element
    printf("\nSearching element:\n");
    search(Head, 15);
    
    return 0;
}
