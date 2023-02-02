// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 2
// Exercise 4_2 (decode)
// Submission code: 11200250 (provided by your TA-s)

//Include session
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check no. of argument, shall be program + 1 argument
    if (argc != 2)
    {
        // If the condition is true, it prints an error message and returns 1
        printf("Error: Invalid number of arguments\n");
        return 1;
    }

    unsigned char packed;
    // Scan argument, convert hexdec string, pass to &packed
    // Format specifier is used to convert a string of hexadecimal digits to an unsigned char

    if (sscanf(argv[1], "%hhX", &packed) != 1)
    {
        printf("Error: Invalid argument value\n");  // if not equal to 1, return error message
        return 1;
    }

    /* Extract binary values from the packed value
    using bitwise AND operation & and bit shift >> */

    int engine_on = (packed & 0x80) >> 7;   //0x80, which is 10000000 in binary, divide value by 2^7
    int gear_pos = (packed & 0x70) >> 4;    //0x70, which is 01110000 in binary, divide (3-bit value) by 2^4
    int key_pos = (packed & 0x0C) >> 2;     //0x0C, which is 00001100 in binary, divide (2-bit value) by 2^2
    int brake1 = (packed & 0x02) >> 1;      //0x02, which is 00000010 in binary, divide value by 2^1
    int brake2 = packed & 0x01;             //0x01, which is 00000001 in binary, result either 0 or 1

    printf("Name Value\n");
    printf("-----------------------------\n");
    printf("engine_on %d\n", engine_on);
    printf("gear_pos %d\n", gear_pos);
    printf("key_pos %d\n", key_pos);
    printf("brake1 %d\n", brake1);
    printf("brake2 %d\n", brake2);

    // The program returns 0 indicating success.
    return 0;
}