#include <stdio.h>

int main() {
    int arr[10], i, num, count = 0;
    printf("Enter 10 numbers:\n");
    for (i = 0; i < 10; i++)
        scanf("%d", &arr[i]);
    printf("Enter number to search: ");
    scanf("%d", &num);
    for (i = 0; i < 10; i++)
        if (arr[i] == num)
            count++;
    if (count > 0)
        printf("Number %d occurred %d times.\n", num, count);
    else
        printf("Number not found.\n");
    return 0;
}

