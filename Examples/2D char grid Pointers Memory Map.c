// Simulate a memory map using pointer-to-pointer and update values in a 2D char grid dynamically.

#include <stdio.h>
#include <stdlib.h>

void print_grid(char **grid, int R, int C) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int R = 3; // rows
    int C = 4; // columns

    // Step 1: Allocate memory for the grid (rows)
    char **grid = malloc(R * sizeof(char*));
    if (grid == NULL) {
        printf("Memory allocation failed for rows\n");
        return 1;
    }
    // Step 2: Allocate memory for each row (columns)
    for (int i = 0; i < R; i++) {
        grid[i] = malloc(C * sizeof(char));
        if (grid[i] == NULL) {
            printf("Memory allocation failed for row %d\n", i);
            return 1;
        }
    }
    // Step 3: Initialize the grid with some values
    // Example initialization: filling grid with 'A', 'B', 'C', etc.
    char val = 'A';
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            grid[i][j] = val++;
        }
    }
    // Step 4: Update a value in the grid (for demonstration)
    grid[1][2] = 'Z';  // Change a value to 'Z'
    // Step 5: Print the grid
    printf("Grid:\n");
    print_grid(grid, R, C);
    // Step 6: Free the allocated memory (reverse order)
    for (int i = 0; i < R; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}

