// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 5
// Exercise 2
// Submission code: 02023aa (provided by your TA-s)

//Include DHT library to use with the sensor on the real board
#include "DHT.h"

//Temperature range variables. The range was changed so we could have a smaller range and be able
//to present to the TA and make the video
#define temp_min 0        //between -40 to 0 degrees
#define temp_max_15 15    //between 1 to 15 degrees
#define temp_max_20 20    //between 26 to 20 degrees
#define temp_max_25 25    //between 51 to 25 degrees
#define temp_max 28      //above 28 degrees

//Define session for the sensor temperature
#define DHTPIN 2          //Define the pin the sensor is connected
#define DHTTYPE DHT11     //Define the type of sensor 

DHT dht(DHTPIN, DHTTYPE);     //Create a dht object and send the pin and type of sensor

//Temperature storage variable in celcius
float temperatureC;

void setup(){
  Serial.begin(9600); 
  dht.begin();    //Initialize the dht library
  //set pins as outputs for the LED's ports in the register (13, 12, 11, 10 and 9) 
  DDRB = B00111110;
}
  
void loop(){ 

  PORTB = B00000000;     //Reset all the LED
    
  measureTemp();    //Call method to calculate temperature
  
  //Check range of the temperature and set the LED's to on according to the range defined
  if(temperatureC <= temp_min){  //If temperature below 0 nothing happens
    Serial.println("Nothing happens");
  }else if(temperatureC > temp_min && temperatureC < temp_max_15){  //If temp between 1 and 14
    PORTB = B00100000;                     //Set red LED to on             
  }else if (temperatureC <= temp_max_20){  //If temp between 15 and 20
    PORTB = B00110000;                     //Set red and white LED's to on
  }else if (temperatureC <= temp_max_25){  //If temp between 21 and 25
    PORTB = B00111000;                     //Set red, white and yellow LED's to on
  }else if (temperatureC <= temp_max){     //If temp between 26 and 28
    PORTB = B00111100;                     //Set red, white, yellow and blue LED's to on
  }else if (temperatureC > temp_max){      //If temp higher than 28
    PORTB = B00111110;                     //Set all LED's to on 
  }
  delay(1000);
}
    
//Function to measure the temperature
void measureTemp() {
  //The library makes the calculation and we store the temperature in Celcius in our variable
  temperatureC = dht.readTemperature();
  Serial.print(temperatureC); Serial.println(" degrees C");
}


