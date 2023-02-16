// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 4
// EXERCISE 4: LISTS
// Submission code: xxxxxxxxx (provided by your TA-s)

#include <stdio.h>
#include <stdlib.h>

#define MAX 70
#define ERROR_MSG "Error: Invalid input"

// Note: all sub tasks in this exercise (searching and sorting) should be
// implemented and tested in the same program.

// Function declaration
int search_number(int number, int tab[], int size);
void sort(int tab[], int size);

int main()
{
    // Initializing an array of integers
    int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};

    // Definition of "size" as length of the array "test" by dividing
    // the total size of "test" with the size of single element of "test".
    int size = sizeof(test) / sizeof(test[0]);
    int number;
    char input[100];

    // Prompt to input a number between 1 and 70
    printf("Write a number (1-70): \n");
    while (1)
    {
        // Reading user input with fgets and storing it in "input" string
        fgets(input, sizeof(input), stdin);

        // If user input can be successfully converted to an integer "number" and "number" is within the range of 1 and 70, break from the loop
        if (sscanf(input, "%d", &number) == 1 && number >= 1 && number <= MAX)
        {
            break;
        }
        // If user input is not a valid integer within the range of 1 and 70, print ERROR_MSG
        printf("%s\n", ERROR_MSG);
        // Prompt again to input a number between 1 and 70
        printf("Write a number (1-70): \n");
    }

    // Call the search_number function and store the returned value in "index"
    int index = search_number(number, test, size);

    // If the search_number function returns a value other than -1, print the index of "number" in the array "test"
    if (index != -1)
    {
        printf("The index of %d in the array is %d\n", number, index);
    }
    // If the search_number function returns -1, print "number is not in the array"
    else
    {
        printf("%d is not in the array.\n", number);
    }

    // Calling the sort function to sort the array in ascending order
    sort(test, size);
    // Print the sorted array "test"
    printf("The sorted array is: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", test[i]);
    }
    printf("\n");
    // Return 0 to indicate successful termination of main function
    return 0;
}

int search_number(int number, int tab[], int size)
{
    // Loop through the array to find the index of the number
    for (int i = 0; i < size; i++)
    {
        // If the current element is equal to "number", return the index "i"
        if (tab[i] == number)
        {
            return i;
        }
    }
    return -1;
}

void sort(int tab[], int size)
{
    // Bubble sort implementation
    // Loop through the array to sort the elements
    for (int i = 0; i < size - 1; i++)
    {
        // Finding the minimum element in the remaining unsorted array
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (tab[j] < tab[minIndex])
            {
                // Store the index of the current minimum element
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first unsorted element
        int temp = tab[i];
        tab[i] = tab[minIndex];
        tab[minIndex] = temp;
    }
}
