// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 3
// EXERCISE 5: POINTERS AND ARRAYS
// Submission code: 45100310 (provided by your TA-s)

/* Write a program that creates an array of integers, array[MAX], and then fill it 
with MAX number of random integers from 1 to 99. Let then the program prints out 
the following: */

//Include session
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define session
#define MAX 20
#define MAX_NO 99

int main() {

    int array[MAX];      // Initialize array of MAX (20)
    int *ptr = array;    // Set *Ptr to point to array[MAX]
    int i;               // Counter

    // Generate random with srand, and add time to make them unique each run
    srand(time(NULL));

    // Fill array with (MAX) number of random int, from 1-99
    for (i = 0; i < MAX; i++) {

        // Assign a random value to the i-th element of the array using pointer arithmetic
        // i is the offset to the pointer and indicates which element of the array should be referenced
        // The parentheses are necessary because the precedence of * is higher than the precedence of +
        *(ptr + i) = rand() % MAX_NO + 1;
    }
    
    printf("The value of the address of the array (pointer) is: %p\n", ptr);
    printf("First integer in the array is (array[0]): %d\n", array[0]);
    printf("The last integer in the array is: %d\n", array[MAX - 1]);

    // Size of Int = 4 byte
    printf("The size of an integer (number of bytes) is: %lu\n", sizeof(int));
    // 4 byte * MAX = 20
    printf("The size of the whole array in bytes is: %lu\n", sizeof(array));

    for (i = 0; i < MAX; i++) {
        // Print the value of the i-th element of the array using pointer arithmetic
        printf("Value of array[%d] is: %d\n", i, *(ptr + i));
        // Print the double of the value of the i-th element of the array
        printf("Value of array[%d] multiplied by two is: %d\n", i, (*(ptr + i)) * 2);
    }
    return 0;   // Indicates successful termination
}