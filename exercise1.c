// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023) 
// Work package 1 
// Exercise 1 
// Submission code: xxxxx (provided by your TA-s)

// Define session
//#define _CRT_SECURE_NO_WARNINGS

// Incluse session
#include <stdio.h>

// Main function in the program, no program arguments supported
void main () {

    // Initialize the interger to be used as input from the user
    int userInput;
  
    do {     // Do the following states while the condition is met

        printf("Enter a number from 1 to 5: ");    // User is requested to enter a number

        scanf("%d", &userInput);   // Input from the user is saved in the memory ***

        if (userInput == 1) {
            printf("Monday's child is fair of face\n\n");
        }
        else if (userInput == 2) {
            printf("Tuesday's child is full of grace\n\n");
        }
        else if (userInput == 3) {
            printf("Wednesday's child is full of woe\n\n");
        }
        else if (userInput == 4) {
            printf("Thursday's child has far to go\n\n");
        }
        else if (userInput == 5) {
            printf("Friday's child is loving and giving\n\n");
        }
        else {
            printf("Saturday's child works hard for a living\n\n");
            break;
        }
    } while (userInput >= 1 && userInput <= 5);    // Codition: While the user input is 1, 2, 3, 4 or 5 continue the loop
} 