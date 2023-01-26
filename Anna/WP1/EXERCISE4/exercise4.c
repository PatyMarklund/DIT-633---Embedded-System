#include <stdio.h>
#include <stdlib.h>
/* C does not provide direct support for exception handling errno can be used for a similar purpose*/
#include <errno.h>
#include <string.h>

// Function to convert decimal number to binary
void dec2Bin(int n, int size)
{
    int binaryNum[size];
    int i = 0;
    /* Convert decimal number 'n' to binary representation 
    by repeatedly dividing by 2 and storing remainders in 'binaryNum' array*/
    while (n > 0)
    {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    /* Add leading zeroes to binary representation of number, 
    if number of digits is less than expected size (checked in main), to ensure desired format*/
    int padding = size - i;
    for (int j = 0; j < padding; j++)
    {
        printf("0");
    }
    /* Print binary representation stored in 'binaryNum' array in reverse order
    to get the correct order of digits*/
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", binaryNum[j]);
    }
}

int main(int argc, char *argv[])
{
    int number, size;
    // Check if an argument has been passed to the program
    if (argc > 1)
    {
        // Check if argument is the help flag "-h"
        if (strcmp(argv[1], "-h") == 0)
        {
            printf("Enter decimal number, and the program will convert it to binary.\n");
            return 0;
        }
        char *endptr;
        errno = 0;
        /*Convert command line argument to long int and store in 'number' using base 10
        (10 for decimal), and set 'endptr' to first invalid char in the string*/
        number = strtol(argv[1], &endptr, 10);

        /*Check if input is valid
        If any of these conditions are true, the program will print an error message
        and exit with a return value of 2*/
        if (errno != 0 || *endptr != '\0' || number < 0)
        {
            /**endptr != '\0': This checks if the pointer "endptr" is not pointing to the null character, 
            which indicates that there were invalid characters in the input string.*/
            printf("Error: Invalid argument. Please enter a positive decimal number.\n");
            return 2;
        }
        // Determine the size of the binary representation based on input using a ternary operator
        size = number < 256 ? 8 : (number < 65536 ? 16 : 32);
    }
    else
    {
        printf("Error: No argument provided. Please enter a positive decimal number.\n");
        return 1;
    }
    // Call function to convert decimal to binary
    dec2Bin(number, size);
    printf("\n");
    return 0;
}
