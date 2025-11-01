#include <stdio.h>

int main() {
    char str[100];
    int i = 0, ch;
    printf("Enter characters (input ends when alphabet is entered):\n");
    while (1) {
        ch = getchar();
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == '\n')
            break;
        str[i++] = ch;
    }
    str[i] = '\0';
    printf("Non-alphabetic characters entered:\n%s\n", str);
    return 0;
}

