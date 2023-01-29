// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 2
// Exercise 1
// Submission code: xxxxx (provided by your TA-s)

//#### Include session ####
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

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

//###### Main program #######
int main() {

    //int i;
    char movement[1];
    char x_pos[5];
    char y_pos[5];

    ROBOT roberto;
    roberto.dir = N;

    printf("Enter the x-coordinate of the robot (Number from 0-99): ");
    scanf("%5s", x_pos);

    printf("Enter the y-coordinate of the robot (Number from 0-99): ");
    scanf("%5s", y_pos);

    int num = atoi(x_pos);
    int num2 = atoi(y_pos);

    roberto.xpos = num;
    roberto.ypos = num2;

    printf("Start position of the robot is x: %d an y: %d. Facing %d \n", roberto.xpos, roberto.ypos, roberto.dir);

    printf("To move the robot, enter 'm' for moving forward and 't' to turn 90 degrees clockwise: ");
    scanf("%s", movement);

    ROBOT * prRoberto = &roberto;

    if (movement[0] == 'm' || movement[0] == 'M') {
        move(prRoberto);
    }else if (movement[0] == 't' || movement[0] == 'T') {
        turn(prRoberto);
    }  

    //print_current_position(prRoberto);
    printf("New position of the robot. x: %d an y: %d. Facing %c ", roberto.xpos, roberto.ypos, roberto.dir);
}

//###### Function Definition #######

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

/* void print_current_position(ROBOT * temp) {
    int direction = temp->dir;
    char * position = "";
    position = check_position(direction);
    printf("New position of the robot. x: %d an y: %d. Facing %d ", temp->xpos, temp->ypos, position);
} */

/* char check_position(int position) {
    char * direction = "";
     char north [5] = "North";
    char east [4] = "East";
    char south [5] = "South";
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
}*/

