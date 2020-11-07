#include <LiquidCrystal.h>

LiquidCrystal lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.print("hello, world!");
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0, 1); 
  lcd.print("Counter:");
  lcd.print(millis()/1000);
}
