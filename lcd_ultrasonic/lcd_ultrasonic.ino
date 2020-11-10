#include <LiquidCrystal_I2C.h> // Library for LCD

// Wiring: SDA pin is connected to A4 and SCL pin to A5.
// Connect to LCD via I2C, default address 0x27 (A0-A2 not jumpered)
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // Change to (0x27,16,2) for 16x2 LCD.

// Arduino pin that the ultrasonic's TRIG pin is connected to
const int TRIG_PIN = 9;
// Arduino pin that the US's ECHO pin is connected to
const int ECHO_PIN = 10;
// holds the time of the US wave, and how far away the object is
float duration, distance;
// speed of US waves in cm/microsecond
const float WAVE_SPEED = 0.0343;

void setup() {
  // Initiate the LCD:
  lcd.init();
  lcd.backlight();
  // set up US
  pinMode(TRIG_PIN, OUTPUT); // put output to US's TRIG pin
  pinMode(ECHO_PIN, INPUT); // take input from US's ECHO pin
  Serial.begin(9600); // start Serial connection
}
void loop() {
  // get distance from ultrasonic
  // make sure TRIG_PIN starts at LOW
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  // set TRIG_PIN high for 10 microseconds, then back to LOW
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  // store time for how long ECHO_PIN is HIGH, in microseconds
  duration = pulseIn(ECHO_PIN, HIGH);

  // use equation: distance = speed x time
  // divide duration by 2 because US wave travels to object AND back
  distance = WAVE_SPEED * (duration/2);

  // Print distance on LCD
  // Print 'Hello World!' on the first line of the LCD:
  lcd.setCursor(0, 0); // Set the cursor on the first column and first row.
  lcd.print("Distance (cm):");
  lcd.setCursor(0, 1); //Set the cursor on the first column and the second row
  lcd.print(distance);
  delay(200);
}
