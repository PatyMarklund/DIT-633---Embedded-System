// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 4
// EXERCISE 4: LISTS
// Submission code: xxxxxxxxx (provided by your TA-s)

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

int search_number(int number, int *tab, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (*(tab + i) == number)
        {
            printf("Number found at index: %d\n", i);
            return i;
        }
    }
    printf("Number not found\n");
    return -1;
}

void bubbleSort(int size, int *tab)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (*(tab + j) > *(tab + j + 1))
            {
                int temp = *(tab + j);
                *(tab + j) = *(tab + j + 1);
                *(tab + j + 1) = temp;
            }
        }
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
