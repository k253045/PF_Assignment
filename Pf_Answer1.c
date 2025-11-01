#include <stdio.h>

void inputMatrix(float a[3][3]);
void displayMatrix(float a[3][3]);
void transposeMatrix(float a[3][3], float t[3][3]);
float determinant(float a[3][3]);
void cofactorMatrix(float a[3][3], float cofactor[3][3]);
void adjointMatrix(float cofactor[3][3], float adj[3][3]);
void inverseMatrix(float adj[3][3], float det, float inv[3][3]);

int main() {
    float a[3][3], t[3][3], cofactor[3][3], adj[3][3], inv[3][3];
    float det;

    printf("Enter the elements of a 3x3 matrix:\n");
    inputMatrix(a);

    printf("\nOriginal Matrix:\n");
    displayMatrix(a);

    transposeMatrix(a, t);
    printf("\nTranspose of Matrix:\n");
    displayMatrix(t);

    det = determinant(a);
    printf("\nDeterminant of Matrix: %.3f\n", det);

    cofactorMatrix(a, cofactor);
    printf("\nCofactor Matrix:\n");
    displayMatrix(cofactor);

    adjointMatrix(cofactor, adj);
    printf("\nAdjoint (Adjugate) Matrix:\n");
    displayMatrix(adj);

    if (det != 0) {
        inverseMatrix(adj, det, inv);
        printf("\nInverse Matrix:\n");
        displayMatrix(inv);
    } else {
        printf("\nInverse does not exist (Determinant = 0)\n");
    }

    return 0;
}

void inputMatrix(float a[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%f", &a[i][j]);
}

void displayMatrix(float a[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf("%8.3f ", a[i][j]);
        printf("\n");
    }
}

void transposeMatrix(float a[3][3], float t[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            t[i][j] = a[j][i];
}

float determinant(float a[3][3]) {
    float det;
    det = a[0][0]*(a[1][1]*a[2][2] - a[1][2]*a[2][1])
        - a[0][1]*(a[1][0]*a[2][2] - a[1][2]*a[2][0])
        + a[0][2]*(a[1][0]*a[2][1] - a[1][1]*a[2][0]);
    return det;
}

void cofactorMatrix(float a[3][3], float cofactor[3][3]) {
    cofactor[0][0] =  (a[1][1]*a[2][2] - a[1][2]*a[2][1]);
    cofactor[0][1] = -(a[1][0]*a[2][2] - a[1][2]*a[2][0]);
    cofactor[0][2] =  (a[1][0]*a[2][1] - a[1][1]*a[2][0]);

    cofactor[1][0] = -(a[0][1]*a[2][2] - a[0][2]*a[2][1]);
    cofactor[1][1] =  (a[0][0]*a[2][2] - a[0][2]*a[2][0]);
    cofactor[1][2] = -(a[0][0]*a[2][1] - a[0][1]*a[2][0]);

    cofactor[2][0] =  (a[0][1]*a[1][2] - a[0][2]*a[1][1]);
    cofactor[2][1] = -(a[0][0]*a[1][2] - a[0][2]*a[1][0]);
    cofactor[2][2] =  (a[0][0]*a[1][1] - a[0][1]*a[1][0]);
}

void adjointMatrix(float cofactor[3][3], float adj[3][3]) {
    transposeMatrix(cofactor, adj);
}

void inverseMatrix(float adj[3][3], float det, float inv[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            inv[i][j] = adj[i][j] / det;
}

