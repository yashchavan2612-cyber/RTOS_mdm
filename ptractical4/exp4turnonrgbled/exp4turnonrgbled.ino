void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); // LED on
  delay(500);

  digitalWrite(LED_BUILTIN, LOW);  // LED off
  delay(500);
}