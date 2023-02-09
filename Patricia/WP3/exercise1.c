// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 3
// Exercise 1 (Set-Up)
// Submission code: xxxxx (provided by your TA-s)

//Define session
#define PIN13 13
#define PIN12 12
#define PIN2 2

//##### Initialize Session #####

int buttonState = 0;  //Initialize the button to state 0 (off)
int LED_state = LOW;  //Initialize the state of the blinking LED for 0 (off)

//Initialize previous time used to keep track of the time the LED blinked the last
unsigned long prevtime_t1 = 0;

//Time interval for task 1
long interval_t1 = 1000;  //Interval used to make it blink every one second 

//##### Setup Session #####

void setup()
{
  pinMode(PIN13, OUTPUT);  //Set pin 13 to be output for the LED
  pinMode(PIN2, INPUT);  //Set pin 2 to be input from the button
  pinMode(PIN12, OUTPUT); //Set pin 12 to be output to the second LED
}

//###### Start Loop ########

void loop()
{  
  //Task1
  //Initialize the variable that holds the current milisecond
  unsigned long currentTime = millis(); 
  
  //Check if the current time - the previous time is bigger than the interval of 1 second 
  if(currentTime - prevtime_t1 > interval_t1) {
    LED_state = !LED_state;  //If bigger then we toggle the LED to the opposite state it was previously
    digitalWrite(PIN13, LED_state);   //We then set the LED to that state
    prevtime_t1 = currentTime;   //And we save the last time the LED toggled on the prevtime so we keep track of the time
  }
  
  //Task 2
  buttonState = digitalRead(PIN2);  //Read the input from pin2 which comes from the button
  
  if(buttonState == HIGH){  //If the input was high, which means the button pressed
    digitalWrite(PIN12, HIGH);  //We write to the second LED on pin12 to turn it on.
  }else {  
    digitalWrite(PIN12, LOW);   //If the button is not high we set the LED to off state
  }
}