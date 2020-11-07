int ledPin = 8;
int count = 5;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (count < 5) {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
  count++;
  }
  else if (count > 10) {
    Serial.print("restarting");
    delay(1000);
    count = 0;
  } else {
    delay(1000);
    count++;
  }
}
