#include <stdio.h>

int main() {
    float marks, pass[10], fail[10];
    int p = 0, f = 0, i;
    float passSum = 0, failSum = 0;

    printf("Enter quiz marks for students (-1 to stop):\n");
    while (1) {
        scanf("%f", &marks);
        if (marks == -1)
            break;
        if (marks >= 5 && marks <= 10 && p < 10) {
            pass[p++] = marks;
            passSum += marks;
        } else if (marks >= 0 && marks < 5 && f < 10) {
            fail[f++] = marks;
            failSum += marks;
        }
    }

    printf("\nPass Students Marks:\n");
    for (i = 0; i < p; i++)
        printf("%.2f ", pass[i]);
    if (p > 0)
        printf("\nAverage (Pass): %.2f\n", passSum / p);
    else
        printf("\nNo pass marks entered.\n");

    printf("\nFail Students Marks:\n");
    for (i = 0; i < f; i++)
        printf("%.2f ", fail[i]);
    if (f > 0)
        printf("\nAverage (Fail): %.2f\n", failSum / f);
    else
        printf("\nNo fail marks entered.\n");

    return 0;
}

