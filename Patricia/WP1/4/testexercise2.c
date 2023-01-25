// Incluse session
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("You need to enter the number of shifts to encrypt the text\n");
        return 1;
    }
    int shiftKey = atoi(argv[1]);
    const int alphabetSize = 26;
    int c;

    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + shiftKey) % alphabetSize + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + shiftKey) % alphabetSize + 'A';
        }
        putchar(c);
    }
    return 0;
}
