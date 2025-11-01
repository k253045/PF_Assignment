#include <stdio.h>

int main() {
    int i, j, k;
    float arr[3][3][3];
    int identical12 = 1, identical13 = 1, identical23 = 1;

    printf("Enter elements for a 3󫢫 matrix (27 values):\n");
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            for (k = 0; k < 3; k++) {
                printf("Element [%d][%d][%d]: ", i, j, k);
                scanf("%f", &arr[i][j][k]);
            }

    printf("\n===== Displaying Each Layer =====\n");
    for (i = 0; i < 3; i++) {
        printf("\nLayer %d:\n", i + 1);
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++)
                printf("%8.2f ", arr[i][j][k]);
            printf("\n");
        }
    }

    for (j = 0; j < 3; j++)
        for (k = 0; k < 3; k++) {
            if (arr[0][j][k] != arr[1][j][k]) identical12 = 0;
            if (arr[0][j][k] != arr[2][j][k]) identical13 = 0;
            if (arr[1][j][k] != arr[2][j][k]) identical23 = 0;
        }

    printf("\n===== Layer Similarity Report =====\n");

    if (identical12)
        printf("Layer 1 and Layer 2 are IDENTICAL.\n");
    else
        printf("Layer 1 and Layer 2 are DISTINCT.\n");

    if (identical13)
        printf("Layer 1 and Layer 3 are IDENTICAL.\n");
    else
        printf("Layer 1 and Layer 3 are DISTINCT.\n");

    if (identical23)
        printf("Layer 2 and Layer 3 are IDENTICAL.\n");
    else
        printf("Layer 2 and Layer 3 are DISTINCT.\n");

    if (identical12 && identical13)
        printf("\nAll three layers are IDENTICAL.\n");
    else if (!identical12 && !identical13 && !identical23)
        printf("\nAll three layers are DISTINCT.\n");
    else
        printf("\nSome layers are identical, others are distinct.\n");

    return 0;
}

