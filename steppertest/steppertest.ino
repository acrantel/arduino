#include <Stepper.h>

const int stepsPerRevolution = 48;
Stepper testStepper(stepsPerRevolution, 11, 10, 9, 8);

void setup() {
  // put your setup code here, to run once:
  testStepper.setSpeed(100);
}

void loop() {
  // put your main code here, to run repeatedly:
  testStepper.step(stepsPerRevolution);
}
