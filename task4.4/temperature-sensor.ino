#include "Wire.h"
#define TMP102_I2C_ADDRESS 72

void setup() {
	Wire.begin();
	Serial.begin(115200);
}


void getTemp(){
	byte firstbyte, secondbyte;
	int val;
	float convertedtemp;
	float correctedtemp;

	Wire.beginTransmission(TMP102_I2C_ADDRESS);
	Wire.send(0x00);
	Wire.endTransmission();
	Wire.requestFrom(TMP102_I2C_ADDRESS, 2);
	Wire.endTransmission();


	firstbyte = (Wire.receive());
	secondbyte = (Wire.receive());

	val = firstbyte;
    if ((firstbyte & 0x80) > 0) {
    	val |= 0x0F00;
    } 
    val <<= 4;

	convertedtemp = val * 0.0625;
	correctedtemp = convertedtemp - 5;

	Serial.print("firstbyte is ");
	Serial.print("\t");
	Serial.println(firstbyte, BIN);
	Serial.print("secondbyte is ");
	Serial.print("\t");
	Serial.println(secondbyte, BIN);
	Serial.print("Concatenated byte is ");
	Serial.print("\t");
	Serial.println(val, BIN);
	Serial.print("Converted temp is ");
	Serial.print("\t");
	Serial.println(val*0.0625);
	Serial.print("Corrected temp is ");
	Serial.print("\t");
	Serial.println(correctedtemp);
	Serial.println();
}

void loop() {
	getTemp();
	delay(5000);
}