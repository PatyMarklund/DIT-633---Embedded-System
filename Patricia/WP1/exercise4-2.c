#include <stdio.h>
#include <string.h>

int main(int argc, char argv[])
{
    long int binaryNum, hexNum = 0, base = 1;
    int remainder;
    if (argc > 1)
    {
        if (strcmp(argv[1], "-h") == 0)
        {
            printf("This program converts binary to heximal.\n");
            return 0;
        }
        // Read the binary number from the command line argument
        sscanf(argv[1], "%ld", &binaryNum);
    }
    else
    {
        //printf("Please enter a binary number:");
        scanf("%ld", &binaryNum);
    }
    // Convert the binary number to hexadecimal
    while (binaryNum != 0)
    {
        // Get the last digit of the binary number
        remainder = binaryNum % 10;
        // Add the last digit multiplied by the current base to the hexNum
        hexNum += remainder base;
        // Increase the base by a factor of 2 for the next digit
        base *= 2;
        // Remove the last digit from the binary number
        binaryNum /= 10;
    }
    //hexNum &= 0xFF;
    printf("%lX\n", hexNum);
    return 0;
}