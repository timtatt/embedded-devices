import tkinter as tk;
from tkinter import ttk;
import RPi.GPIO as GPIO;
import time;

ledPin = 15;

GPIO.setmode(GPIO.BCM);
GPIO.setwarnings(False);

GPIO.setup(ledPin, GPIO.OUT);

unitLength = 0.2;
dotWait = unitLength;
dashWait = unitLength * 3;
letterWait = unitLength * 2;
wordWait = unitLength * 7;

class Application(tk.Frame):
    def __init__(self, master=None):
        tk.Frame.__init__(self, master);
        self.grid(ipadx=20,ipady=20);
        self.createWidgets();
    def createWidgets(self):
        self.morseWord = tk.StringVar(self);
        self.morseTextInput = ttk.Entry(textvariable=self.morseWord);
        self.morseButton = ttk.Button(text='Output Morse', command=self.outputMorseCode);

        self.morseTextInput.grid(row=0, column=0);
        self.morseButton.grid(row=0, column=1);
    def outputMorseCode(self):
        words = self.morseWord.get().split(' ');
        for word in words:
            for letter in word:
                self.letter(letter.lower());
            time.sleep(wordWait);
    def dot(self):
        GPIO.output(ledPin, GPIO.HIGH);
        time.sleep(dotWait);
        GPIO.output(ledPin, GPIO.LOW);
        time.sleep(dotWait);
    def dash(self):
        GPIO.output(ledPin, GPIO.HIGH);
        time.sleep(dashWait);
        GPIO.output(ledPin, GPIO.LOW);
        time.sleep(dotWait);
    def letter(self, letter):
        if (letter == 'a'):
            self.dot();
            self.dash();
        elif (letter == 'b'):
            self.dash();
            self.dot();
            self.dot();
            self.dot();
        elif (letter == 'c'):
            self.dash();
            self.dot();
            self.dash();
            self.dot();
        elif (letter == 'd'):
            self.dash();
            self.dot();
            self.dot();
        elif (letter == 'e'):
            self.dot();
        elif (letter == 'f'):
            self.dot();
            self.dot();
            self.dash();
            self.dot();
        elif (letter == 'g'):
            self.dash();
            self.dash();
            self.dot();
        elif (letter == 'h'):
            self.dot();
            self.dot();
            self.dot();
            self.dot();
        elif (letter == 'i'):
            self.dot();
            self.dot();
        elif (letter == 'j'):
            self.dot();
            self.dash();
            self.dash();
            self.dash();
        elif (letter == 'k'):
            self.dash();
            self.dot();
            self.dash();
        elif (letter == 'l'):
            self.dot();
            self.dash();
            self.dot();
            self.dot();
        elif (letter == 'm'):
            self.dash();
            self.dash();
        elif (letter == 'n'):
            self.dash();
            self.dot();
        elif (letter == 'o'):
            self.dash();
            self.dash();
            self.dash();
        elif (letter == 'p'):
            self.dot();
            self.dash();
            self.dash();
            self.dot();
        elif (letter == 'q'):
            self.dash();
            self.dash();
            self.dot();
            self.dash();
        elif (letter == 'r'):
            self.dot();
            self.dash();
            self.dot();
        elif (letter == 's'):
            self.dot();
            self.dot();
            self.dot();
        elif (letter == 't'):
            self.dash();
        elif (letter == 'u'):
            self.dot();
            self.dot();
            self.dash();
        elif (letter == 'v'):
            self.dot();
            self.dot();
            self.dot();
            self.dash();
        elif (letter == 'w'):
            self.dot();
            self.dash();
            self.dash();
        elif (letter == 'x'):
            self.dash();
            self.dot();
            self.dot();
            self.dash();
        elif (letter == 'y'):
            self.dash();
            self.dot();
            self.dash();
            self.dash();
        elif (letter == 'z'):
            self.dash();
            self.dash();
            self.dot();
            self.dot();
        time.sleep(letterWait);
            
app = Application();
app.master.title('Radio Buttons');
app.mainloop();