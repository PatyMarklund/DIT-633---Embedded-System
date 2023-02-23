// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 4
// Exercise 2 
// Submission code: 14000401 (provided by your TA-s)

//Include Servo library
#include <Servo.h>

//Define the servo pin
#define servoSec 5    
#define servoMin 6

//Define variables used in the interrupt
#define CLOCK_TIME 16000000
#define PRESCALE 64    
#define FREQUENCY 1     //Set prescale to 64 with freq 1 to move faster
#define TIMER_MAX 256
#define TIMER_MIN 64

//Initialize servo variables
int servo_pos = 0;   //Position of the servo (seconds)
int min_pos = 0;     //Position of the servo (minutes)
int sec = 0;         //Variable used to print seconds
int min = 0;         //Variable used to print minutes
unsigned long counter = 0; // Servo seconds counter
int minutes = 0;           //Servo minutes counter

int time = 0;

// Create new servo objects
Servo servo_sec;   // create a servo object to control the second hand
Servo servo_min;   // create a servo object to control the minute hand

void setup() {
  Serial.begin(9600);
  servo_sec.attach(servoSec);    // Attach the Servo seconds to a pin:
  servo_min.attach(servoMin);    // Attach the servo minute to a pin
  
  cli();           //stop interrupts
  
 //Set timer0 interrupt at 1Hz 
  TCCR0A = 0;    // set entire TCCR2A register to 0
  TCCR0B = 0;// same for TCCR2B
  TCNT0  = 0;//initialize counter value to 0
  //Set incrememt time using constant variables
  time = (CLOCK_TIME / (PRESCALE * FREQUENCY));
  //The incrememt time should not be higher than Timer_max or lower than Timer_min
  if (time >= TIMER_MAX) {
    time = TIMER_MAX;   //If higher set time to the maximum 255
  }else if (time <= TIMER_MIN) {
    time = TIMER_MIN;   //If lower than 64 set the time to the lower
  }

  // set compare match register for 1khz increments
  OCR0A = time;// = (16*10^6) / (1*64) - 1 (must be <256)
  // turn on CTC mode
  TCCR0A |= (1 << WGM01);
  // Set CS01 and CS00 bits for 64 prescaler / 256 prescale set (1 << CS02)
  TCCR0B |= (1 << CS01) | (1 << CS00);   
  // enable timer compare interrupt
  TIMSK0 |= (1 << OCIE0A);

  sei();         //allow interrupts
}

void loop() {
}

ISR(TIMER0_COMPA_vect){ 
  
  counter++;    //increment counter
  if(counter % 1000 == 0){   //Check if counter is a multiple of 1000 using modulus
    sec = counter/1000;      //Convert ms to seconds (1 sec = 1000 ms)
    
    Serial.print("Time: ");
    Serial.print(min);
    Serial.print(" min: ");
    Serial.print(sec);
    Serial.println(" sec");
    
    //Servo position is incrememted by 3 degrees and total cicle is 180 degrees / 60 seconds
    servo_pos = (sec % 60) * 3;  //Use the timer value as a multiplier using mod operator
    servo_sec.write(servo_pos);  //Write the degree position to the servo (seconds)
    servo_min.write(min_pos);    //Write the degree position to the servo (minutes), which is 0 at first
	//Check when the servo seconds reaches the end at 180 degrees. 
    //Reset the counter and move the minutes servo
    if (servo_pos == 177){  
      counter = 0;    //Reset counter so the seconds start counting from 0
      minutes++;      //Increase the counter for the minutes servo
      min_pos = minutes * 3;     //The minute servo should move 3 positions everytime reaches the if statement
      servo_min.write(min_pos);  //Write the position to the servo minutes
      min = minutes;             //Save the minutes in the variable to be printed
    }
  }
}