// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023) 
// Work package 1 
// Exercise 1 
// Submission code: 10001001 (provided by your TA-s)

// Incluse session
#include <stdio.h>

// Main function in the program, no program arguments supported
void main () {

    // Initialize the interger to be used as input from the user
    int userInput;
  
    do {     // Do the following states while the condition is met

        printf("Enter a number from 1 to 5: ");    // User is requested to enter a number

        scanf("%d", &userInput);   // Input from the user is saved using scan

        if (userInput == 1) {       // Condition checks if the number entered by the user is equal to 1
            printf("Monday's child is fair of face\n\n");      // If the input was 1 it will print the following
        }
        else if (userInput == 2) {   // Condition checks if the number entered by the user is equal to 2
            printf("Tuesday's child is full of grace\n\n");    // If the input was 2 it will print the following
        }
        else if (userInput == 3) {   // Condition checks if the number entered by the user is equal to 3
            printf("Wednesday's child is full of woe\n\n");    // If the input was 3 it will print the following
        }
        else if (userInput == 4) {   // Condition checks if the number entered by the user is equal to 4
            printf("Thursday's child has far to go\n\n");      // If the input was 4 it will print the following
        }
        else if (userInput == 5) {   // Condition checks if the number entered by the user is equal to 5
            printf("Friday's child is loving and giving\n\n");   // If the input was 5 it will print the following
        }
        else {     // Condition checks if the number entered by the user is none of the above. Not from 1-5
            printf("Saturday's child works hard for a living. THE END!\n\n");    //Prints this message if no input number from 1-5
            break;        // Stop the while loop and exit 
        }
    } while (userInput >= 1 && userInput <= 5);    // Codition: While the user input is 1, 2, 3, 4 or 5 continue the loop
} 