#include <stdio.h>
#include <math.h>

int main() {
    int i, j, r, c;
    float a[5][5], b[5][5], det = 0;
    int hasSecond = 0;

    printf("Enter number of rows (max 5): ");
    scanf("%d", &r);
    printf("Enter number of columns (max 5): ");
    scanf("%d", &c);

    printf("Enter elements of the matrix:\n");
    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++)
            scanf("%f", &a[i][j]);

    printf("Do you want to compare with another matrix? (1-Yes / 0-No): ");
    scanf("%d", &hasSecond);
    if (hasSecond) {
        printf("Enter elements of second matrix:\n");
        for (i = 0; i < r; i++)
            for (j = 0; j < c; j++)
                scanf("%f", &b[i][j]);
    }

    int isSquare = (r == c);
    int isZero = 1, isIdentity = 1, isDiagonal = 1, isScalar = 1;
    int isUpper = 1, isLower = 1, isSym = 1, isSkew = 1;
    int isRow = (r == 1), isCol = (c == 1), isNull = 1;
    int isEqual = 1, isIdempotent = 1, isNilpotent = 1;

    for (i = 0; i < r; i++)
        for (j = 0; j < c; j++) {
            if (a[i][j] != 0) isZero = 0;
            if (a[i][j] != 0) isNull = 0;
        }

    if (isSquare) {
        for (i = 0; i < r; i++)
            for (j = 0; j < c; j++) {
                if (i != j && a[i][j] != 0) isIdentity = 0;
                if (i != j && a[i][j] != 0) isDiagonal = 0;
                if (i != j && a[i][j] != 0) isScalar = 0;
                if (i > j && a[i][j] != 0) isUpper = 0;
                if (i < j && a[i][j] != 0) isLower = 0;
                if (a[i][j] != a[j][i]) isSym = 0;
                if (a[i][j] != -a[j][i]) isSkew = 0;
                if (i == j && a[i][j] != 1) isIdentity = 0;
            }
        if (isDiagonal) {
            float diagVal = a[0][0];
            for (i = 1; i < r; i++)
                if (a[i][i] != diagVal) isScalar = 0;
        } else isScalar = 0;

        if (r == 2)
            det = a[0][0]*a[1][1] - a[0][1]*a[1][0];
        else if (r == 3)
            det = a[0][0]*(a[1][1]*a[2][2]-a[1][2]*a[2][1])
                - a[0][1]*(a[1][0]*a[2][2]-a[1][2]*a[2][0])
                + a[0][2]*(a[1][0]*a[2][1]-a[1][1]*a[2][0]);

        float prod[5][5] = {0}, sqr[5][5] = {0};
        if (isSquare) {
            for (i = 0; i < r; i++)
                for (j = 0; j < c; j++)
                    for (int k = 0; k < c; k++)
                        prod[i][j] += a[i][k] * a[k][j];

            isIdempotent = 1;
            for (i = 0; i < r; i++)
                for (j = 0; j < c; j++)
                    if (fabs(prod[i][j] - a[i][j]) > 1e-3)
                        isIdempotent = 0;

            for (i = 0; i < r; i++)
                for (j = 0; j < c; j++)
                    if (fabs(prod[i][j]) > 1e-3)
                        isNilpotent = 0;
        }
    } else {
        isIdentity = isDiagonal = isScalar = isUpper = isLower = isSym = isSkew = 0;
    }

    if (hasSecond) {
        for (i = 0; i < r; i++)
            for (j = 0; j < c; j++)
                if (a[i][j] != b[i][j]) isEqual = 0;
    } else isEqual = 0;

    printf("\nMatrix Type(s):\n");
    if (isSquare) printf("Square Matrix\n");
    else printf("Rectangular Matrix\n");
    if (isZero) printf("Zero Matrix\n");
    if (isNull) printf("Null Matrix\n");
    if (isIdentity) printf("Identity Matrix\n");
    if (isDiagonal) printf("Diagonal Matrix\n");
    if (isScalar) printf("Scalar Matrix\n");
    if (isUpper) printf("Upper Triangular Matrix\n");
    if (isLower) printf("Lower Triangular Matrix\n");
    if (isSym) printf("Symmetric Matrix\n");
    if (isSkew) printf("Skew-Symmetric Matrix\n");
    if (isRow) printf("Row Matrix\n");
    if (isCol) printf("Column Matrix\n");
    if (isSquare) {
        if (det == 0) printf("Singular Matrix\n");
        else printf("Non-Singular Matrix\n");
    }
    if (hasSecond && isEqual) printf("Equal Matrix\n");
    if (isIdempotent) printf("Idempotent Matrix\n");
    if (isNilpotent) printf("Nilpotent Matrix\n");

    return 0;
}

