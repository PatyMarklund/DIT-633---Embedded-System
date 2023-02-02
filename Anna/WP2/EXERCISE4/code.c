#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check no. of argument (passed as strings), shall be program + 5 arguments
    if (argc != 6)
    {
        //if not, prints an error message and returns 1
        printf("Error: Invalid number of arguments\n");
        return 1;
    }
    /* Command line argument passed to the program(argv[x],
    from string --> int, stored in the variable */

    // atoi() converts a character string to an integer value
    int engine_on = atoi(argv[1]);  // 2nd argument, stored in the integer variable engine_on
    int gear_pos = atoi(argv[2]);   // 3nd argument, stored in the integer variable gear_pos
    int key_pos = atoi(argv[3]);    // 4nd argument, stored in the integer variable key_pos
    int brake1 = atoi(argv[4]);     // 5nd argument, stored in the integer variable brake1
    int brake2 = atoi(argv[5]);     // 6nd argument, stored in the integer variable break2

    // Checks if the values of the 5 arguments are within the specified range
    if (engine_on < 0 || engine_on > 1 ||   // 1 bit
        gear_pos < 0 || gear_pos > 4 ||     // 3 bits
        key_pos < 0 || key_pos > 2 ||       // 2 bits
        brake1 < 0 || brake1 > 1 ||         // 1 bit
        brake2 < 0 || brake2 > 1)           // 1 bit = tot. 8 bits
    {
        // If not, prints an error message and returns 1
        printf("Error: Invalid argument value\n");
        return 1;
    }
    /* Packs the values of the 5 arguments into a single unsigned char,
    called packed using bit shifting and bitwise OR operations */
    unsigned char packed =
        (engine_on << 7) | // shifted left by 7, multiplies 128, MSB = Most Significant Bit
        (gear_pos << 4) |  // shifted left by 4, multiplies 16
        (key_pos << 2) |   // shifted left by 2, multiplies 4
        (brake1 << 1) |    // shifted left by 1, multiplies 2
        brake2;            // set to value of brake2, Bit no 0, LSB = Least Significant Bit

    // For controll - to be removed. 
    printf("controll: %d\n", packed);

    // Print as a 2-digit hexadecimal number using printf with format specifier %02X
    printf("%02X\n", packed);

    // Code returns 0 to indicate successful execution
    return 0;
}
