#include <stdio.h>
#include <stdlib.h>

// Function declaration
int search_number(int number, int *tab, int size);
void bubbleSort(int size, int *tab);
void print_sorted(int size, int *test);

int main()
{
    int test[] = {1, 2, 34, 5, 67, 3, 23, 12, 13, 10};
    int size = sizeof(test) / sizeof(test[0]);
    int number;

    printf("Write a number (1-70): \n");
    scanf("%d", &number);

    search_number(number, test, size);
    bubbleSort(size, test);
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
    // Loop through array
    for (int i = 0; i < size; i++)
    {
        // Compair ptr + current i with number
        if (*(tab + i) == number)
        {
            printf("Number found at index: %d\n", i);
            return i; // Return location of key/number
        }
    }
    printf("Number not found\n");
    return -1; // Key not found
}

void bubbleSort(int number, int *tab)
{
    int i, j, temp, min_unsorted;

    for (i = 0; i < number - 1; i++)
    {
        // Find the index of the minimum key in the unsorted part of the array
        min_unsorted = i;
        for (j = i + 1; j < number; j++)
        {
            if (*(tab + j) < *(tab + min_unsorted))
            {
                min_unsorted = j;
            }
        }

        // Swap the minimum key with the first key in the unsorted part of the array
        temp = *(tab + i);
        *(tab + i) = *(tab + min_unsorted);
        *(tab + min_unsorted) = temp;
    }
}

void print_sorted(int size, int *test)
{
    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(test + i));
    }
    printf("\n");
}
