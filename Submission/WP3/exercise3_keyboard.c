// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 3
// Exercise 3 (KEYBOARD SCANNING)
// Submission code: 45100310 (provided by your TA-s)

// C++ code
//Define the pints for the display
#define ROW1 11
#define ROW2 10
#define ROW3 9
#define ROW4 8
#define COL1 7
#define COL2 6
#define COL3 5
#define COL4 4

//##### Initialize Session #####

const int rows = 4;  //Initialize a constant for the display rows
const int cols = 4;  //Initialize a constant for the display columns

//Initialize the 2 dimention array which contains all the chars from the display
//We write the values using '' so we dont print the ASCii character, instead of
//what we actually have in the keypad
const char keys[rows][cols] = {
               {'1','2','3','A'},
               {'4','5','6','B'},
               {'7','8','9','C'},
               {'*','0','#','D'}
               };
               
char rowPins[] = {ROW1, ROW2, ROW3, ROW4};  //Initialize the char holding the pins for the rows
char colPins[] = {COL1, COL2, COL3, COL4};  //Initialize the char holding the pins for the columns

//##### Setup Session #####
void setup () {
  Serial.begin(9600);   //Start serial port
  //Set the row pins as OUTPUT
  pinMode(ROW1, OUTPUT);
  pinMode(ROW2, OUTPUT);
  pinMode(ROW3, OUTPUT);
  pinMode(ROW4, OUTPUT);
  //Set all rows to high. Turn on the pullups
  digitalWrite(ROW1, HIGH);
  digitalWrite(ROW2, HIGH);
  digitalWrite(ROW3, HIGH);
  digitalWrite(ROW4, HIGH);
  //Set the colum pins as input
  pinMode(COL1, INPUT);
  pinMode(COL2, INPUT);
  pinMode(COL3, INPUT);
  pinMode(COL4, INPUT);
}

//###### Start Loop ########

void loop() {
  
  char k = 0; //Initialize char that will hold the char that was pressed in the keypad
      
  //For loop that sets each row pin of the keypad to low to activate the corresponding row
  //Then is loops to each column pins if it reads a low voltage. indicating the button on that row and column was pressed
  for(char i = 0; i < rows; i++){
  	digitalWrite(rowPins[i], LOW); 
    	for(char j = 0; j < cols; j++){
        	if(digitalRead(colPins[j]) == LOW){
            	while(digitalRead(colPins[j])== LOW);  //Waits until the button is released
            	k = keys[i][j];  //Sets to k the corresponding button character
            }
        }
    digitalWrite(rowPins[i], HIGH); //Sets the row back to high before moving to the next row
  }
  
  if(k != 0){   //If K is not 0, which means something was pressed 
   Serial.println(k);   //Then we print the button character
  }
  
  //Set to 20 when testing for better results
  delay(20);   //Set a delay to one second as described on WP3 but the keypad doesnt function in the best way
}