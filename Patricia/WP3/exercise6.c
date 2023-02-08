// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 3
// Exercise 6 (ARRAYS AND FILES)
// Submission code: xxxxx (provided by your TA-s)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX 20

// ### Function Declaration #####
void copyString(char *string, char *copyString);

int main(int argc, char *argv[])
{
    /*Write a program that reads in a string with a maximum of 20 characters from the
    keyboard and stores the string in a local string variable. */
    char string [MAX + 1];   //Create a char that will hold 29 characters. We need to add one more because the last character is \0"

    //SIMPLE WAY OF READING THE FILE OR USER INPUT AND SAVING CHAR
    //printf("Enter a string with a maximum of 20 characters: ");
    //printf("Or enter print from a file. Enter the file name in the argument. ")  
    
    //Fgets is used to save a line of text from the file stream and save it on a buffer (string). If we want to read a string from a file or
    //from a normal keyboard input fgets works great as it can read from both.
    //fgets(string, MAX + 1, stdin);  

    //We have an if statement to check if the user entered an input from the keyboard or if a file name was provided in the command line 
    //fileno is used to obtain the file descriptor associated with the stream 
    //isatty is used to check if the file descriptor refers to a terminal or from the keyboard.
    if(isatty(fileno(stdin))){     //If the input comes from the keyboard we print something for the user first
        printf("Enter a string with a maximum of 20 characters: ");
        fgets(string, MAX + 1, stdin);   //Then we save the input in the string char
    }else {
        fgets(string, MAX + 1, stdin);   //if it comes from a file we just save the string input from the file directly in the string char
    }
   
    printf("\nString: %s\n", string);  //Print the string entered by the user from the keyboard or from the text file provided by the terminal
   
    //Copy the string input to another char by using ctrcpy function
    char copyString1 [MAX + 1];      //Create a new char 
    strcpy(copyString1, string);    //Call the function and enter the new char where the input will be copied and the old char
   
    printf("Copied string 1: %s\n", copyString1);    //Print the copied string using strcpy
   
    //Copy the string by send it to a function void copyString and using no library 
    char copyString2 [MAX + 1];   //Create a new char to copy the string 
    copyString(string, copyString2);       //Call the function that will copy the string to the new char. Send both char's as parameters
    printf("Copied string 2: %s\n", copyString2);   //Print the copied string from the function

    return 0;
}

// ### Function Description #####

//Function that copies one string to another by looping through the char string and copying each character to the new char copyString.
void copyString(char *string, char *copyString) {
    for(int i = 0; i <= MAX; i++) {
        copyString[i] = string[i];
    }
}