// EXERCISE 5: POINTERS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10      // Defines the maximum number of the values in the table
#define MAXNUMBER 5 // Defines the maximum value of random numbers

// This function generates a set of random numbers
// and fills the table *tab with these numbers

// https://stackoverflow.com/questions/22186423/array-of-random-numbers-using-c-program
// https://www.geeksforgeeks.org/generating-random-number-range-c/
// The * symbol is used to declare a pointer variable
void create_random(int *tab)
{
    for (int i = 0; i < MAX; i++) {
        // generate a random number between MINNUMBER and MAXNUMBER
        // function: num = (rand() % (upper – lower + 1)) + lower
        tab[i] = rand() % (MAXNUMBER + 1);
        printf("%d ", tab[i]);
    }
    printf("\n");
}

// This function takes the *tab of random numbers
// and creates a table with the frequency counts for these numbers
void count_frequency(int *tab, int *freq)
{

    for (int i = 0; i < MAXNUMBER; i++){
        freq[i] = 0; // initialize the frequency array to 0
    }
    for (int i = 0; i < MAX; i++)
    {
        freq[tab[i]]++; // increment the frequency of the current number
    }
}

// This function takes the frequency count table
// and draws a histogram of the values in that frequency table
void draw_histogram(int *freq)
{
    for (int i = 0; i <= MAXNUMBER; i++){
            printf("%d   ", i);
            for (int j = 0; j < freq[i]; j++)
            {
            printf("x");
            }
            printf("\n");

    }
}

// The main entry point for the program
int main(void)
{
    int table[MAX], n;
    int frequency[MAXNUMBER];

    srand(time(0));                    // seed the random number generator with the current time
    create_random(table);              // add random numbers to table
    count_frequency(table, frequency); // count the frequency of each number in the table
    draw_histogram(frequency);         // draw the histogram
    return 0;
}
