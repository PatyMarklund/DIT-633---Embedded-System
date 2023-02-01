// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 2
// Exercise 1
// Submission code: xxxxx (provided by your TA-s)

#define MAX 10

//#### Include session ####
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <ctype.h>

enum DIRECTION {N,O,S,W}; 
 
typedef struct { 
        int xpos; 
        int ypos; 
        enum DIRECTION dir; 
} ROBOT;

// ##### Function declarations ##### 
void move(ROBOT * temp);  // means that the robot takes one step in the current direction
void turn(ROBOT * temp);  //means that the robot turns 90 degrees clockwise.
void print_current_position(ROBOT * temp);
char check_position(int position);
void get_user_input(ROBOT * temp);
int check_input(char *input);

//###### Main program #######
int main() {

    char movement[MAX];
    ROBOT roberto;
    int user_input;

    while(1) {
        
        get_user_input(&roberto);
        roberto.dir = N;

        printf("Start position of the robot is x: %d an y: %d. Facing %d \n", roberto.xpos, roberto.ypos, roberto.dir);

        printf("To move the robot, enter 'm' for moving forward and 't' to turn 90 degrees clockwise. You can enter as many movements as you like (mmtmt): ");
        scanf("%s", movement);

        ROBOT * prRoberto = &roberto;

        for (int i = 0; movement[i] != '\0'; i++) {
            if (movement[i] == 'm' || movement[i] == 'M') {
                move(prRoberto);
            }else if (movement[i] == 't' || movement[i] == 'T') {
                turn(prRoberto);
            }
        }  

        //print_current_position(prRoberto);
        printf("New position of the robot. x: %d an y: %d. Facing %d \n", roberto.xpos, roberto.ypos, roberto.dir);

        printf("Press 'q' for leaving the program or 'c' to continue: ");
        scanf("%d\n", user_input);
        user_input = getchar();
        getchar();
        if(user_input == 'q' || user_input  == 'Q'){
            break;
        }
        fflush(stdin);
    }
    return 0;
}

//###### Function Definition #######

void get_user_input(ROBOT * temp){
    char x_pos[5];
    char y_pos[5];
    int valid;
    do {
        printf("Enter the x-coordinate of the robot (Number from 0-99): ");
        fgets(x_pos, sizeof(x_pos), stdin); 
    
        if(valid = check_input(x_pos) && strlen(x_pos) <= 3) {
            temp->xpos = atoi(x_pos);
            break;  
        }else {
            printf("Try again! Enter a number from 0 - 99 \n");
        }
    } while (1);
    
    while (1) {
        printf("Enter the y-coordinate of the robot (Number from 0-99): ");
        fgets(y_pos, sizeof(y_pos), stdin); 
    
        if(valid = check_input(y_pos) && strlen(y_pos) <= 3) {
            temp->ypos = atoi(y_pos);
            break;  
        }else {
            printf("Try again! Enter a number from 0 - 99 \n");
        }
    }
}

int check_input(char *input) {
    int valid = 0;
    for (int i = 0; input[i] != '\n'; i++) {
        if(isdigit(input[i]) == 0) {
            valid = 0;
            break;
        }else {
            valid = 1;
        }
    }
    return valid;
}
// means that the robot takes one step in the current direction
void move(ROBOT * temp) {
    if (temp->dir == N) {
        //temp->xpos += 1;
        temp->ypos += 1;
        temp->dir = N;
    }else if (temp->dir == O) {
        temp->xpos += 1;
        //temp->ypos += 1;
        temp->dir = O;
    }else if (temp->dir == S) {
        //temp->xpos += 1;
        temp->ypos -= 1;
        temp->dir = S;
    }else if (temp->dir == W) {
        temp->xpos -= 1;
        //temp->ypos += 1;
        temp->dir = W;
    }
}

//means that the robot turns 90 degrees clockwise.
void turn(ROBOT * temp) {
    if (temp->dir == N) {
        temp->dir = O;
    }else if (temp->dir == O) {
        temp->dir = S;
    }else if (temp->dir == S) {
        temp->dir = W;
    }else if (temp->dir == W) {
        temp->dir = N;
    }
}

void print_current_position(ROBOT * temp) {
    int direction = temp->dir;
    char * position = "";
    position = check_position(direction);
    printf("New position of the robot. x: %d an y: %d. Facing %d ", temp->xpos, temp->ypos, position);
}

char check_position(int position) {
    char * direction = "";
     char north [5] = "North";
    char east [4] = "East";
    //char south [5] = "South";
    char west [4] = "West"; 

    switch (position) {
        case 0:
            direction = "North";
            break;
        case 1:
            direction = "East";
            break;
    }
    return direction; 
}

