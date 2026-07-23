#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const char *messages[][2] = {
  {"Hello!", "Welcome"},
  {"Nano 33 BLE", "Sense Board"},
  {"I2C LCD", "Working Fine"},
  {"Embedded", "Systems Lab"}
};

int currentMessage = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.setRGB(0, 255, 0);   // Green
}

void loop() {

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print(messages[currentMessage][0]);

  lcd.setCursor(0, 1);
  lcd.print(messages[currentMessage][1]);

  currentMessage++;
  if (currentMessage >= 4)
    currentMessage = 0;

  delay(2000);
}