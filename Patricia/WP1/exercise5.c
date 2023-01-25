// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023) 
// Work package 1 
// Exercise 5 
// Submission code: xxxxx (provided by your TA-s)

#include <stdio.h> 
#include <stdlib.h> 
 
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

void create_random(int *tab) {
    //You need to create an array of integers (table [MAX 100]) where MAX 100 is the number of random numbers between 0 and MAXNUMBER 20
    for (int i = 0; i < MAX; i++) {
        tab[i] = rand() % MAXNUMBER;
        printf("%d\t ", tab[i]);
    }
    printf("\n");
}

void count_frequency(int *tab, int *freq ){
    // Then you should write a function that for each possible number between 0 – MAXNUMBER 
    // calculates how many times the number exists in the array. The result is then stored in a new array (frequency []).
    int count = 0;         // Interger to retain the count

    for (int i = 0; i < MAXNUMBER; i++) {
        for (int j = 0; j < MAX; j++){
            if (tab[j] == i) {
                count++;
            }
        }
        freq[i] = count;
        //printf("Intergers that repeat: %d at this amount of time: %d\n", i, freq[i]);
        count = 0;
    }
    printf("\n");
}

void draw_histogram(int *freq ){
    //write a function that takes the array frequency [] as a parameter and draws a histogram 
    
    for (int i = 0; i < MAXNUMBER; i++) {
        if(!freq[i] == 0){
            printf("%d\t", i);
            for (int j = 0; j < freq[i]; j++){
                printf("x");
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
 
    int table[MAX]; 
    int frequency[MAXNUMBER]; 
 
    printf("Random array: \n");
    create_random(table);
    count_frequency(table, frequency);
    draw_histogram(frequency);

    return 0;
} 