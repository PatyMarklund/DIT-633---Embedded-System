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

    if(argc < 2) {         // Check if the user entered at least one argument
        printf("You need to enter the number of shifts to encrypt the text");    // If no argument print this message 
        return 1;     // And exit returnin to the begining
    }

    char userInput[100];    // Initialize the array of char where the user input will be stored
    int shiftKey = atoi(argv[1]);    //Converte the argument entered to an int which will be used as the shift number for the encryption
    const int alphabetSize = 26;     // Initialize the constand of the size of the alphabet 'a' to 'z' = 26 || 'A' to 'Z' = 26

    // Ask user to input a text 
    printf("Enter the text to be encrypted and wait for the result! Continue until your're done and press ctrl+z to finish. \n");  
    
    while (fgets(userInput, sizeof(userInput), stdin) != NULL) {   // While the user inputs text and not a EOF the loop continues to run.
                                                                   // Using fgets function to be able to read the entire input from the user and not only the first string

        for(int i = 0; userInput[i] != '\0'; i++) {     //Loops through the array userinput until it reaches the end \0
            
            if (userInput[i] >= 'a' && userInput[i] <= 'z'){   // Checks if the text inputed is lower case 
                // Shifts the letter at the current index of the userInput string by the shiftKey amount position
                // This equation uses modulo to make sure the number shifting will never exceed the alphabet size 26
                userInput[i] = (userInput[i] - 'a' + shiftKey) % alphabetSize + 'a';   
            }
            else if (userInput[i] >= 'A' && userInput[i] <= 'Z'){   // Checks if the text inputed is upper case
                userInput[i] = (userInput[i] - 'A' + shiftKey) % alphabetSize + 'A';   // Same equation as above but usint the numbers from the upper case alphabet
            }
        }
        printf("\nEncrypted string: %s\n", userInput);   // Print the text result after being encrypted

        printf("Enter the text to be encrypted: \n");    // Print another line for the user to enter a new text in case the while loop condition still met
    }
    return 0;
        
}