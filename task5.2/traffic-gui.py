import tkinter as tk;
from tkinter import ttk;
import RPi.GPIO as GPIO;

redPin = 18;
yellowPin = 14;
greenPin = 15;

GPIO.setmode(GPIO.BCM);
GPIO.setwarnings(False);

GPIO.setup(redPin, GPIO.OUT);
GPIO.setup(yellowPin, GPIO.OUT);
GPIO.setup(greenPin, GPIO.OUT);

class Application(tk.Frame):
    def __init__(self, master=None):
        tk.Frame.__init__(self, master);
        self.grid(ipadx=20,ipady=20);
        self.createWidgets();
    def createWidgets(self):
        self.color = tk.StringVar(self);
        self.red = ttk.Radiobutton(self, text='Red', variable=self.color, value='red', command=self.changeColor);
        self.yellow = ttk.Radiobutton(self, text='Yellow', variable=self.color, value='yellow', command=self.changeColor);
        self.green = ttk.Radiobutton(self, text='Green', variable=self.color, value='green', command=self.changeColor);
        self.red.grid(row=0);
        self.yellow.grid(row=1);
        self.green.grid(row=2);
    def changeColor(self):
        GPIO.output(redPin, GPIO.LOW);
        GPIO.output(yellowPin, GPIO.LOW);
        GPIO.output(greenPin, GPIO.LOW);
        if (self.color.get() == 'red'):
            GPIO.output(redPin, GPIO.HIGH);
        elif (self.color.get() == 'yellow'):
            GPIO.output(yellowPin, GPIO.HIGH);
        elif (self.color.get() == 'green'):
            GPIO.output(greenPin, GPIO.HIGH);
            

app = Application();
app.master.title('Radio Buttons');
app.mainloop();