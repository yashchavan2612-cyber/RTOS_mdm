#include <Arduino_LSM9DS1.h>
#include <HardwareBLESerial.h>

HardwareBLESerial &bleSerial = HardwareBLESerial::getInstance();

const int ledPin = LED_BUILTIN;   // Built-in LED

void setup() {
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  while (!bleSerial.beginAndSetupBLE("sanjyoti's ble"));
  while (!IMU.begin());

  Serial.println("BLE Ready");
}

void loop() {
  // Check for BLE commands
  bleSerial.poll();

  if (bleSerial.available()) {
    char command = bleSerial.read();

    if (command == 'A') {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED ON");
      bleSerial.println("LED ON");
    }
    else if (command == 'B') {
      digitalWrite(ledPin, LOW);
      Serial.println("LED OFF");
      bleSerial.println("LED OFF");
    }
  }

  // Read IMU data
  float x, y, z;

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);

    Serial.print(x);
    bleSerial.print(x);

    Serial.print('\t');
    bleSerial.print('\t');

    Serial.print(y);
    bleSerial.print(y);

    Serial.print('\t');
    bleSerial.print('\t');

    Serial.println(z);
    bleSerial.println(z);
  }

  delay(10);
}