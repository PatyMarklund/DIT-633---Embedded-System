// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 4
// Exercise 4: LISTS
// Submission code: 14000401 (provided by your TA-s)

//Include session
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function declaration
int search_number(int number, int *tab, int size);      // a pointer to the first element of the array
void bubbleSort(int size, int *tab);
void print_sorted(int size, int *test);

int main()
{
    // Array of integers to be sorted
    int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};
    // Determine size of array
    int size = sizeof(test) / sizeof(test[0]);
    int number;

    // Prompt user to enter a number between 1 and 70
    printf("Write a number (1-70): ");
    // Read input from user and validate
    if (scanf("%d", &number) != 1 || number < 1 || number > 70)
    {
        // Print error message if user input is invalid
        printf("Invalid input. Please enter a number between 1 and 70.\n");
        return 1;
    }

    // Search for the entered number in the array and print its index
    search_number(number, test, size);
    // Sort the array in ascending order using bubble sort
    bubbleSort(size, test);
    // Print the sorted array
    print_sorted(size, test);

    return 0;
}

// ----------------------------------------------------------------

/*
Compare key to every element of array until the location is found or until the end of array is reached;
return index of element if key is found or -1 if key is not found
*/
int search_number(int number, int *tab, int size)
{
    // Loop through the array
    for (int i = 0; i < size; i++)
    {
        // Check if the current element of the array matches the number
        if (*(tab + i) == number)   // The *(tab + i) notation is equivalent to tab[i]
        {
            // Print the index of the element if it is found
            printf("Number found at index: %d\n", i);
            // Return the index of the element
            return i;
        }
    }
    // If the number is not found in the array, print a message and return -1
    printf("Number not found\n");
    return -1;
}

// Sorts an array of integers in ascending order using bubble sort algorithm
void bubbleSort(int size, int *tab)
{
    // i = outer loop counter, j = inner loop counter
    int i, j, temp, min_unsorted;

    for (i = 0; i < size - 1; i++)
    {
        // Find the index of the minimum element in the unsorted part of the array
        min_unsorted = i;
        for (j = i + 1; j < size; j++)
        {
            if (*(tab + j) < *(tab + min_unsorted))
            {
                min_unsorted = j;
            }
        }

        // Swap the minimum element with the first element in the unsorted part of the array
        // creates a temporary variable called temp and assigns it the value of the ith element in the array tab.
        temp = *(tab + i);

        // assigns the value of the min_unsortedth element in the array tab to the ith element in the array tab
        *(tab + i) = *(tab + min_unsorted);

        // assigns the value of temp (which is the original value of the ith element in the array tab) to the min_unsortedth element in the array tab.
        *(tab + min_unsorted) = temp;
    }
}

// Prints the elements of an array of integers
void print_sorted(int size, int *test)
{
    printf("Sorted array: ");
    // Loop through the array and print each element
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(test + i));
    }
    printf("\n");
}