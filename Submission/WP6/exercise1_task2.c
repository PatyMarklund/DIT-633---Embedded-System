// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 6
// Exercise 1 (TASK 2)
// Submission code: 00110620 (provided by your TA-s)

//Define motor pins 
#define PWM1 5
#define PWM2 6
//Define encoder pins 
#define ENC_A 2
#define ENC_B 3

volatile int pos = 0;   //Initialize the variable to hold the position of the motor

int direction = 0; // Desired motor direction
int *ptrDir = &direction;   //Save the direction on a pointer
 
int speed = 0; // Desired motor speed
int *ptrSpeed = &speed;    //Save the speed on a pointer

int a = 0; // a-encoder signal
int b = 0; // b-encoder signal

void setup() {
 
  Serial.begin(9600);
  pinMode(PWM1,OUTPUT);
  pinMode(PWM2,OUTPUT);
  pinMode(ENC_A,INPUT_PULLUP);
  pinMode(ENC_B,INPUT_PULLUP);
  
  // Start the motor, just a tiny little bit because otherwise TinkerCad dies....
  analogWrite(PWM2, 10); 
  delay(1000); // TinkerCad bug
  analogWrite(PWM1, 10);
  
  // Get input 
  getInput(ptrDir, ptrSpeed);

  //Start the interrup at every rising reading from the a signal encoder. Call the function encoderISR 
  attachInterrupt(digitalPinToInterrupt(ENC_A), encoderISR, RISING);
}

void loop() {
     
  // Send speed signal to motor
  if (direction == 1) {     // If the input is 1 turn the motor Clockwise
    analogWrite(PWM2, 0);
    analogWrite(PWM1, speed);   //Write the speed on the motor that turns clockwise
  }
  else if (direction == 0) { // IF the input is 0 turn the motor Counter-clockwise
    analogWrite(PWM1, 0);
    analogWrite(PWM2, speed);   //Write the speed on the motor that turns counter-clockwise
  }
  else { // If any input other than 0 and 1 Stop the motor
    analogWrite(PWM1, 10);
    analogWrite(PWM2, 10);
  }

  // Print the current position in degrees
  Serial.println(pos * 360.0 / 1000.0);
}

//Method that gets the input from the user
void getInput(int *direction, int *speed){
 
  int ready = 0;    // A flag to indicate when input is ready
  char buf[5];      // A buffer to store the input characters
  int dir = -1;     // The integer value of the direction
  int spd = -1;     // The integer value of the speed
  
  Serial.print("Please enter the desired direction (1 = clockwise; 0 = counter clock) and speed (max: 25) In format 'direction,speed'): \n");
  
  // Loop until input is ready.
  while(!ready){
    // Read up to 5 bytes from the serial monitor into the buffer, and store the number of bytes read in ready.
    ready = Serial.readBytesUntil('\n', buf, 5);
    if (ready > 0) {
      // Parse the input string into direction and speed values
      char *ptr = strtok(buf, ",");    // Split the input string at the comma.
      if (ptr != NULL) {
        dir = atoi(ptr);     // Convert the first part to an integer and store it in dir.
      }
      ptr = strtok(NULL, ",");    // Split the remaining string at the comma.
      if (ptr != NULL) {
        spd = atoi(ptr);     // Convert the second part to an integer and store it in spd.
      }
    }
  }
  *direction = dir;   //Update the direction to the pointer
  *speed = spd;       //Update the speed to the pointer
}  

void encoderISR() {
  // Read the state of the encoder pins
  //If b is greater than 0 means that the motor is turnung counter-clockwise
  b = digitalRead(ENC_B);

  //If b is greater than 0 means that the motor is turnung counter-clockwise
  if (b > 0) {
    pos--;     //Then we set the position to count minus
  }else {      //If b is lessa than 0 then means that a signal trigged first and the motors is turning clockwise
    pos++;     //Then we set the position to count plus
  }
}