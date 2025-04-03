// Matrix multiplication using arrays

#include <stdio.h>
#define ROWS 3
#define COLS 3
int main() {
    printf("Matrix multiplication using arrays\n\n");
    int matrix1[ROWS][COLS] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int matrix2[ROWS][COLS] = {{6, 9, 2}, {5, 1, 4}, {3, 4, 1}};
    int result[ROWS][COLS];
    int i, j;
    // Perform matrix multiplication
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            result[i][j] = matrix1[i][j] * matrix2[i][j];
        }
    }
    // Print the matrices and result
    printf("Matrix 1:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }
    printf("Matrix 2:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }
    printf("Resultant Matrix (Product):\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}