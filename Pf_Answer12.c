#include <stdio.h>

int main() {
    int arr[10], i, j;
    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++)
        scanf("%d", &arr[i]);
    for (i = 0; i < 10; i++) {
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                arr[i] = -1;
                break;
            }
        }
    }
    printf("Updated array:\n");
    for (i = 0; i < 10; i++)
        printf("%d ", arr[i]);
    return 0;
}

