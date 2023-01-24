/*EXERCISE 1: IF-STATEMENTS
Write  a  program  that  reads  in  an  integer  number  between  1  and  5  from  the  keyboard  and  prints  out  one  of
existing five sentences on the console depending on what number was entered. You can invent the sentences
as you want, but each sentence should be unique.

The program continues to ask for a new number and exits if number isn ́t in the interval 1 to 5.*/

#include <stdio.h>

int main()
{
        // Create an integer variable that will store the number we get from the user
    int number;
        // Ask the user to type a number
    printf("Type a number (1-5): \n");
        // Get and save the number the user types
    scanf("%d", &number);
    // output depending of number input
    if (number == 1)
    {
        printf("%d. Mount Everest - 8,848 meters - Nepal and Tibet\n", number);
    }
    else if (number == 2)
    {
        printf("%d. K2 - 8,611 meters - Pakistan and China\n", number);
    }
    else if (number == 3)
    {
        printf("%d. Kangchenjunga - 8,586 meters - Nepal and India\n", number);
    }
    else if (number == 4)
    {
        printf("%d. Lhotse - 8,516 meters - Nepal and Tibet\n", number);
    }
    else if (number == 5)
    {
        printf("%d. Makalu - 8,485 meters - Nepal and Tibet\n", number);
    }
    else 
    {
        if((number < 1) && (number > 6))
        printf("Error: Choose a number between 1-5.\n");
    }
    main();
}
