// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 1
// Exercise 3
// Submission code: 10001001 (provided by your TA-s)

// include libraries
#include <stdio.h>  //include libraries for input/output
#include <stdlib.h> //include library for rand/srand etc
#include <time.h>   //include library to seed and creating random numbers using current time

// Define session
#define MAX_NUMBER 5

// ------ Function declarations   ----------

// Function that creates a random number from 1 to 100
int createRandomNumber();

// Main function for guess the number game
int guessNumberGame();

// function to se if the player want to exit the game or play again
int exitOrContinue();

// ------ Main   ----------

int main()
{
    guessNumberGame(); // run function guessNumberGame

    return 0;
}

// function that creates a random number
int createRandomNumber()
{
    srand(time(0));                // use srand to seed a random number generator and time to make it different depending on the computers time
    int number = rand() % 100 + 1; // retrieves a random number between 1 - 100.
    printf("This is the random number: %d\n", number);        // prints the random number created - used only for testing purposes

    return number; // returns the number created
}

// main function for guess the number game
int guessNumberGame()
{

    // declare variables
    int randomNumber = createRandomNumber(); // calls the function to create a random number, and assigns the return value into a local variable

    int guessedNumber;       // declares variable for the guessed number
    int read_number;         // declares an int that stores number of succesfully read values from input guessedNumber
    int numberOfGuesses = 0; // declares and initialize variable for number of guesses, starts at 0.

    do
    { // executes the body atleast once and as long as the while condition is true
        printf("\nGuess the number: ");
        read_number = scanf_s("%d", &guessedNumber); // reads the user input and assigns the value to guessedNumber.
                                                     // also assigns the number of items succesfully read by function inside read_number. If this value is 0, something other than a number has been provided

        if (read_number != 1)
        { // Will only execute this if statement if the input for guessed number was unsuccessful (0).
            printf("\nInvalid input. You have to insert a number between 1-100. Choose if you want to exit or try again!");
            scanf_s("%*s"); // ignores the wrong input and does not store it in any variable
        }

        else if (guessedNumber >= 1 && guessedNumber <= 100)
        { // will only execute this if statement if the input for guessed number is between 1-100.

            if (guessedNumber == randomNumber)
            {                                          // execute if the user guesses the correct number
                numberOfGuesses = numberOfGuesses + 1; // adds a count on number of guesses
                printf("You have guessed %d time(s) and your answer is correct!", numberOfGuesses);
            }
            else if (guessedNumber < randomNumber)
            {                                          // execute if the users guessed a lower number than the random number
                numberOfGuesses = numberOfGuesses + 1; // adds a count on number of guesses
                printf("Your guess is to low!\n");
            }
            else if (guessedNumber > randomNumber)
            {                                          // execute if the user guessed a higher number than the random number
                numberOfGuesses = numberOfGuesses + 1; // adds a count on number of guesses
                printf("Your guess is to high!\n");
            }
        }
        else // if the players input is not betweeen 1-100(but still a number), this print will be executed and the user will be thrown back to the top of this inner do while loop
            printf("\nYour guess needs to be a number between 1 and 100. Guess Again!");

    } while (!(guessedNumber == randomNumber || numberOfGuesses >= MAX_NUMBER || read_number == 0)); // terminates the loop if the user guessed the right number, the user has reached the max limit of guesses or the input is a letter or other value other than a number

    if (numberOfGuesses >= MAX_NUMBER)
    { // will only execute this if statement if the termination depends on max guesses being reached.
        printf("You have reached the maximum number of guesses.");
    }

    exitOrContinue(); // calls this function

    return 0;
}

// function to se if the player want to exit the game or play again
int exitOrContinue()
{
    int exitNumber = 0; // declares and initialize variable for exiting the program
    int read_exit;      // declare an int that stores number of succesfully read values from input exit

start: // start label. Is used by the goto function to know where to go.
    printf("\nPress 1 to exit or any other number to play again: ");
    read_exit = scanf_s("%d", &exitNumber); // Reads the user input and store the value in int exit.
                                            // Also stores the number of items succesfully read by function inside read_exit.

    if (exitNumber == 1)
    {            // execute if the user types 1
        exit(0); // terminate the program
    }
    else if (read_exit != 1)
    { // If this value is 0, something other than a number has been provided
      // execute if statement if the users input is something other than a number
        printf("\nInvalid input. Type a number.");
        scanf_s("%*s"); // ignores the wrong input and does not store it in any variable
        goto start;     // makes the program jump to start: and start again from there
    }
    else
        guessNumberGame(); // calls the function to play the game again

    return 0;
}
