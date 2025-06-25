#include <stdio.h>
#include <stdlib.h>

// The transpose function as defined earlier
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes);

int main() {
    // Declare variables for matrix dimensions
    int matrixSize, matrixColSize;

    // Take user input for matrix dimensions
    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &matrixSize);
    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &matrixColSize);

    // Dynamically allocate memory for the matrix
    int** matrix = (int**)malloc(matrixSize * sizeof(int*));
    for (int i = 0; i < matrixSize; i++) {
        matrix[i] = (int*)malloc(matrixColSize * sizeof(int));
    }

    // Take user input to fill the matrix
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print the original matrix
    printf("\nOriginal Matrix:\n");
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixColSize; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Variables to store the return values
    int returnSize;
    int* returnColumnSizes;

    // Call the transpose function
    int** transposedMatrix = transpose(matrix, matrixSize, &matrixColSize, &returnSize, &returnColumnSizes);

    // Print the transposed matrix
    printf("\nTransposed Matrix:\n");
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", transposedMatrix[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    for (int i = 0; i < matrixSize; i++) {
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < returnSize; i++) {
        free(transposedMatrix[i]);
    }
    free(transposedMatrix);
    free(returnColumnSizes);

    return 0;
}

// The transpose function implementation
int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int rows = *matrixColSize;
    int cols = matrixSize;

    int** transposed = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        transposed[i] = (int*)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[i][j] = matrix[j][i];
        }
    }

    *returnSize = rows;
    *returnColumnSizes = (int*)malloc(rows * sizeof(int));
    for (int i = 0; i < rows; i++) {
        (*returnColumnSizes)[i] = cols;
    }

    return transposed;
}
