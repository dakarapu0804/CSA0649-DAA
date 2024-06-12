#include <stdio.h>

void printMatrix(int matrix[][2], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void strassenMatrixMultiplication(int A[][2], int B[][2], int C[][2]) {
    int m1, m2, m3, m4, m5, m6, m7;

    m1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    m2 = (A[1][0] + A[1][1]) * B[0][0];
    m3 = A[0][0] * (B[0][1] - B[1][1]);
    m4 = A[1][1] * (B[1][0] - B[0][0]);
    m5 = (A[0][0] + A[0][1]) * B[1][1];
    m6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    m7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    C[0][0] = m1 + m4 - m5 + m7;
    C[0][1] = m3 + m5;
    C[1][0] = m2 + m4;
    C[1][1] = m1 - m2 + m3 + m6;
}

int main() {
    int A[2][2] = {{12, 34}, {22, 10}};
    int B[2][2] = {{3, 4}, {2, 1}};
    int C[2][2];

    printf("The first matrix is: \n");
    printMatrix(A, 2, 2);

    printf("The second matrix is: \n");
    printMatrix(B, 2, 2);

    strassenMatrixMultiplication(A, B, C);

    printf("Product achieved using Strassen's algorithm: \n");
    printMatrix(C, 2, 2);

    return 0;
}
