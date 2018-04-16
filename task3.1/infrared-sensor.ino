#include <Math.h>

int sensorIRPin = A0;
int ledPin = 13;

int maxDist = 30;
int minDist = 4;
int maxReading = 620;
int minReading = 150;
double calibration = 1.0 * (maxDist - minDist) / (maxReading - minReading);

int lastDistance = 0;

void setup() {
  Serial.begin(9600);
  pinMode(sensorIRPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  double sensorIRReading = analogRead(sensorIRPin) * calibration;
  int distance = 30 - sensorIRReading;
  distance = abs(distance);
  
  Serial.println(distance);
  if (abs(lastDistance - distance) > 1) {
    digitalWrite(ledPin, HIGH);
    delay(400);
    digitalWrite(ledPin, LOW);
    delay(100);
  } else {
    delay(500);
  }
  lastDistance = distance;
}