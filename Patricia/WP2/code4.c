#include <stdio.h> 
#include <stdlib.h> 

int main(int argc, char *argv[]) {
    int engine_on;
    int gear_pos;
    int key_pos;
    int brake1;
    int brake2;
    
    //Needs to check if it is a number as well
    if(argc != 6) {
        printf("You entered too many arguments or none! \n");
        return 1;
    }else {
        engine_on = atoi(argv[1]);
        gear_pos = atoi(argv[2]);
        key_pos  = atoi(argv[3]);
        brake1 = atoi(argv[4]);
        brake2 = atoi(argv[5]);
    }

    // this should be an unsigned char and not an int
    int send_file = 0;

    send_file = send_file | brake2; 
    send_file = send_file | brake1 << 1;
    send_file = send_file | key_pos << 2;
    send_file = send_file | gear_pos << 4;
    send_file = send_file | engine_on << 7;

    printf("\n");
    printf("%X \n", send_file);

    return 0;
}