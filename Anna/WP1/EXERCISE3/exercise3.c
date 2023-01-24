// EXERCISE 3: GUESS THE NUMBER GAME
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void guess(int N)
{
    int number, guess, MAX_NUMBER = 0;
    srand(time(NULL));
    number = rand() % N;
    printf("Guess a number between 1 and %d\n", N);
    do
    {
        if (MAX_NUMBER > 9)
        {
            printf("\nYou Loose!\n");
            break;
        }
        scanf("%d", &guess);
        if (guess > number)
        {
            printf("Lower number\n");
            MAX_NUMBER++;
        }
        else if (number > guess)
        {
            printf("Higher number\n");
            MAX_NUMBER++;
        }
        else
            printf("You have guessed %d times, and your guess is correct!\n", MAX_NUMBER);
    } while (guess != number);
}
// Guess the number, the game!
int main()
{
    int N = 100;
    guess(N);
    return 0;
}
