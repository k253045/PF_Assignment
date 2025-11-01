#include <stdio.h>

int main() {
    int r1, c1, r2, c2;
    float A[3][3], B[3][3], C[3][3] = {0};
    int i, j, k;

    printf("Enter rows and columns of first matrix (max 3x3): ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix (max 3x3): ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("\nMatrix multiplication not possible. Columns of A must equal rows of B.\n");
        return 0;
    }

    printf("\nEnter elements of first matrix (A):\n");
    for (i = 0; i < r1; i++)
        for (j = 0; j < c1; j++)
            scanf("%f", &A[i][j]);

    printf("\nEnter elements of second matrix (B):\n");
    for (i = 0; i < r2; i++)
        for (j = 0; j < c2; j++)
            scanf("%f", &B[i][j]);

    for (i = 0; i < r1; i++)
        for (j = 0; j < c2; j++)
            for (k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];

    printf("\nMatrix A:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++)
            printf("%8.2f ", A[i][j]);
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++)
            printf("%8.2f ", B[i][j]);
        printf("\n");
    }

    printf("\nResultant Matrix (A × B):\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++)
            printf("%8.2f ", C[i][j]);
        printf("\n");
    }

    return 0;
}

