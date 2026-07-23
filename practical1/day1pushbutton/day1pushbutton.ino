/*
  Button with Internal Pull-up

  Circuit:
  - LED connected to pin 13
  - Pushbutton connected between pin 2 and GND

  When the button is pressed, the LED turns on.
*/

// constants won't change:
const int buttonPin = 2;
const int ledPin = 13;

// variable will change:
int buttonState = 0;

void setup() {
  // Initialize LED pin as output
  pinMode(ledPin, OUTPUT);

  // Enable internal pull-up resistor
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // Read the button state
  buttonState = digitalRead(buttonPin);

  // Button is pressed when the input is LOW
  if (buttonState == LOW) {
    digitalWrite(ledPin, HIGH);  // Turn LED on
  } else {
    digitalWrite(ledPin, LOW);   // Turn LED off
  }
}