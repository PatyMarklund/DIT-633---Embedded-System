// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 5
// Exercise 3 
// Submission code: 02023aa (provided by your TA-s)

//Include DHT library to use with the sensor on the real board
#include "DHT.h"

//Define the pins for the LED's
#define LED_GREEN 13
#define LED_YELLOW 12
#define LED_RED 10

//Define session for the sensor temperature
#define DHTPIN 2          //Define the pin the sensor is connected
#define DHTTYPE DHT11     //Define the type of sensor 

DHT dht(DHTPIN, DHTTYPE);     //Create a dht object and send the pin and type of sensor


const int light_meter = A2;      //Define analog input pin for the light meter 

const int periodicaly = 1000;    //Constant for the delay

float temperatureC;   //Variable that hold temperature values
int lightValue = 0;   //Variable that hold light values

void setup()
{
  Serial.begin(9600);
  dht.begin();     //Initialize DHT library
  //Set up pin modes for LED's and light meter
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(light_meter, INPUT);
}

void loop()
{
  //Reading analog signal from the light sensor
  lightValue = analogRead(light_meter);
  int lumen = lightRawToPhys(lightValue);   //Send value to function to calculate the luminosity
  
  //The library makes the calculation and we store the temperature in Celcius in our variable
  temperatureC = dht.readTemperature();

  //Print temperature and luminosity
  Serial.print(temperatureC); Serial.println(" degrees C");
  Serial.print("Luminosity: "); Serial.println(lumen);
  
  //Reset the pins to low
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, LOW);
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
      digitalWrite(LED_YELLOW, HIGH);
    }else if (temperatureC > 0) {   //If temperature higher than 0 LED red is on
      digitalWrite(LED_RED, HIGH);
    }else {                        //Otherwise LED green in on
      digitalWrite(LED_GREEN, HIGH);
    }
  }
  
  //While the lumen is between 21% and 60%
  if (lumen >= 21 && lumen <= 60){  
    if (temperatureC < 0) {         //If temperature is below 0 LED blue is on
      digitalWrite(LED_YELLOW, HIGH);
    }else if (temperatureC > 20) {   //If temperature is higher than20 LED red is on
      digitalWrite(LED_RED, HIGH);
    }else {                             //Otherwise LED green in on
      digitalWrite(LED_GREEN, HIGH);
    }
  }
  
  //While the lumen is higher than 60%
  if (lumen >= 61){
    //We changed the range in the temperature from 21 to 26 so we could test it in the room temperature
    if (temperatureC < 26) {         //If temperature is below 26 then LED blue is on
      digitalWrite(LED_YELLOW, HIGH);
    }else {                           //Otherwise LED green in on
      digitalWrite(LED_GREEN, HIGH);
    }
  }
  
  delay(periodicaly);  //Short delay specified in the assignment
}

//Funtion that convertst the light meter value to luminosity
int lightRawToPhys(int raw) {
  int phys = map(raw, 0, 1023, 0, 110);  //Call function map to calculate luminosity
  return phys;    //Return an int with the luminosity value in %
}
