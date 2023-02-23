// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 4
// Exercise 3 
// Submission code: xxxxx (provided by your TA-s)

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

//Temperature range variables
#define temp_min 0        //between -40 to 0 degrees
#define temp_max_25 25    //between 1 to 25 degrees
#define temp_max_50 50    //between 26 to 50 degrees
#define temp_max_75 75    //between 51 to 75 degrees
#define temp_max 100      //above 100 degrees

//Initialize temperature variables
int time = 0;
int tempValue = 0;
float voltage;
int temperatureC;
const int temp_meter = A0;

// Setup the NeoPixel library and tell it how many pixels, and which pin to use to send signals.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

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
  
  //For loop that goes through all pixels and set them to 0 before the next loop
  for(int i=0;i<NUMPIXELS;i++){
    pixels.setPixelColor(i, pixels.Color(0,0,0)); // Ring (all 16 pixels) is OFF
  }

  measureTemp();            //Call method to calculate temperature
  
  //Check range of the temperature and set the LED's to on according to the range defined
  if(temperatureC <= temp_min){    //If temperature below 0 nothing happens
    Serial.println("Nothing happens");
  }else if(temperatureC > temp_min && temperatureC < temp_max_25){   //If temp between 1 and 25
    pixels.setPixelColor(0, pixels.Color(0,150,150));   //Set 3 pixels on to light blue
    pixels.setPixelColor(1, pixels.Color(0,150,150));
    pixels.setPixelColor(2, pixels.Color(0,150,150));
  }else if (temperatureC <= temp_max_50){               //If temp between 25 and 50
    pixels.setPixelColor(0, pixels.Color(0,150,150));   //Set 3 more pixels to dark blue 
    pixels.setPixelColor(1, pixels.Color(0,150,150));
    pixels.setPixelColor(2, pixels.Color(0,150,150));
    pixels.setPixelColor(3, pixels.Color(0,0,250));
    pixels.setPixelColor(4, pixels.Color(0,0,250));
    pixels.setPixelColor(5, pixels.Color(0,0,250));
  }else if (temperatureC <= temp_max_75){               //If temp between 51 and 75
    pixels.setPixelColor(0, pixels.Color(0,150,150));   //Set 3 more pixels to yellow
    pixels.setPixelColor(1, pixels.Color(0,150,150));
    pixels.setPixelColor(2, pixels.Color(0,150,150));
    pixels.setPixelColor(3, pixels.Color(0,0,250));
    pixels.setPixelColor(4, pixels.Color(0,0,250));
    pixels.setPixelColor(5, pixels.Color(0,0,250));
    pixels.setPixelColor(6, pixels.Color(150,150,0));
    pixels.setPixelColor(7, pixels.Color(150,150,0));
    pixels.setPixelColor(8, pixels.Color(150,150,0));
  }else if (temperatureC <= temp_max){                 //If temp between 76 and 100
    pixels.setPixelColor(0, pixels.Color(0,150,150));  //Set 3 more pixels to pink
    pixels.setPixelColor(1, pixels.Color(0,150,150));
    pixels.setPixelColor(2, pixels.Color(0,150,150));
    pixels.setPixelColor(3, pixels.Color(0,0,250));
    pixels.setPixelColor(4, pixels.Color(0,0,250));
    pixels.setPixelColor(5, pixels.Color(0,0,250));
    pixels.setPixelColor(6, pixels.Color(150,150,0));
    pixels.setPixelColor(7, pixels.Color(150,150,0));
    pixels.setPixelColor(8, pixels.Color(150,150,0));
    pixels.setPixelColor(9, pixels.Color(150,0,150));
    pixels.setPixelColor(10, pixels.Color(150,0,150));
    pixels.setPixelColor(11, pixels.Color(150,0,150));
  }else if (temperatureC > temp_max){                    //If temp higher than 100
    pixels.setPixelColor(0, pixels.Color(0,150,150));    //Set 4 last pixels to red
    pixels.setPixelColor(1, pixels.Color(0,150,150));
    pixels.setPixelColor(2, pixels.Color(0,150,150));
    pixels.setPixelColor(3, pixels.Color(0,0,250));
    pixels.setPixelColor(4, pixels.Color(0,0,250));
    pixels.setPixelColor(5, pixels.Color(0,0,250));
    pixels.setPixelColor(6, pixels.Color(150,150,0));
    pixels.setPixelColor(7, pixels.Color(150,150,0));
    pixels.setPixelColor(8, pixels.Color(150,150,0));
    pixels.setPixelColor(9, pixels.Color(150,0,150));
    pixels.setPixelColor(10, pixels.Color(150,0,150));
    pixels.setPixelColor(11, pixels.Color(150,0,150));
    pixels.setPixelColor(12, pixels.Color(250,0,0));
    pixels.setPixelColor(13, pixels.Color(250,0,0));
    pixels.setPixelColor(14, pixels.Color(250,0,0));
    pixels.setPixelColor(15, pixels.Color(250,0,0));
  }
  pixels.show();     //Display the pixels
  
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