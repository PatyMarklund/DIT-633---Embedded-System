// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 4
// Exercise 3 
// Submission code: 14000401 (provided by your TA-s)

#include <Adafruit_NeoPixel.h>   //Include Neopixel ring library

//Define pins in the board
#define buzz 6
#define PIXEL_PIN 5

// Define the pixels on the ring
#define NUMPIXELS 16

//Define variables used in the interrupt
#define CLOCK_TIME 16000000
#define PRESCALE 1024
#define FREQUENCY 8
#define TIMER_MAX 65536
#define TIMER_MIN 257

//Initialize temperature variables
int time = 0;
int tempValue = 0;
float voltage;
int temperatureC;
const int temp_meter = A0;

// Setup the NeoPixel library and tell it how many pixels, and which pin to use to send signals.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

//Array that holds all the temperature range
float temp_max_values[] = {-30.0, -20.0, -10.0, 0.0, 10.0, 20.0, 30.0, 40.0, 50.0, 60.0, 70.0, 80.0, 90.0, 100.0, 110.0, 120.0};

void setup() {
  Serial.begin(9600); 
  //Define pins as output/inputs
  pinMode(buzz, OUTPUT);
  pinMode(temp_meter, INPUT);
  
  pixels.begin();   // This initializes the NeoPixel library.
  pixels.setBrightness(50);   //Set brighteness of the pixels on the ring
  pixels.show();        //Enable the ring to turn on
  
  cli();       //stop interrupts

//set timer1 interrupt at 8Hz
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  //Set incrememt time using constant variables
  time = (CLOCK_TIME / (PRESCALE * FREQUENCY)) - 1;
  
  //The incrememt time should not be higher than Timer_max or lower than Timer_min
  if (time >= TIMER_MAX) {
    time = TIMER_MAX;   //If higher set time to the maximum 65536
  }else if (time <= TIMER_MIN) {
    time = TIMER_MIN;   //If lower than 256 set the time to the lower
  }
  
  // set compare match register for 8hz increments
  OCR1A = time;// = (16*10^6) / (1*1024) - 1 (must be <v65536)
  TCCR1B |= (1 << WGM12);   // turn on CTC mode
  // Set CS12 and CS10 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);

  sei();     //allow interrupts
}

//Function for timer1 interrupt at 8Hz
ISR(TIMER1_COMPA_vect){ 
  
  TCNT1  = 0;   // Initialize counter value to 0
  
  measureTemp();    //Call method to calculate temperature
  
  //Loop goes through the ring with 16 LED's and compare the actual temperature with the array holding all the temperature values
  for(int i = 0; i < NUMPIXELS; i++){
    //If the actual temperature exceeds the range (i) from the array it will lid up a certain amount of LED's
    if(temperatureC > temp_max_values[i]){   
      //Use the index number to set the amount of LED's to lid up
      if(i < 3){ // set LED 1, 2, 3 to light blue
          pixels.setPixelColor(i, pixels.Color(0, 150, 150)); // set RGB values to (255, 0, 0) for red
      }else if(i < 6){ // set 4, 5, 6 LED's to dark blue
          pixels.setPixelColor(i, pixels.Color(0,0,250)); // set RGB values to (0, 255, 0) for green
      }else if(i < 9){ // set LED 7, 8, 9 to yellow
          pixels.setPixelColor(i, pixels.Color(150,150,0)); // set RGB values to (0, 0, 255) for blue
      }else if(i < 12){ // set LED 10, 11, 12 to pink
          pixels.setPixelColor(i, pixels.Color(150,0,150)); // set RGB values to (0, 0, 255) for blue
      }else {     // set LED 13, 14, 15, 16 to red
          pixels.setPixelColor(i, pixels.Color(250,0,0)); // set RGB values to (255, 255, 255) for white for any remaining LEDs
      }
      pixels.show();    //Enable the LED with the colors set to them
    }else {    //Otherwise set all the LED's in the ring to 0 (OFF)
      pixels.setPixelColor(i, pixels.Color(0,0,0));
    }
  }  
  if(temperatureC > 120){   //Check if the temperature is higher than 120
    digitalWrite(buzz, HIGH);   //Sound the buzzed and lid up the LED that is connected in series 
  }else {       
    digitalWrite(buzz, LOW);    //Otherwise the buzzer and LED is off
  }
}

//Function to measure the temperature
void measureTemp() {
  tempValue = analogRead(temp_meter);   //Read the analog signal from the temp sensor (A0) and save in the variable
  voltage = tempValue * (5.019 / 1024.0);  //Convert the analog signal to voltage
  temperatureC = (voltage - 0.5) * 100;    //Convert the voltage signal to temperature in Celcius
  Serial.print(temperatureC); Serial.println(" degrees C");    //Print the temperature
}

void loop() {   //For loop is empty as we use interrrupts
}