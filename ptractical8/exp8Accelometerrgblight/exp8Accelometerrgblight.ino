#include <Arduino_LSM9DS1.h>

// Built-in RGB LED pins
#define LEDR 22
#define LEDG 23
#define LEDB 24

void setup() {
  Serial.begin(9600);

  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);

  // Turn all LEDs off
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, HIGH);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  Serial.println("Tilt Detection Started");
}

void loop() {
  float x, y, z;

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);

    Serial.print("X: ");
    Serial.print(x);
    Serial.print("  Y: ");
    Serial.print(y);
    Serial.print("  Z: ");
    Serial.println(z);

    // Left Tilt
    if (x < -0.5) {
      blinkRed();
    }
    // Right Tilt
    else if (x > 0.5) {
      blinkGreen();
    }
    // Up Tilt
    else if (y > 0.5) {
      blinkBlue();
    }
    // Down Tilt
    else if (y < -0.5) {
      blinkYellow();
    }
    else {
      ledsOff();
    }
  }
}

void ledsOff() {
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, HIGH);
}

void blinkRed() {
  ledsOff();
  digitalWrite(LEDR, LOW);
  delay(200);
  ledsOff();
  delay(200);
}

void blinkGreen() {
  ledsOff();
  digitalWrite(LEDG, LOW);
  delay(200);
  ledsOff();
  delay(200);
}

void blinkBlue() {
  ledsOff();
  digitalWrite(LEDB, LOW);
  delay(200);
  ledsOff();
  delay(200);
}

void blinkYellow() {
  ledsOff();
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDG, LOW);
  delay(200);
  ledsOff();
  delay(200);
}