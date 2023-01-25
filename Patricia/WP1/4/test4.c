/* To write a program in C that converts a decimal number to a binary format and uses the smallest possible datatype for the given number, you can use the following steps:

Take user input for the decimal number and store it in a variable of type long (to accept any number between 0 and the maximum value of type long in C for your compiler).
Initialize a variable to store the binary representation of the decimal number and set it to 0.
Use a while loop to repeatedly divide the decimal number by 2 and store the remainder in the binary variable.
Reverse the binary representation and store it in a new variable.
Use a for loop to print the binary representation in 8-bit, 16-bit, or 32-bit format, depending on the size of the binary representation.
 */

#include <stdio.h>
#include <stdlib.h>

long decimal_number;
long binary_number = 0;
long rem, temp;

int main() {
    printf("Enter a decimal number: ");
    scanf("%ld", &decimal_number);

    temp = decimal_number;
    while (temp != 0) {
        rem = temp % 2;
        binary_number = binary_number * 10 + rem;
        temp /= 2;
    }

    // Reverse the binary representation
    temp = binary_number;
    binary_number = 0;
    while (temp != 0) {
        rem = temp % 10;
        binary_number = binary_number * 10 + rem;
        temp /= 10;
    }

    int binary_length = 0;
    temp = binary_number;
    while (temp != 0) {
        temp /= 10;
        binary_length++;
    }

    printf("Binary representation: ");
    for (int i = 0; i < binary_length; i++) {
        rem = binary_number % 10;
        printf("%d", rem);
        binary_number /= 10;
    }
    printf("\n");
    return 0;
}
