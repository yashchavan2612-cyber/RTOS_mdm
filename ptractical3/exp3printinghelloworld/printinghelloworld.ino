void setup() {
  Serial.begin(115200);

  // Wait for the Serial Monitor to open (optional but useful on USB boards)
  while (!Serial) {
    ;
  }

  Serial.println("Hello, World!");
}

void loop() {
  // Nothing to do here
}