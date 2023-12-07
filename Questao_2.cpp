#include <stdio.h>
#include <stdlib.h>

void somaMatrizes(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtraiMatrizes(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void copiaMatriz(int **src, int **dest, int row, int col, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dest[i][j] = src[row + i][col + j];
        }
    }
}

void multiplicaStrassen(int **A, int **B, int **C, int n) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;

    int ***P = (int ***)malloc(7 * sizeof(int **));
    for (int i = 0; i < 7; i++) {
        P[i] = (int **)malloc(newSize * sizeof(int *));
        for (int j = 0; j < newSize; j++) {
            P[i][j] = (int *)malloc(newSize * sizeof(int));
        }
    }

    int ***temp = (int ***)malloc(4 * sizeof(int **));
    for (int i = 0; i < 4; i++) {
        temp[i] = (int **)malloc(newSize * sizeof(int *));
        for (int j = 0; j < newSize; j++) {
            temp[i][j] = (int *)malloc(newSize * sizeof(int));
        }
    }

    int **A11 = A;
    int **A12 = A;
    int **A21 = A;
    int **A22 = A;
    int **B11 = B;
    int **B12 = B;
    int **B21 = B;
    int **B22 = B;

    copiaMatriz(A, A11, 0, 0, newSize);
    copiaMatriz(A, A12, 0, newSize, newSize);
    copiaMatriz(A, A21, newSize, 0, newSize);
    copiaMatriz(A, A22, newSize, newSize, newSize);

    copiaMatriz(B, B11, 0, 0, newSize);
    copiaMatriz(B, B12, 0, newSize, newSize);
    copiaMatriz(B, B21, newSize, 0, newSize);
    copiaMatriz(B, B22, newSize, newSize, newSize);

    subtraiMatrizes(B12, B22, temp[0], newSize);
    multiplicaStrassen(A11, temp[0], P[0], newSize);

    somaMatrizes(A11, A12, temp[1], newSize);
    multiplicaStrassen(temp[1], B22, P[1], newSize);

    somaMatrizes(A21, A22, temp[2], newSize);
    multiplicaStrassen(temp[2], B11, P[2], newSize);

    subtraiMatrizes(B21, B11, temp[3], newSize);
    multiplicaStrassen(A22, temp[3], P[3], newSize);

    somaMatrizes(A11, A22, temp[0], newSize);
    somaMatrizes(B11, B22, temp[1], newSize);
    multiplicaStrassen(temp[0], temp[1], P[4], newSize);

    subtraiMatrizes(A12, A22, temp[2], newSize);
    somaMatrizes(B21, B22, temp[3], newSize);
    multiplicaStrassen(temp[2], temp[3], P[5], newSize);

    subtraiMatrizes(A11, A21, temp[0], newSize);
    somaMatrizes(B11, B12, temp[1], newSize);
    multiplicaStrassen(temp[0], temp[1], P[6], newSize);

    somaMatrizes(P[3], P[4], temp[0], newSize);
    somaMatrizes(temp[0], P[5], temp[1], newSize);
    subtraiMatrizes(temp[1], P[1], temp[2], newSize);
    somaMatrizes(P[2], temp[2], temp[3], newSize);

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = temp[3][i][j];
            C[i][j + newSize] = P[0][i][j];
            C[i + newSize][j] = P[2][i][j];
            C[i + newSize][j + newSize] = temp[1][i][j];
        }
    }

    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < newSize; j++) {
            free(P[i][j]);
        }
        free(P[i]);
    }
    free(P);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < newSize; j++) {
            free(temp[i][j]);
        }
        free(temp[i]);
    }
    free(temp);
}

int main() {
    int n = 3;

    int **A = (int **)malloc(n * sizeof(int *));
    int **B = (int **)malloc(n * sizeof(int *));
    int **resultado = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) {
        A[i] = (int *)malloc(n * sizeof(int));
        B[i] = (int *)malloc(n * sizeof(int));
        resultado[i] = (int *)malloc(n * sizeof(int));
    }

    A[0][0] = 2; A[0][1] = 3; A[0][2] = 4;
    A[1][0] = 5; A[1][1] = 6; A[1][2] = 7;
    A[2][0] = 8; A[2][1] = 9; A[2][2] = 10;

    B[0][0] = 11; B[0][1] = 12; B[0][2] = 13;
    B[1][0] = 14; B[1][1] = 15; B[1][2] = 16;
    B[2][0] = 17; B[2][1] = 18; B[2][2] = 19;

    multiplicaStrassen(A, B, resultado, n);

    printf("Resultado da multiplicacao de matrizes:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(A[i]);
        free(B[i]);
        free(resultado[i]);
    }

    free(A);
    free(B);
    free(resultado);

    return 0;
}
