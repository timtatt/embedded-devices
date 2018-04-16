#include "Particle.h"

int lightPin = A0;
String lightLevel = "";

void setup() {
    pinMode(lightPin, INPUT);
}

void loop() {
    lightLevel = String(analogRead(lightPin), DEC);
    Particle.publish("light", lightLevel, PRIVATE);
    delay(3000);
}