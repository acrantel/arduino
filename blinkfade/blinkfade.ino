int ledPin = 9;
int currentPWM = 0;
int fadeChange = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (currentPWM + fadeChange < 0 || currentPWM + fadeChange > 255) {
    currentPWM = max(0, min(currentPWM, 255));
    fadeChange = -fadeChange;
  }
  currentPWM += fadeChange;
  Serial.print(currentPWM);
  analogWrite(ledPin, currentPWM);
  delay(200);
}
