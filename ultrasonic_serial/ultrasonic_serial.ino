/** Adapted from https://create.arduino.cc/projecthub/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-036380 */

// Arduino pin that the ultrasonic's TRIG pin is connected to
const int TRIG_PIN = 9;
// Arduino pin that the US's ECHO pin is connected to
const int ECHO_PIN = 10;

// holds the time of the US wave, and how far away the object is
float duration, distance;

// speed of US waves in cm/microsecond
const float WAVE_SPEED = 0.0343;

void setup() {
  pinMode(TRIG_PIN, OUTPUT); // put output to US's TRIG pin
  pinMode(ECHO_PIN, INPUT); // take input from US's ECHO pin
  Serial.begin(9600); // start Serial connection
}

void loop() {
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

  Serial.print("Distance in cm: ");
  Serial.println(distance);
  delay(100);
}
