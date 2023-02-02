
//include section

# include <stdio.h>
# include <stdlib.h>                    // needed to use exit function
# include <string.h>                    // needed to compare two strings

//define section
enum DIRECTION { N, O, S, W };              // defines a new datatype called direction with four possible values
										//N has value 0, O has value 1, S has value 2, W has value 3

#define MIN 0                           //defines a constant macro
#define MAX 99                          //defines a constant macro

typedef struct robots {                 //defines a struct named robot. A struct let us group variables of different type together
	int xpos;
	int ypos;
	enum DIRECTION dir;
};

/* function declaration */

//this function prints out the different values that belongs to the struct robot
void printRobot(struct robots);

//this function sets the direction north and asks the user for starting x and y positions for the robot
void askPosition(struct robots* robotPtr);

//this function takes user input, reads it and calls methods move or turn for each time it is typed
void askInstructions(struct robots* robotPtr);

//the robot moves a step in either x or y positions depending on the set directions
void move(struct robots* robotPtr);

// the robots direction is changed 90 degrees each time the method gets called
void turn(struct robots* robotPtr);

//main program section

int main() {

	//variable declarations      
	struct robots* robotPtr, robot;              //declares a robot of type struct robots with a pointer, robotPtr
	robotPtr = &robot;                           //makes the pointer point to the memory location of the robot
	robot.xpos;
	robot.ypos;
	robot.dir = N;
	
	int quit = 0;

	//program logic

	do {

		askPosition(robotPtr);                  // a pointer is passed as argument. the method recieves memory adress and can update the value directly    
		askInstructions(robotPtr);              // a pointer is passed as argument. the method recieves memory adress and can update the value directly 

		printRobot(robot);                      //passed by value, a copy of the robot will be made and will not affect the original value

		printf("\nPress 'Q' for leaving the program or any other character to continue: ");
		scanf_s("%d", &quit);					// store the value in quit
		quit = getchar();						// stores the value and returns the character as an int
		getchar();								// used to clear the buffer
		if (quit == 'q' || quit == 'Q') {		// checks if the value stored in quit is equal to q/Q, then it breaks the loop and terminate the program
			break;
		}

	

	} while (1);                                //value 1 is always true. Meaning the program will only terminate if the user press x or X when asked

	return 0;
}

//this function takes an argument of type robot, and prints out the different values that belongs to the struct robot
void printRobot(struct robots robot) {

	printf("\nThe X position is: %d", robot.xpos);
	printf("\nThe Y position is: %d", robot.ypos);
	const char* directionsLetter[] = { "N", "O", "S", "W" };						// declare an array of chars that represent the direction values
	printf("\nThe direction of the robot is: %s", directionsLetter[robot.dir]);		//prints the direction of the robot using the dir value of the robot as a letter either, N,S,O W

}

//this function sets the direction north and asks the user for starting x and y positions for the robot. it takes a pointer to the structure robot as argument
void askPosition(struct robots* robotPtr) {

	////variable declarations
	char x_pos[5];
	char y_pos[5];
	int valid;

	////program logic
	robotPtr->dir = N;                      //sets the starting direction of the robot to north through a pointer

	do {
		printf("Enter the x-coordinate of the robot (Number from 0-99): ");			//ask for input
		fgets(x_pos, sizeof(x_pos), stdin);											//read the input from the stdin filestream
			
		if (valid = check_input(x_pos) && strlen(x_pos) <= 3) {						// if the user input is valid (returns a 1 from check_input) and the length is less than 3 (between 0-99) 
			robotPtr->xpos = atoi(x_pos);											// the input will be saved to the robots xpos after being converted from string representation to int
			break;																	//breaks the loop
		}
		else {																		
			printf("Try again! Enter a number from 0 - 99 \n");
		}
	} while (1);																	//continue until a break is reached

	while (1) {																		//continue until a break is reached, the loop works as above
		printf("Enter the y-coordinate of the robot (Number from 0-99): ");
		fgets(y_pos, sizeof(y_pos), stdin);

		if (valid = check_input(y_pos) && strlen(y_pos) <= 3) {
			robotPtr->ypos = atoi(y_pos);
			break;
		}
		else {
			printf("Try again! Enter a number from 0 - 99 \n");
		}
	}
}

//validates that the user input is a number
int check_input(char* input) {									//takes an argument for a pointer to a string, returns an int															
	int valid = 0;												//declares a local variable
	for (int i = 0; input[i] != '\n'; i++) {					//iterate through each charachter 
		if (isdigit(input[i]) == 0) {							//check if each characther is is not a digit,returns non-zero if its a digit and 0 otherwise
			valid = 0;											//set valid to 0 if it is a non-digit
			break;
		}
		else {
			valid = 1;											//set valid to 1 if it is a digit
		}
	}
	return valid;
}




//this function takes user input, reads it and calls methods move or turn for each time it is typed. it takes a pointer to the structure robot as argument
void askInstructions(struct robots* robotPtr) {
	//variable declarations

	char inputMT[21];                               //declares an array of characters with length 21

	//program logic

	printf("\nInput a series of m (move) and t (turn) to move the robot: ");
	scanf_s("%20s", inputMT, 21);                   //stores the input using scanf 

	for (int i = 0; inputMT[i] != '\0'; i++) {      //goes through all characthers from the input until it reaches 0
		if (inputMT[i] == 'm' || inputMT[i] == 'M') {                    //if it finds an m char, 
			move(robotPtr);                         //it will call the method move and pass the pointer as argument in order to update the state of the robot
		}
		else if (inputMT[i] == 't' || inputMT[i] == 'T') {               //if it finds an t char, it will call the method turn
			turn(robotPtr);                         //it will call the method turn and pass the pointer as argument in order to update the state of the robot
		}
	}
}


//updates the robots position based on the current direction. Takes a pointer to struct robot as argument
void move(struct robots* robotPtr) {

	//variable declarations

	enum DIRECTION updatePosition = robotPtr->dir;          // declares and initates a variable to check what position the robot currently has

	//program logic

	switch (updatePosition)                                 //use a switch to update the position accordingly to the current direction
	{
	case N:                                                 //if current direction is north
		robotPtr->ypos = robotPtr->ypos + 1;                 //change the robots ypos -1 to make it move one step north
		break;
	case O:
		robotPtr->xpos = robotPtr->xpos + 1;
		break;
	case S:
		robotPtr->ypos = robotPtr->ypos - 1;
		break;
	case W:
		robotPtr->xpos = robotPtr->xpos - 1;
		break;
	}
}

//updates the robots direction 90 degrees clockwise from on the current direction. Uses a pointer to struct robot as argument
void turn(struct robots* robotPtr) {
	//variable declarations
	enum DIRECTION currentDirection = robotPtr->dir;        // declares and initates a variable to check what position the robot currently has

	//program logic
	switch (currentDirection)                               //use a switch to update the direction 90 degrees from the current direction
	{
	case N:                                                 //if currentDirection is north
		robotPtr->dir = O;                                  //update the new direction to East
		break;
	case O:
		robotPtr->dir = S;
		break;
	case S:
		robotPtr->dir = W;
		break;
	case W:
		robotPtr->dir = N;
		break;
	}
}








