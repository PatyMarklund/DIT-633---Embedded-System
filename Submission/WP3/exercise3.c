// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 3
// Exercise 3 (Temperatur Meter v 2.0) Combination with exercise 2 (TEMPERATURE AND LIGHT METER)
// Submission code: 45100310 (provided by your TA-s)

// C++ code

//Include session
#include<LiquidCrystal.h>   // Library used for the display

//Define session
#define RS 12
#define E 11
#define DB7 5
#define DB6 4
#define DB5 3
#define DB4 2
#define LED_RED 10
#define LED_BLUE 9
#define LED_GREEN 8

//##### Initialize Session #####

const int periodicaly = 500;   //Delay supplied in the assignment
//const float maxLux = 1000;   
const int light_meter = A1;   //Initialize light meter on Analoge input 1
const int temp_sensor = A0; //Initialize the temperature sensor as an int in the analog input 0
LiquidCrystal lcd(RS, E, DB4, DB5, DB6, DB7);  //Initialize the pins connected to the display.

int lightValue = 0;   //Initialize an integer to hold the actual light value
int tempValue = 0;   //Initialize an integer to hold the actual temperature value

//###### Setup session ########
void setup()
{
  Serial.begin(9600);   //Start serial port
  pinMode(temp_sensor, INPUT);   //Set Analog input 0, temperature sensor as an input
  lcd.begin(16, 2);   //Declare size of display. 16 columns and 2 rows
  //Set the pins as output
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(light_meter, INPUT);   //Set light meter pin as input
}

//###### Start Loop ########
void loop()
{  
  //Reading analog signal from the light sensor
  lightValue = analogRead(light_meter);
  int lumen = lightRawToPhys(lightValue);   //Send value to function to calculate the luminosity
  
  //Reading temperature sensor
  tempValue = analogRead(temp_sensor);   //Read the analog signal from the temp sensor (A0) and save in the variable
  float voltage = tempValue * (5.019 / 1024.0);  //Convert the analog signal to voltage
  //Multiply the tempValue by the voltage supplied to the sensor (5V) / The maximum value the analog to digital conversion can accept (1024)
  
  //Convert the voltage from the temp sensor to Celcius
  float temperatureC = (voltage - 0.5) * 100;   //Temperature (°C) = (VOUT – 500) / 10
 	
  Serial.print("Temp voltage: "); Serial.println(voltage);
  Serial.print(temperatureC); Serial.println(" degrees C");
  Serial.print("Luminosity: "); Serial.println(lumen);
  
  //Using the lcd object created previously we set up in the the display the exact cursor
  //we want to print the result of the measure. First set the cursor and then print the result
  lcd.setCursor(0,0);          //Set in the first column 0 of the first row 0
  lcd.print("Temp.");    //We then write "Temperature" 
  lcd.setCursor(0,1);          //Set in the first column 0 of the second row 1
  lcd.print(temperatureC);     //We then print the value temperature in Celcius
  lcd.setCursor(5,1);          //Set in the 6th column 5 of the second row 1
  lcd.print(char(178));        //Display a char which is equivalent to the degree symbol
  lcd.setCursor(6,1);          //Set in the 7th column 6 of the second row 1
  lcd.print("C");              //We then write "C"
  lcd.setCursor(10,0);         //Set the cursor in column 10, row 1
  lcd.print("Light");          //Same as above with the light
  lcd.setCursor(10,1);
  lcd.print(lumen);
  lcd.setCursor(12,1);
  lcd.print(char(37));
  
  //Reset the pins to low
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_BLUE, LOW);
  digitalWrite(LED_GREEN, LOW);
  
  //Check the condition from the table in the assignment.
  //The first condition the LED never goes blue because there is no lower limit for the tempereture on the table
  //The last condition the LED never goes red becausre there is no higher limit for the temperature on the tables
  
  if (lumen == 0) {  //While lummen is 0%  
	if(temperatureC >= -13){         //If temperature is > -12 LED is red
      	digitalWrite(LED_RED, HIGH);
    }else{                             //Otherwise the LED is green
      	digitalWrite(LED_GREEN, HIGH);
  	}
  }
  
  //While the lumen is between 1% and 20%
  if (lumen > 0 && lumen <= 20){
    if (temperatureC < -12) {   //If temperature below -12 then LED blue is on
      digitalWrite(LED_BLUE, HIGH);
    }else if (temperatureC > 0) {   //If temperature higher than 0 LED red is on
      digitalWrite(LED_RED, HIGH);
    }else {                        //Otherwise LED green in on
      digitalWrite(LED_GREEN, HIGH);
    }
  }
  
  //While the lumen is between 21% and 60%
  if (lumen >= 21 && lumen <= 60){  
    if (temperatureC < 0) {         //If temperature is below 0 LED blue is on
      digitalWrite(LED_BLUE, HIGH);
    }else if (temperatureC > 20) {   //If temperature is higher than20 LED red is on
      digitalWrite(LED_RED, HIGH);
    }else {                             //Otherwise LED green in on
      digitalWrite(LED_GREEN, HIGH);
    }
  }
  
  //While the lumen is higher than 60%
  if (lumen >= 61){
    if (temperatureC < 21) {         //If temperature is below 21 then LED blue is on
      digitalWrite(LED_BLUE, HIGH);
    }else {                           //Otherwise LED green in on
      digitalWrite(LED_GREEN, HIGH);
    }
  }
  
  delay(periodicaly);  //Short delay specified in the assignment
}

//Funtion that convertst the light meter value to luminosity
int lightRawToPhys(int raw) {
  int phys = map(raw, 20, 1023, 0, 111);  //Call function map to calculate luminosity
  return phys;    //Return an int with the luminosity value in %
}