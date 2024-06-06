#include <stdio.h>

int main() {
    char ch;
    printf("Enter a character: ");
    scanf("%c", &ch);
    printf("The eighth bit is %d\n", (ch >> 7) & 1);
    printf("The seventh bit is %d\n", (ch >> 6) & 1);
    printf("The sixth bit is %d\n", (ch >> 5) & 1);
    printf("The fifth bit is %d\n", (ch >> 4) & 1);
    printf("The fourth bit is %d\n", (ch >> 3) & 1);
    printf("The third bit is %d\n", (ch >> 2) & 1);
    printf("The second bit is %d\n", (ch >> 1) & 1);
    printf("The first bit is %d\n", ch & 1);


    return 0;
}

