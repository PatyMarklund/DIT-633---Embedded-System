// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 6
// Exercise 2
// Submission code: 00110620 (provided by your TA-s)

//Define pins for ultrasonic
#define trigPin 9
#define echoPin 8
//Define pins for the LED's and buzzer
#define LED_1 2
#define LED_2 3
#define LED_3 4
#define LED_4 5
#define soundbuzzer 6

//Initialize the variables used to read the ultrasonic sensor
long durationindigit, distanceincm;

void setup() {
  Serial.begin (9600);
  //Initialize all pins
  pinMode(trigPin, OUTPUT);  //Trig pin is an output as it is sending the signal
  pinMode(echoPin, INPUT);   //Echo pin is the input that read back the signal that bounces back when reach an object
  //Set LED and buzzer pins to output
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  pinMode(LED_3, OUTPUT);
  pinMode(LED_4, OUTPUT);
  pinMode(soundbuzzer, OUTPUT);
}

void loop() {
  long distance = readDistance(); //Call the function that calculates the distance to an object from the ultrasonic sensor
  setSpeaker(distance);  //Call the function that sets the frequency to the spekers as the distance changes
  setLED(distance);  //Call the function that sets the LED on and off as the distance changes
  delay(400);   //Delay of 400 
  noTone(soundbuzzer);   //Turn off the sound buzzer 
}

//Function that calculates the distance to an object from the ultrasonic sensor
long readDistance(){
  
  //Generate a 10 microsencond pulse on TRIG pin
  digitalWrite(trigPin, LOW);  //Write a zero to the output to clear the system.
  delayMicroseconds(2);        //Wait 2 microseconds
  digitalWrite(trigPin, HIGH); //Write a one to the output to send a ping
  delayMicroseconds(10);       //Wait 10 microseconds
  digitalWrite(trigPin, LOW);  //Write a zero to the output to stop sending the ping.
  durationindigit = pulseIn(echoPin, HIGH);   //Measure the pulse duration in echoPin using pulseIn() function.
  
  //Calculate the distance between sensor and obstacle and deliver that in centimeters
  distanceincm = (durationindigit * 0.0344) / 2;     //distance = travel_time * speed / 2
  Serial.print(distanceincm);
  Serial.println(" cm");
  return distanceincm;   //Return the distance to be used in other functions
}

//Function that sets the frequency to the spekers as the distance changes
void setSpeaker(long distance){
  if (distance < 30) {          //If distance is bellow 30 the frequency will be 4000 which is very annoying
    tone(soundbuzzer, 4000);    //Use function tone to set the buzzed pin to a frequency of 4000
  }else if (distance < 50) {    //If distance is bellow 50 the frequency will be 3000
    tone(soundbuzzer, 3000);    //Use function tone to set the buzzed pin to a frequency of 3000
  }else if (distance < 100) {   //If distance is bellow 100 the frequency will be 2000
    tone(soundbuzzer, 2000);    //Use function tone to set the buzzed pin to a frequency of 2000
  }else if (distance < 200) {   //If distance is bellow 200 the frequency will be 500
    tone(soundbuzzer, 500);     //Use function tone to set the buzzed pin to a frequency of 500
  }
}

//Function that sets the LED on or off as the distance changes
void setLED(long distance) {
  if (distance < 25) {              //If distance is bellow 25 all LED's will be on and blinking
    digitalWrite(LED_1, !digitalRead(LED_1));  //This code toggles the state of an LED to on or off and make it blink
    digitalWrite(LED_2, !digitalRead(LED_2));  
    digitalWrite(LED_3, !digitalRead(LED_3));
    digitalWrite(LED_4, !digitalRead(LED_4));
  }else if(distance < 30){          //If distance is bellow 30 all LED's will be constantly on 
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, HIGH);
  }else if(distance < 50){          //If distance is bellow 50 3 LED's will be constantly on
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, LOW);  
  }else if(distance < 100){         //If distance is bellow 100  LED's will be constantly on
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);  
  }else if(distance < 200){        //If distance is bellow 200 all LED's will be constantly on
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);  
  }else {                          //If distance is above 200 all LED's will go off
    digitalWrite(LED_1, LOW);
    digitalWrite(LED_2, LOW);
    digitalWrite(LED_3, LOW);
    digitalWrite(LED_4, LOW);
  }
}