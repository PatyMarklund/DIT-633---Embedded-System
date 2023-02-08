#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <unistd.h>

#define MAX_LEN 20

void copyString(char *dest, char *src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int main(int argc, char *argv[]) {
    char input[MAX_LEN + 1];
    char copy1[MAX_LEN + 1];
    char copy2[MAX_LEN + 1];
    if (!isatty(fileno(stdin))) {
        scanf("%20s", input);
    } else {
        printf("Enter a string of up to 20 characters: ");
        scanf("%20s", input);
    }
    strcpy(copy1, input);
    copyString(copy2, input);
    printf("Copied strings using strcpy: %s\n", copy1);
    printf("Copied strings using copyString: %s\n", copy2);
    return 0;
}