//-- Graph Representation using Adjacency List --//

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

// Structure to represent a node in the adjacency list
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

// Array of adjacency lists
Node* adjList[MAX_VERTICES];

// Variable to track number of vertices
int vertexCount = 0;
// Array to track visited vertices
int visited[MAX_VERTICES];

// Function to create a new node
Node* createNode(int v) {
    
    // Allocate memory for new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    
    return newNode;
}

// Function to initialize graph
void initGraph() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }
}

// Function to add a vertex
void addVertex() {
    
    if (vertexCount >= MAX_VERTICES) {
        printf("Maximum vertices reached\n");
        return;
    }
    
    // Initialize adjacency list for new vertex
    adjList[vertexCount] = NULL;
    printf("Vertex %d added\n", vertexCount);
    vertexCount++;
}

// Function to add an edge (undirected)
void addEdge(int src, int dest) {
    
    if (src >= vertexCount || dest >= vertexCount) {
        printf("Invalid vertices\n");
        return;
    }
    
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = adjList[src];
    adjList[src] = newNode;
    
    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = adjList[dest];
    adjList[dest] = newNode;
}

// Function to delete an edge
void deleteEdge(int src, int dest) {
    
    Node* temp = adjList[src];
    Node* prev = NULL;
    
    // Remove dest from src list
    while (temp != NULL && temp->vertex != dest) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        if (prev == NULL)
            adjList[src] = temp->next;
        else
            prev->next = temp->next;
        free(temp);
    }
    
    temp = adjList[dest];
    prev = NULL;
    
    // Remove src from dest list
    while (temp != NULL && temp->vertex != src) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        if (prev == NULL)
            adjList[dest] = temp->next;
        else
            prev->next = temp->next;
        free(temp);
    }
}

// Function to delete a vertex
void deleteVertex(int v) {
    
    if (v >= vertexCount) {
        printf("Invalid vertex\n");
        return;
    }
    
    // Delete all edges connected to vertex
    for (int i = 0; i < vertexCount; i++) {
        if (i != v) {
            deleteEdge(i, v);
        }
    }
    
    // Free adjacency list of vertex
    Node* temp = adjList[v];
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    
    // Shift adjacency lists
    for (int i = v; i < vertexCount - 1; i++) {
        adjList[i] = adjList[i + 1];
    }
    
    vertexCount--;
}

// Function to reset visited array
void resetVisited() {
    for (int i = 0; i < vertexCount; i++) {
        visited[i] = 0;
    }
}

// Function to perform BFS traversal
void BFS(int start) {
    
    if (start >= vertexCount) {
        printf("Invalid start vertex\n");
        return;
    }
    
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    
    resetVisited();
    
    visited[start] = 1;
    queue[rear++] = start;
    
    printf("BFS Traversal: ");
    
    while (front < rear) {
        
        int current = queue[front++];
        printf("%d ", current);
        
        Node* temp = adjList[current];
        while (temp != NULL) {
            if (!visited[temp->vertex]) {
                visited[temp->vertex] = 1;
                queue[rear++] = temp->vertex;
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// Function to perform DFS traversal
void DFS(int start) {
    
    visited[start] = 1;
    printf("%d ", start);
    
    Node* temp = adjList[start];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFS(temp->vertex);
        }
        temp = temp->next;
    }
}

// Function to print the graph
void printGraph() {
    for (int i = 0; i < vertexCount; i++) {
        
        // Print current vertex
        printf("Vertex %d: ", i);
        
        Node* temp = adjList[i];
        while (temp != NULL) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}


// MAIN FUNCTION //
int main() {
    
    initGraph();
    
    addVertex();
    addVertex();
    addVertex();
    addVertex();
    addVertex();
    
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 4);
    
    printf("\nGraph:\n");
    printGraph();
    
    BFS(0);
    
    resetVisited();
    printf("DFS Traversal: ");
    DFS(0);
    printf("\n");
    
    return 0;
}
