// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 4
// Exercise 1 
// Submission code: xxxxx (provided by your TA-s)

//Define pins for LED's
#define LED_RED 13
#define LED_WHITE 12
#define LED_YELLOW 11
#define LED_BLUE 10
#define LED_GREEN 9

//Define variables used in the interrupt
#define CLOCK_TIME 16000000
#define PRESCALE 1024
#define FREQUENCY 8
#define TIMER_MAX 65536
#define TIMER_MIN 257

//Temperature storage variables
int tempValue = 0;    
float voltage;
float temperatureC;
int time = 0;
const int temp_meter = A0;

//Temperature range variables
const int temp_min = 0;      //between -40 to 0 degrees
const int temp_max_25 = 25;  //between 1 to 25 degrees
const int temp_max_50 = 50;  //between 26 to 50 degrees
const int temp_max_75 = 75;  //between 51 to 75 degrees
const int temp_max = 100;     //above 100 degrees

void setup(){
  Serial.begin(9600); 
  //set pins as outputs/Inputs
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_WHITE, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(temp_meter, INPUT);   //Set temperature Analog input

  cli();     //Stop interrupts

//Set timer1 interrupt at 8Hz
  TCCR1A = 0;   // set entire TCCR1A register to 0
  TCCR1B = 0;   // same for TCCR1B
  TCNT1  = 0;   // Initialize counter value to 0 
  //Set incrememt time using constant variables
  time = (CLOCK_TIME / (PRESCALE * FREQUENCY)) - 1;
  
  //The incrememt time should not be higher than Timer_max or lower than Timer_min
  if (time >= TIMER_MAX) {
    time = TIMER_MAX;   //If higher set time to the maximum 65536
  }else if (time <= TIMER_MIN) {
    time = TIMER_MIN;   //If lower than 256 set the time to the lower
  }
  
  // set compare match register for 8hz increments
  OCR1A = time;// = (16*10^6) / (8*1024) - 1 (must be < 65536)
  TCCR1B |= (1 << WGM12);   // turn on CTC mode
  // Set CS12 and CS10 bits for 1024 prescaler
  TCCR1B |= (1 << CS12) | (1 << CS10);  
  // enable timer compare interrupt
  TIMSK1 |= (1 << OCIE1A);

  sei();       //allow interrupts

}//end setup

//timer1 interrupt 8Hz
ISR(TIMER1_COMPA_vect){ 
  
  //Set all the pins to the leds to LOW before next cicle
  digitalWrite(LED_RED,LOW);
  digitalWrite(LED_WHITE,LOW);
  digitalWrite(LED_YELLOW,LOW);
  digitalWrite(LED_BLUE,LOW);
  digitalWrite(LED_GREEN,LOW);
    
  measureTemp();    //Call method to calculate temperature
  
  //Check range of the temperature and set the LED's to on according to the range defined
  if(temperatureC <= temp_min){  //If temperature below 0 nothing happens
    Serial.println("Nothing happens");
  }else if(temperatureC > temp_min && temperatureC < temp_max_25){  //If temp between 1 and 25
    digitalWrite(LED_RED,HIGH);             //Set red LED to on
  }else if (temperatureC <= temp_max_50){   //If temp between 25 and 50
    digitalWrite(LED_RED,HIGH);             //Set red and white LED's to on
    digitalWrite(LED_WHITE,HIGH);
  }else if (temperatureC <= temp_max_75){   //If temp between 51 and 75
    digitalWrite(LED_RED,HIGH);            //Set red, white and yellow LED's to on
    digitalWrite(LED_WHITE,HIGH);
    digitalWrite(LED_YELLOW,HIGH);
  }else if (temperatureC <= temp_max){    //If temp between 76 and 100
    digitalWrite(LED_RED,HIGH);          //Set red, white, yellow and blue LED's to on
    digitalWrite(LED_WHITE,HIGH);
    digitalWrite(LED_YELLOW,HIGH);
    digitalWrite(LED_BLUE,HIGH);
  }else if (temperatureC > temp_max){   //If temp higher than 100
    digitalWrite(LED_RED,HIGH);          //Set all LED's to on 
    digitalWrite(LED_WHITE,HIGH);
    digitalWrite(LED_YELLOW,HIGH);
    digitalWrite(LED_BLUE,HIGH);
    digitalWrite(LED_GREEN,HIGH);
  }
}
  
void loop(){  //Loop empty as we use interrupt
}
    
//Function to measure the temperature
void measureTemp() {
  tempValue = analogRead(temp_meter);   //Read the analog signal from the temp sensor (A0) and save in the variable
  voltage = tempValue * (5.019 / 1024.0);  //Convert the analog signal to voltage
  temperatureC = (voltage - 0.5) * 100;    //Convert the voltage signal to temperature in Celcius
  Serial.print(temperatureC); Serial.println(" degrees C");    //Print the temperature
}


