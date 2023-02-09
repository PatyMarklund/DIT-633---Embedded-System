// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 3
// Exercise 6 (ARRAYS AND FILES)
// Submission code: 45100310 (provided by your TA-s)

/* Write a program that reads in a string with a maximum of 20 characters from
the keyboard and stores the string in a local string variable. */

//Include session
#include <stdio.h>
#include <string.h>
#include <unistd.h>

//Define session
#define MAX 20  // Holds 20 characters plus a null terminator
#define ERROR_MSG1 "Error: Failed to read input from keyboard"
#define ERROR_MSG2 "Error: Failed to read input from file or empty file"
#define ERROR_MSG3 "Error: Input string can not be empty"

// Function declaration
void copyString(char *destination, char *source);

int main()
{
    char stringInput[MAX +1];   //Strhing that will store the input entered by the text file or by the user on the keyboard
    char stringCopied[MAX +1];   //String that will store the string copied from the first string

    // Check if input is from keyboard or file
    // isatty() is a function that returns 1 if the fd - (file descriptor) refers to a terminal.
    if (isatty(0))
    {
        // Input is from keyboard
        printf("Enter a string (max 20 characters): ");
        if (fgets(stringInput, MAX +1, stdin) == NULL)
        {
            printf( ERROR_MSG1 "\n");
            return 1;
        }
    }
    else
    {
        // Input is from file
        if (fgets(stringInput, MAX +1, stdin) == NULL)
        {
            printf( ERROR_MSG2 "\n");
            return 1;
        }
    }
    // Remove the newline character from the string
    stringInput[strcspn(stringInput, "\n")] = '\0';
    // Check if input string is empty
    if (strlen(stringInput) == 0)
    {
        printf(ERROR_MSG3 "\n");
        return 1;
    }
    // Use strcpy to copy string
    strcpy(stringCopied, stringInput);

    // Use custom function to copy string
    copyString(stringCopied, stringInput);

    printf("Copied string (strcpy): %s\n", stringCopied);
    printf("Copied string (copyString): %s\n", stringCopied);

    return 0;
}

// Function definition
void copyString(char *newCopy, char *source)
{
    int i;
    // Loop through the source string
    for (i = 0; source[i] != '\0'; i++)
    {
        // Copy each character from source to destination
        newCopy[i] = source[i];
    }
    // Add null terminator to the destination string
    // determines end of the string
    newCopy[i] = '\0';
}