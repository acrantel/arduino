/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

const int POT_PIN = 0;  // analog pin used to connect the potentiometer
int potVal;    // variable to read the value from the analog pin

const int SERVO_PIN = 9;

void setup() {
  myservo.attach(SERVO_PIN);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  potVal = analogRead(POT_PIN);            // reads the value of the potentiometer (value between 0 and 1023)
  potVal = map(potVal, 0, 1023, 0, 180);     // scale the value in [0, 1023] to a value in [0, 180] so it can be used with the servo.
  myservo.write(potVal);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}
