#include <PDM.h>

short sampleBuffer[256];
volatile int samplesRead = 0;

const int RED_LED = 9;
const int GREEN_LED = 10;

const int THRESHOLD = 300;

void onPDMdata() {
  int bytesAvailable = PDM.available();
  PDM.read(sampleBuffer, bytesAvailable);
  samplesRead = bytesAvailable / 2;
}

void setup() {

  Serial.begin(9600);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  PDM.onReceive(onPDMdata);

  if (!PDM.begin(1, 16000)) {
    while (1);
  }
}

void loop() {

  if (samplesRead) {

    long sum = 0;

    for (int i = 0; i < samplesRead; i++) {
      sum += abs(sampleBuffer[i]);
    }

    int soundLevel = sum / samplesRead;

    Serial.println(soundLevel);

    if (soundLevel > THRESHOLD) {

      digitalWrite(GREEN_LED, HIGH);
      digitalWrite(RED_LED, LOW);

    }
    else {

      digitalWrite(GREEN_LED, LOW);
      digitalWrite(RED_LED, HIGH);
    }

    samplesRead = 0;
  }
}