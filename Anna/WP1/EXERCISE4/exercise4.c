#include <stdio.h>
#include <stdlib.h>
/* C does not provide direct support for exception handling
errno can be used for a similar purpose*/
#include <errno.h>
#include <string.h>

void dec2Bin(int n, int size)
{
    int binaryNum[size];
    int i = 0;
    // Convert decimal to binary
    while (n > 0)
    {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    // Add padding to binary representation
    int padding = size - i;
    int counter = 0;
    for (int j = 0; j < padding; j++)
    {
        printf("0");
        counter++;
        if (counter % 8 == 0)
        {
            printf(" ");
        }
    }
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binaryNum[j]);
        counter++;
        if (counter % 8 == 0)
        {
            printf(" ");
        }
    }
}

int main(int argc, char *argv[])
{
    int number, size;
    if (argc > 1)
    {
        if (strcmp(argv[1], "-h") == 0)
        {
            printf("This program takes a positive number as an argument and outputs its binary representation.\n");
            return 0;
        }
        char *endptr;
        errno = 0;
        // Convert string argument to int
        number = strtol(argv[1], &endptr, 10);

        /*If any of these conditions are true,
        the program will print an error message
        and exit with a return value of 2*/
        if (errno != 0 || *endptr != '\0' || number < 0)
        {
            printf("Invalid argument. Please enter a positive number.\n");
            return 2;
        }
        // Check argument input and determine binary size
        size = number < 256 ? 8 : (number < 65536 ? 16 : 32);
    }
    else
    {
        printf("Please enter a positive number as an argument.\n");
        return 1;
    }
    // Call function to convert decimal to binary
    dec2Bin(number, size);
    printf("\n");
    return 0;
}