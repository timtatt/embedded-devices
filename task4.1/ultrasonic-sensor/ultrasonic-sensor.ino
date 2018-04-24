int ledPin = 13;
int trigPin = 9;
int echoPin = 10;

long duration;
int distance;

int closestDist = 4;
int closeDist = 8;

void setup() {
	pinMode(ledPin, OUTPUT);
	pinMode(trigPin, OUTPUT);
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

	if (distance <= closestDist) {
		// Closest
		digitalWrite(ledPin, HIGH);
		delay(50);
		digitalWrite(ledPin, LOW);
	} else if (distance > closestDist && distance < closeDist) {
		// Close
		digitalWrite(ledPin, HIGH);
		delay(200);
		digitalWrite(ledPin, LOW);
		delay(250);
	} else if (distance >= closeDist) {
		// Far
		digitalWrite(ledPin, HIGH);
	}
	delay(50);
}
