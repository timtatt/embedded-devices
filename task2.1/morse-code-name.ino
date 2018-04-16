int ledPin = D7;

int unitLength = 200;
int dotWait = unitLength;
int dashWait = unitLength * 3;
int letterWait = unitLength * 2;
int wordWait = unitLength * 7;

void setup() {
    pinMode(ledPin, OUTPUT);
}

void dot() {
    digitalWrite(ledPin, HIGH);
    delay(dotWait);
    digitalWrite(ledPin, LOW);
    delay(dotWait);
}

void dash() {
    digitalWrite(ledPin, HIGH);
    delay(dashWait);
    digitalWrite(ledPin, LOW);
    delay(dotWait);
}

void loop() {
    dash(); // T
    delay(letterWait);
    
    dot();
    dot(); // I
    delay(letterWait);
    
    dash();
    dash(); // M
    
    delay(wordWait);
    
    dash(); // T
    delay(letterWait);
    
    dot();
    dash(); // A
    delay(letterWait);
    
    dash(); // T
    delay(letterWait);
    
    dash(); // T
    delay(letterWait);
    
    dot(); // E
    delay(letterWait);
    
    dot();
    dash();
    dot(); // R
    delay(letterWait);
    
    dot();
    dot();
    dot(); // S
    delay(letterWait);
    
    dot();
    dash(); // A
    delay(letterWait);
    
    dot();
    dash();
    dot();
    dot(); // L
    delay(letterWait);
    
    dot();
    dash();
    dot();
    dot(); // L
    delay(letterWait);
    
    delay(wordWait);
}