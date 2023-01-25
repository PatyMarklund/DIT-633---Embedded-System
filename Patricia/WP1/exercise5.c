// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023) 
// Work package 1 
// Exercise 5 
// Submission code: xxxxx (provided by your TA-s)

// Include session
#include <stdio.h> 
#include <stdlib.h> 
 
// Define session
#define MAX 100 // Defines the maximum number of the values in the table 
#define MAXNUMBER 20 // Defines the maximum value of random numbers 
 
 
// ------ Function declarations   ----------  
 
// This function generates a set of random numbers 
// and fills the table *tab with these numbers 
void create_random(int *tab );   
 
// This function takes the *tab of random numbers 
// and creates a table with the frequency counts for these numbers 
void count_frequency(int *tab, int *freq );     
 
// This function takes the frequency count table 
// and draws a histogram of the values in that frequency table 
void draw_histogram(int *freq );  
 
// ------ Function definitions   ---------- 

// This function receive an int pointer to the array tab. This is good cause its not necessary to return the array
// as the modification made to the array will be saved directly using the pointer
void create_random(int *tab) {
    for (int i = 0; i < MAX; i++) {   // Loop throught the array tab which has a size of the defined MAX number
        tab[i] = rand() % MAXNUMBER;    // Create random numbers and store them in the array tab. Module makes sure the number is not higher than the defined MAXNUMBER 
        printf("%d\t ", tab[i]);    // Print the array for display all in the same line with space between each index
    printf("\n");
}

// Then you should write a function that for each possible number between 0 – MAXNUMBER 
// The function calculates how many times the number exists in the array. The result is then stored in a new array (frequency []).
void count_frequency(int *tab, int *freq ){
    
    int count = 0;         // Interger to retain the count

    for (int i = 0; i < MAXNUMBER; i++) {    // Loops through the possible numbers between 0 – MAXNUMBER
        for (int j = 0; j < MAX; j++){       // Loop throught the array tab which has a size of the defined MAX number      
            if (tab[j] == i) {         // Compare the index number from the first loop with the int value of the tab array 
                count++;             // Increase the count everytime the index matches with a value in the tab array
            }
        }
        // Frequency array has size 20 (MAXNUMBER). The array stores the amount of time the index value was matched with the tab array values
        freq[i] = count;  // Save the ammount of times the numbers were matched in the frequency array. 
        count = 0;      // Reset the count to 0 before moving to the next number in the itiration
    }
    printf("\n");
}

// Function that takes the array frequency [] as a parameter and draws a histogram 
void draw_histogram(int *freq ){
    
    for (int i = 0; i < MAXNUMBER; i++) {   // Loops through the array frequency MAXNUMBER
        if(!freq[i] == 0){                 // Check if the value in that current index is not equal 0. 
            printf("%d\t", i);             // Prints the index number
            for (int j = 0; j < freq[i]; j++){     // Loops through the freq[i]. So it will count for each number stored in the current index it will print a character
                printf("x");         // Character 'x' will be printed for the amount of the value held by the index. If index value 2 it will print "xx". 
            }
            printf("\n");
        }
    }
}
 
// ------ Main   -------------------------- 
 
// The main entry point for the program 
//  
// If you choose to go for the optional part 
// Please modify it accordingly 
int main (void){ 
 
    int table[MAX];     // Initialize the array table which has the size of the MAX defined
    int frequency[MAXNUMBER];  // Initialize the array frequency which has the size of the MAXNUMBER defined
 
    printf("Random array: \n");
    create_random(table);         // Call the function and send table array as the parameter
    count_frequency(table, frequency);     // Call the function and send the table and frequency array as the parameter
    draw_histogram(frequency);      // Call the function and send the frequency array as the parameter

    return 0;
} 