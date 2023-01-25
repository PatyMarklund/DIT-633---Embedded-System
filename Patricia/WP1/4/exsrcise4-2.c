// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023) 
// Work package 1 
// Exercise 5 
// Submission code: xxxxx (provided by your TA-s)

#include <stdio.h> 
#include <stdlib.h>

#define bit1 0b1

// bit2 is the value of the second bit
// the value is 2 = 2*1
#define bit2 0x02

// bit3 is the value of the third bit
// the value is 2^2 = 4
#define bit3 4
#define bit4 8
#define bit5 16
#define bit6 32
#define bit7 64
#define bit8 128

typedef unsigned char byte;

int main(void) {

    printf("Welcome to the binary numbers demonstration! \n");

    unsigned char one_byte;

    one_byte = (char) 20;

    printf("This is the value of one_byte %d\n", one_byte);

    unsigned char another_byte = 0b00010100;

    // let's check if that is the case
    if (one_byte == another_byte)
        printf("1: Comparing bytes: Both bytes have the same number! \n");

    // Let's do the same with the #define
    if (one_byte == (bit3 + bit5))
        printf("2: Comparing a byte to two bits: Both bytes have the same number! \n");

    if (one_byte == (bit3 | bit5))
        printf("3: Comparing a byte to a mask: Both bytes have the same number! \n");

    // so, if we can mask a bit, we can also set it, right?
    unsigned char bit_8_is_set = 0b00000000 | bit6;

    // let's see what we get:
    printf("Value of the 8th bit is: %d\n", bit_8_is_set);

    return 0;
}

