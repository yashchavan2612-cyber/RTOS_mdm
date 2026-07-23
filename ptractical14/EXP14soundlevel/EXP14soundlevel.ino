#include <PDM.h>

#define SAMPLE_BUFFER_SIZE 256

short sampleBuffer[SAMPLE_BUFFER_SIZE];
volatile int samplesRead = 0;

void onPDMdata() {
  int bytesAvailable = PDM.available();
  PDM.read(sampleBuffer, bytesAvailable);
  samplesRead = bytesAvailable / 2;
}

void setup() {
  Serial.begin(115200);
  while (!Serial);

  PDM.onReceive(onPDMdata);

  if (!PDM.begin(1, 16000)) {
    Serial.println("Failed to start PDM!");
    while (1);
  }

  PDM.setGain(40);

  Serial.println("Microphone started");
}

void loop() {

  if (samplesRead) {

    long sum = 0;

    for (int i = 0; i < samplesRead; i++) {
      sum += (long)sampleBuffer[i] * sampleBuffer[i];
    }

    float rms = sqrt((float)sum / samplesRead);

    Serial.print("Sound Level (RMS): ");
    Serial.println(rms);

    samplesRead = 0;
  }
}