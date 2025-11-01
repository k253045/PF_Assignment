#include <stdio.h>

int main() {
    int i, j, k;
    float arr[3][3][3];
    float layerSum[3] = {0}, totalSum = 0;
    float min, max;
    int totalCount = 0;

    printf("Enter elements for a 3󫢫 matrix (27 values):\n");
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            for (k = 0; k < 3; k++) {
                printf("Element [%d][%d][%d]: ", i, j, k);
                scanf("%f", &arr[i][j][k]);
            }

    min = arr[0][0][0];
    max = arr[0][0][0];

    printf("\n===== 3D MATRIX DATA (3 LAYERS) =====\n");

    for (i = 0; i < 3; i++) {
        printf("\nLayer %d:\n", i + 1);
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                printf("%8.2f ", arr[i][j][k]);
                layerSum[i] += arr[i][j][k];
                totalSum += arr[i][j][k];
                totalCount++;
                if (arr[i][j][k] < min) min = arr[i][j][k];
                if (arr[i][j][k] > max) max = arr[i][j][k];
            }
            printf("\n");
        }
        printf("? Sum of Layer %d = %.2f\n", i + 1, layerSum[i]);
        printf("? Average of Layer %d = %.2f\n", i + 1, layerSum[i] / 9);
    }

    printf("\n===== OVERALL ANALYSIS =====\n");
    printf("Total of all elements: %.2f\n", totalSum);
    printf("Average of all elements: %.2f\n", totalSum / totalCount);
    printf("Minimum element value: %.2f\n", min);
    printf("Maximum element value: %.2f\n", max);

    float layerAvgSum = (layerSum[0] + layerSum[1] + layerSum[2]) / 3;
    printf("Average of layer totals: %.2f\n", layerAvgSum);

    if (layerSum[0] > layerSum[1] && layerSum[0] > layerSum[2])
        printf("Layer 1 has the highest total.\n");
    else if (layerSum[1] > layerSum[0] && layerSum[1] > layerSum[2])
        printf("Layer 2 has the highest total.\n");
    else if (layerSum[2] > layerSum[0] && layerSum[2] > layerSum[1])
        printf("Layer 3 has the highest total.\n");
    else
        printf("Two or more layers share the same highest total.\n");

    return 0;
}

