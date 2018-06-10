int buttonPin = A0;
int greenPin = 1;
int orangePin = 2;
int redPin = 3;

int cacheState = 0;

/*
Cache States:
0 - Nothing is happening
1 - Pending on a response from the server
*/

void setup() {
    Serial.begin(9600);
    
    pinMode(buttonPin, INPUT);
    
    pinMode(greenPin, OUTPUT);
    pinMode(orangePin, OUTPUT);
    pinMode(redPin, OUTPUT);
    
    Particle.subscribe("cacheStatus", cacheStatusCallback);
}

void loop() {
    int buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH && cacheState == 0) {
        cacheState = 1;
        Serial.println("Button pushed");
        Serial.println("Waiting for server to respond");
        
        Particle.publish("clearCache");
        
        Serial.println("Waiting for button to be unpushed");
        while (buttonState == HIGH) {
            delay(100);
            digitalWrite(orangePin, HIGH);
            delay(100);
            digitalWrite(orangePin, LOW);
            buttonState = digitalRead(buttonPin);
        }
        Serial.println("Button unpushed");
    } else if (cacheState == 1) {
        digitalWrite(orangePin, HIGH);
        delay(100);
        digitalWrite(orangePin, LOW);
    }
    delay(100);
}

void cacheStatusCallback(const char *event, const char *data) {
    Serial.println("Callback received: Cache Cleared");
    cacheState = 0;
    digitalWrite(orangePin, LOW);
    digitalWrite(greenPin, HIGH);
    delay(3000);
    digitalWrite(greenPin, LOW);
    
}