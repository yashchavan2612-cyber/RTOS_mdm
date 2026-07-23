#include <Arduino_LSM9DS1.h>

float x, y, z;

void setup() {
  Serial.begin(115200);

  if (!IMU.begin()) {
    Serial.println("IMU initialization failed!");
    while (1);
  }
}

void loop() {

  if (IMU.accelerationAvailable()) {

    IMU.readAcceleration(x, y, z);

    String label = "CENTER";

    if (x > 0.3 && y > 0.3)
      label = "FORWARD_LEFT";
    else if (x > 0.3 && y < -0.3)
      label = "FORWARD_RIGHT";
    else if (x < -0.3 && y > 0.3)
      label = "BACKWARD_LEFT";
    else if (x < -0.3 && y < -0.3)
      label = "BACKWARD_RIGHT";
    else if (x > 0.3)
      label = "FORWARD";
    else if (x < -0.3)
      label = "BACKWARD";
    else if (y > 0.3)
      label = "LEFT";
    else if (y < -0.3)
      label = "RIGHT";

    Serial.print("X: ");
    Serial.print(x, 2);
    Serial.print("  Y: ");
    Serial.print(y, 2);
    Serial.print("  Label: ");
    Serial.println(label);
  }

  delay(50);
}