// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 3
// Exercise 5 (POINTERS AND ARRAYS)
// Submission code: xxxxx (provided by your TA-s)

/*Write a program that creates an array of integers, array[MAX], and then fill it with MAX number of random
integers from 1 to 99.  Let then the program prints out the following:
The value of the address of the array (pointer) is:  xxxxxxxxxx
First integer in the array is (array[0]):  xxxxxxxxxx
The last integer in the array is:  xxxxxxxxxx
The size of an integer (number of bytes) is: xxxxxxxxx
The size of the whole array in bytes is: xxxxxxxxx */

#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#define MAX_NUMBER 99

void displayArray(int *ptrArray);

int main()
{
    int array [MAX];
    int *ptrarray = array;
    int lastInteger;

    for (int i = 0; i < MAX; i++) {
        array[i] = rand() % MAX_NUMBER + 1;
        if(i == MAX){
           lastInteger = array[i];
        }
        printf("%d\t", array[i]);
    }

    printf("\n");
   
    printf("The value of the address of the array (pointer) is: %p\n", ptrarray);
    printf("The value of the address of the array (pointer) is: %p\n", &array);
    printf("First integer in the array is (array[0]): %d\n", *ptrarray);
    printf("First integer in the array is (array[0]): %d\n", array[0]);
    //printf("The last integer in the array is: %d\n", lastInteger);
    printf("The last integer in the array is: %d\n", ptrarray[MAX - 1]);
    //printf("The last integer in the array is: %d\n", array[MAX - 1]);
    printf("The size of an integer (number of bytes) is: %lu\n", sizeof(lastInteger));
    //printf("The size of the whole array in bytes is: %lu\n", sizeof(ptrarray));
    printf("The size of the whole array in bytes is: %llu\n", sizeof(array));
   
    /*The program shall then, by use of a pointer, print out each integer value and
    then print the value multiplied by two. */
   
    //One way of doing
    //displayArray(array);
   
    //Second way of doing:
    int counter = 1;
    for (int i = 0; i <= MAX; i++){
        int result = *(ptrarray + i) * 2;
        printf("Interger nr: %d\t %d\n", counter++, result);
    }
   
    return 0;
}

void displayArray(int *ptrArray){
    int counter = 1;
    for (int i = 0; i <= MAX; i++){
        int result = ptrArray[i] * 2;
        printf("Interger nr: %d\t %d\n", counter++, result);
    }
}