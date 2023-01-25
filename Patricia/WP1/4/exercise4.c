// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023) 
// Work package 1 
// Exercise 5 
// Submission code: xxxxx (provided by your TA-s)
//#define LONG_MAX 

#include <stdio.h> 
#include <stdlib.h>
#include <limits.h>

/* You should write two programs, which convert between numbers in different format. You should make sure that 
these programs can be executed in a pipeline.  

The  programs  should  accept  any  number  between  0  and  the  maximum  value  of  type  long  in  C  for  your 
compiler. 
The program should use the smallest possible datatype for a given, number. For example, if the user inputs 12, 
the program should use treat this as 8 bits and format the output accordingly. If the user inputs 1200, then the 
program should format the output as 16 bits, etc.   
The first program must convert a number in a decimal format to a binary format.  
 dec2bin.exe 12 should result in 00001100 
The second program should convert binary to hexadecimal value. 
 bin2hec.exe 00001111 should result in 0F 
 
You should use the program arguments so that it is possible to use these two programs like this: 
 dec2bin.exe 12 | bin2hec.exe */

//define MAXIMUM_VALUE long 

// User enter a decimal value and that converts to i byte or 8 bits. 12 = 0b 0000 1100

// if the user types 1200 it converts to 2 bytes or 16 bits = 0b 0001 0010 0110 1000  1 2 4 8 - 16 32 64 128 - 256 512 1024 2048

int main(int argc, char* argv[]){
    //convert a number in a decimal format to a binary format.
    //12 should result in 00001100

    unsigned long userInput;
    long reminder[65];
    int i = 0;

    printf("Enter a number between 0 and %ld: ", LONG_MAX);
    scanf("%ld", &userInput);

    if(userInput > LONG_MAX || userInput < 0){
        printf("Invalid input");
        return 1;
    }

    while(userInput > 0){
        reminder[i++] = userInput % 2;
        userInput /= 2;
    }

    int leading_zeroes = 65 - i;
    while(leading_zeroes--)
        printf("0");

    for(int j = i-1; j >= 0; j--){
        printf("%d", reminder[j]);
    }

    return 0;
}