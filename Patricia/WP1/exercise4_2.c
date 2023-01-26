
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    unsigned long long binaryNum, hexNum = 0, base = 1;
    int remainder;
    if (argc > 1)
    {
        if (strcmp(argv[1], "-h") == 0)
        {
            printf("This program converts binary to heximal.\n");
            return 0;
        }
        // Read the binary number from the command line argument
        sscanf(argv[1], "%lld", &binaryNum);
    }
    else
    {
        scanf("%lld", &binaryNum);
    }
    //printf("%lld\n",binaryNum);
    //printf("%s\n",argv[1]);

    // Convert the binary number to hexadecimal
    while (binaryNum != 0)
    {
        // Get the last digit of the binary number
        remainder = binaryNum % 10;
        // Add the last digit multiplied by the current base to the hexNum
        hexNum += remainder * base;
        // Increase the base by a factor of 2 for the next digit
        base *= 2;
        // Remove the last digit from the binary number
        binaryNum /= 10;
    }
    //Print hexadecimal representation of 'hexNum' with at least 2 digits and leading zeroes if necessary
    printf("%02llX\n", hexNum);
    return 0;
}