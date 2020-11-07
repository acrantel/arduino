// pin connected to LED, change it to whatever pin number you are using
const int LED_PIN = 11;
// pin connected to switch, change it to whatever pin number you are using
const int SWITCH_PIN = 2;

// stores the current brightness of the LED
int ledBrightness = 255;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin for LED as an output.
  pinMode(LED_PIN, OUTPUT);
  // initialize pin for switch as an input
  pinMode(SWITCH_PIN, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  // if the switch is on
  if (digitalRead(SWITCH_PIN) == HIGH) {
    // decrease brightness of LED
    //ledBrightness = ledBrightness - 15;
    ledBrightnes -= 15;
    if (ledBrightness < 0) {
      ledBrightness = 255;
    }
    delay(100);
  }
  analogWrite(LED_PIN, ledBrightness);
}
