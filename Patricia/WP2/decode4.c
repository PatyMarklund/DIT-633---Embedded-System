#include <stdio.h> 
#include <stdlib.h> 

int main(int argc, char *argv[]) {
    unsigned int hex_value;

    /* char * endstr;
    long hex_value = strtol(argv[1], NULL, 16);
    if (*endstr != '\0') {
        printf("Error: Invalid hexadecimal number\n");
        return 1;
    } */
    int result = sscanf(argv[1], "%x", &hex_value);  //Parse the provided string from the argument to the int hex_value
    if (result != 1){
        printf("You didnt enter an argument or that was higher than FF \n");
        return 1;
    }
    printf("%d\n", result);

    printf("number %d\n", hex_value);

    int engine_on = 0;
    int gear_pos = 0;
    int key_pos = 0;
    int brake1 = 0;
    int brake2 = 0;
    
    // 171 = 10101011 

    engine_on = (hex_value & 0b10000000) >> 7; //10101011 & 10000000 = 10000000
    gear_pos = (hex_value & 0b01110000) >> 4;  //10101011 & 01110000 = 00100000
    key_pos = (hex_value & 0b00001100) >> 2;   //10101011 & 00001100 = 00001000
    brake1 = (hex_value & 0b00000010) >> 1;    //10101011 & 00000010 = 00000010
    brake2 = (hex_value & 0b00000001);         //10101011 & 00000001 = 00000001

    printf("Hexadecimal value: %X\n\n", hex_value);

    printf("Name\t\t Value \n");
    printf("------------------------------\n");
    printf("engine_on\t %d \n", engine_on);
    printf("gear_pos\t %d \n", gear_pos);
    printf("key_pos\t\t %d \n", key_pos);
    printf("brake1\t\t %d \n", brake1);
    printf("brake2\t\t %d \n", brake2);
    return 0;
}
