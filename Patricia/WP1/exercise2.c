// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023) 
// Work package 1 
// Exercise 2 
// Submission code: xxxxx (provided by your TA-s)

// Define session
#define _CRT_SECURE_NO_WARNINGS

// Incluse session
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Main function in the program, no program arguments supported
int main (int argc, char *argv[]) {

    if(argc < 2) {
        printf("You need to enter the number of shifts to encrypt the text");
        return 1;
    }

    char userInput[100];
    int shiftKey = atoi(argv[1]);
    const int alphabetSize = 26;

    printf("Enter the text to be encrypted and wait for the result! Continue until your're done and press ctrl+z to finish. \n");
    
    while (fgets(userInput, sizeof(userInput), stdin) != NULL) {   // While the user inputs text and not a EOF the loop continues to run.
                                                                   // Using fgets function to be able to read the entire input from the user and not only the first string

        for(int i = 0; userInput[i] != '\0'; i++) {

            //if (userInput[i] == '\n') continue; //skip newline character
            
            if (userInput[i] >= 'a' && userInput[i] <= 'z'){
                userInput[i] = (userInput[i] - 'a' + shiftKey) % alphabetSize + 'a';
            }
            else if (userInput[i] >= 'A' && userInput[i] <= 'Z'){
                userInput[i] = (userInput[i] - 'A' + shiftKey) % alphabetSize + 'A';
            }
        }
        printf("\nEncrypted string: %s\n", userInput);

        printf("Enter the text to be encrypted: \n");
    }
    return 0;
        
}