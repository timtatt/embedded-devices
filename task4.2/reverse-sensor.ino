int ledPin = 13;
int buzzerPin = 6;
int trigPin = 9;
int echoPin = 10;

long duration;
int distance;

int ultrasonicRange;

void setup() {
	pinMode(ledPin, OUTPUT);
	pinMode(trigPin, OUTPUT);
	pinMode(buzzerPin, OUTPUT);
	pinMode(echoPin, INPUT);
	Serial.begin(9600);
}

void loop() {
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);
	
	duration = pulseIn(echoPin, HIGH);
	distance = duration * 0.034/2;
	
	Serial.print("Distance: ");
	Serial.println(distance);

	float buzzerLevel = distance / ultrasonicRange * 255;
	analogWrite(buzzerPin, buzzerLevel);
	delay(100);
}