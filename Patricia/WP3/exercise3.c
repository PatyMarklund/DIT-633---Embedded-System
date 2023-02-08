// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 3
// Exercise 3 (Temperatur Meter v 2.0)
// Submission code: xxxxx (provided by your TA-s)

//Include session
#include<LiquidCrystal.h>   // Library used for the display

//Define session
#define multimeter 6
#define RS 12
#define E 11
#define DB7 5
#define DB6 4
#define DB5 3
#define DB4 2

//##### Initialize Session #####

const int temp_sensor = A0; //Initialize the temperature sensor as an int in the analog input 0
LiquidCrystal lcd(RS, E, DB4, DB5, DB6, DB7);  //Initialize the pins connected to the display.

int tempValue = 0;   //Initialize an integer to hold the actaul temperature value

//###### Setup session ########
void setup()
{
  Serial.begin(9600);   //Start serial port
  pinMode(temp_sensor, INPUT);   //Set Analog input 0, temperature sensor as an input
  lcd.begin(16, 2);   //Declare size of display. 16 columns and 2 rows
}

//###### Start Loop ########
void loop()
{
  tempValue = analogRead(temp_sensor);   //Read the analog signal from the temp sensor (A0) and save in the variable
  float voltage = tempValue * (5.019 / 1024.0);  //Convert the analog signal to voltage
  //Multiply the tempValue by the voltage supplied to the sensor (5V) / The maximum value the analog to digital conversion can accept (1024)
  
  //Convert the voltage from the temp sensor to Celcius
  float temperatureC = (voltage - 0.5) * 100;   //Temperature (°C) = (VOUT – 500) / 10
 	
  Serial.print("Temp voltage: "); Serial.println(voltage);
  Serial.print(temperatureC); Serial.println(" degrees C");
  
  delay(500);  //Short delay specified in the assignment
  
  //Using the lcd object created previously we set up in the the display the exact cursor
  //we want to print the result of the measure. First set the cursor and then print the result
  lcd.setCursor(0,0);          //Set in the first column 0 of the first row 0
  lcd.print("Temperature");    //We then write "Temperature" 
  lcd.setCursor(0,1);          //Set in the first column 0 of the second row 1
  lcd.print(temperatureC);     //We then print the value temperature in Celcius
  lcd.setCursor(5,1);          //Set in the 6th column 5 of the second row 1
  lcd.print(char(178));        //Display a char which is equivalent to the degree symbol
  lcd.setCursor(6,1);          //Set in the 7th column 6 of the second row 1
  lcd.print("C");              //We then write "C"
}