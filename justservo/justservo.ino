#include <Servo.h>

// create servo object to control a servo
Servo myservo;

void setup() {
  // attaches the servo on pin 9 to the servo object
  myservo.attach(9);  
}

void loop() {
  // sets the servo to 120 deg
  myservo.write(0);  
}
