//--- Graph Representation using Adjacency Matrix --//
// Input could be all possible graph types: Weighted / unweighted, Directed / undirected
// Accept user input for number of edges, type of graph

#include <stdio.h>

#define MAX 10 // No. of vertices
#define DIRECTED 1 // 0001 (Bitwise flag for graph type)
#define WEIGHTED 2 // 0010 (Bitwise flag for graph type)

// Structure for adjacency matrix
typedef struct {
    int n; // No. of vertices
    int m; // No. of edges
    int flag; // Bitwise flag: DIRECTED | UNDIRECTED
    int adj[MAX][MAX]; // Adjacency matrix
} Graph;

// Function prototypes
void initGraph(Graph *g);
void readGraph(Graph *g);
void printGraph(Graph *g);

int main(void) {
    Graph G;
    readGraph(&G);
    printGraph(&G);
    return 0;
}

// Function: Initialize adjacency matrix
void initGraph(Graph *g) {
    for (int i =0; i< g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            g->adj[i][j] = 0;
        }
    }
}

// Function: Accept user input for graph
void readGraph(Graph *g) {
    int directed, weighted;
    printf("Enter no. of vertices (n <= %d): ", MAX);
    scanf("%d", &g->n);
    printf("Enter no. of edges (m): ");
    scanf("%d", &g->m);
    
    printf("Directed? (0/1): ");
    scanf("%d", &directed);
    printf("Weighted? (0/1): ");
    scanf("%d", &weighted);
    
    g->flag = (directed ? DIRECTED : 0) | (weighted ? WEIGHTED : 0);
    initGraph(g);
    for (int k = 0; k < g->m; k++) {
        int u, v, w = 1;
        
        if (g->flag & WEIGHTED) {
            scanf("%d %d %d", &u, &v, &w);
        }
        else {
            scanf("%d %d", &u, &v);
        }
        
        if (u >= g->n || v >= g->n || u<0 || v<0) {
            printf("Invalid vertex index, try again\n");
            k--;
            continue;
        }
        g->adj[u][v] = (g->flag & WEIGHTED) ? w : 1;
        // For undirected graphs, mirror the edge
        if (!(g->flag & DIRECTED)) {
            g->adj[v][u] = (g->flag & WEIGHTED) ? w : 1;
        }
    }
}

// Function: Display Graph/Adjacency Matrix
void printGraph(Graph *g) {
    printf("\nGraph Properties:\n");
    printf("Type: %s | %s\n",
    (g->flag & DIRECTED) ? "Directed" : "Undirected",
    (g->flag & WEIGHTED) ? "Weighted" : "Unweighted");
    
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < g->n; i++) {
        for (int j = 0; j < g->n; j++) {
            printf("%3d", g->adj[i][j]);
        }
        printf("\n");
    }
}
