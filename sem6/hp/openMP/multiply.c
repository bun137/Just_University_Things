#include <stdio.h>
#include <omp.h>

#define SIZE 10

void multiply_matrices(int A[SIZE][SIZE], int B[SIZE][SIZE], int C[SIZE][SIZE]) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            C[i][j] = A[i][j] * B[i][j];
        }
    }
}

void print_matrix(int matrix[SIZE][SIZE], const char *name) {
    printf("%s:\n", name);
    printf("+----+----+----+----+----+----+----+----+----+----+\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("|%4d", matrix[i][j]);
        }
        printf("|\n+----+----+----+----+----+----+----+----+----+----+\n");
    }
}

int main() {
    int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];

    // Initialize matrices with some values
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            A[i][j] = i + j;
            B[i][j] = (i + 1) * (j + 1);
        }
    }

    multiply_matrices(A, B, C);

    print_matrix(A, "Matrix A");
    printf("\n");
    print_matrix(B, "Matrix B");
    printf("\n");
    print_matrix(C, "Matrix C (Result of A * B)");

    return 0;
}
