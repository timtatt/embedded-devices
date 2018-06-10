#!/usr/bin/env python
import time
import serial
ser = serial.Serial(
port='/dev/ttyACM0',
baudrate = 9600,
parity=serial.PARITY_NONE,
stopbits=serial.STOPBITS_ONE,
bytesize=serial.EIGHTBITS,
timeout=1
)

stringsSent = []


for i in range(0, 20):
    stringToSend = str(i)
    
    if (stringToSend == "EXIT"):
        break

    stringsSent.append(stringToSend)
    stringToSend = stringToSend.encode('utf-8');
    # Write the string to the Arduino
    ser.write(stringToSend)
    
##        while(ser.inWaiting() < len(stringToSend)):
##            pass
    # Read the string in the serial input buffer
    stringReceived = ser.read(len(stringToSend))
    print('Previous strings sent: ')
    for j in stringsSent:
        print(j);
    print('');
    print("String recieved from Arduino: ", stringReceived.decode('utf-8'))
