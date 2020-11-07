#include <Servo.h>

// create servo object to control a servo
Servo myservo;  
// variable to read the value from the analog pin
int potVal;    

void setup() {
  // attaches the servo on pin 9 to the servo object
  myservo.attach(9);  
}

void loop() {
  // reads the value of the potentiometer (value between 0 and 1023)
  potVal = analogRead(A0);
  // scale the value in [0, 1023] to a value in [0, 180] so it can be used with the servo.
  // equivalent to (potVal/1023)*180
  potVal = map(potVal, 0, 1023, 0, 180);     
  // sets the servo position according to the scaled value
  myservo.write(potVal);
}
