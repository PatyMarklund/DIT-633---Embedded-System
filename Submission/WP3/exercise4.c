// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 3
// Exercise 4 (KEYBOARD SCANNING V 2.0)
// Submission code: 45100310 (provided by your TA-s)

//Include keyypad library
#include <Keypad.h>

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

byte rowPins[rows] = {ROW1, ROW2, ROW3, ROW4};  //Initialize the byte holding the pins for the rows
byte colPins[cols] = {COL1, COL2, COL3, COL4};  //Initialize the byte holding the pins for the columns

//Initialize the 2 dimention array which contains all the chars from the display
//We write the values using '' so we dont print the ASCii character, instead of
//what we actually have in the keypad
const char keys[rows][cols] = {
               {'1','2','3','A'},
               {'4','5','6','B'},
               {'7','8','9','C'},
               {'*','0','#','D'}
               };
//Initialize the keypad object and call the method that maps the keypad to the pins. Using the 
//2 dimention array keys as a picture of the keyboard. rowPins and colPins as the pins from arduino
//And rows and cols that specify the number of rows and column in the keypad
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);


//##### Setup Session #####
void setup()
{  
  Serial.begin(9600);  //Start serial port
}

//###### Start Loop ########
void loop()
{
  //Call a function getkey from the keypad object, that returns the key that was pressed in the keypad 
  char key = keypad.getKey();  //Store in the char key 
  
  if(key != 0){    //Check if a key was pressed. If key is not 0, means something was pressed
    Serial.println(key);  //Then we print the button character
  }
  
  //Set to 20 when testing for better results
  delay(20);   //Set a delay to one second as described on WP3 but the keypad doesnt function in the best way
}