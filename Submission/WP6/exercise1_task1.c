// (C) Patricia Marklund, Anna Törngren, Sanna Evertsson, group: 10 (2023)
// Work package 6
// Exercise 1 (TASK 1)
// Submission code: 00110620 (provided by your TA-s)

//Define motor pins
#define PWM1 5
#define PWM2 6

int direction = 0; // Desired motor direction
int *ptrDir = &direction;  //Save the direction on a pointer

int speed = 0; // Desired motor speed
int *ptrSpeed = &speed;   //Save the speed on a pointer

void setup() {
  Serial.begin(9600);
  //Initialize the motor pins to output
  pinMode(PWM1,OUTPUT);   
  pinMode(PWM2,OUTPUT);  
  
  // Start the motor, just a tiny little bit because otherwise TinkerCad dies....
  analogWrite(PWM2, 10); 
  delay(1000); // TinkerCad bug
  analogWrite(PWM1, 10);
}

void loop() {
  
  // Get input 
  getInput(ptrDir, ptrSpeed);
    
  // Send speed signal to motor
  if (direction == 1) { // If the input is 1 turn the motor Clockwise
    analogWrite(PWM2, 0);       
    analogWrite(PWM1, speed);    //Write the speed on the motor that turns clockwise
  }
  else if (direction == 0) { // IF the input is 0 turn the motor Counter-clockwise
    analogWrite(PWM1, 0);
    analogWrite(PWM2, speed);   //Write the speed on the motor that turns counter-clockwise
  }
  else { // If any input other than 0 and 1 Stop the motor
    analogWrite(PWM1, 10); 
    analogWrite(PWM2, 10);
  }
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
      char *ptr = strtok(buf, ",");     // Split the input string at the comma
      if (ptr != NULL) {
        dir = atoi(ptr);      // Convert the first part to an integer and store it in dir.
      }
      ptr = strtok(NULL, ",");    // Split the remaining string at the comma.
      if (ptr != NULL) {
        spd = atoi(ptr);    // Convert the second part to an integer and store it in spd.
      }
    }
  }
  *direction = dir;   //Update the direction to the pointer
  *speed = spd;       //Update the speed to the pointer
}  
