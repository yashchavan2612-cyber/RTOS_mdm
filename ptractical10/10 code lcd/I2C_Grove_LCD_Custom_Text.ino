#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int numCols = 16;
const int numRows = 2;

void setup() {
  // Initialize LCD
  lcd.begin(numCols, numRows);

  // Set LCD backlight color (Red, Green, Blue)
  lcd.setRGB(0, 255, 255);   // Cyan

  // Display first message
  lcd.setCursor(0, 0);
  lcd.print("Nano 33 BLE");

  lcd.setCursor(0, 1);
  lcd.print("I2C LCD Ready!");

  delay(3000);

  lcd.clear();

  // Display another message
  lcd.setCursor(0, 0);
  lcd.print("Embedded");

  lcd.setCursor(0, 1);
  lcd.print("Systems Lab");
}

void loop() {

}