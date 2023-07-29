#import serial

#s = serial.Serial('COM7', 115200, timeout=10)
#print("Opening: " + s.name)
#from Tkinter import *
#import tkFont
#import tkMessageBox
#s.reset_output_buffer()
#s.reset_input_buffer()
#s.write('s'.encode())

import serial

s = serial.Serial('COM9', 38400)
s.reset_input_buffer()

import tkinter as tk
from tkinter import *
import tkinter.messagebox

top = tkinter.Tk()
top.geometry("800x500")
def helloCallBack():
   tkinter.messagebox.showinfo( "Hello Python", "Hello World")
   #s.write(bytes(1))

def left_button():
   value = "45"
   s.write(value.encode())

def right_button():
   value = "135"
   s.write(value.encode())

def middle_button():
   value = "90"
   s.write(value.encode())

def go():
   value = "go"
   s.write(value.encode())

def slider_changed(event):  
    print(slider.get())
    value = str(slider.get())
    s.write(value.encode())

slider = tk.Scale(top, from_=0, to=100, orient='horizontal', variable=90, command=slider_changed)

left = tkinter.Button(top, text ="Left", command = left_button)
right = tkinter.Button(top, text ="Right", command = right_button)
middle = tkinter.Button(top, text ="middle", command = middle_button)
gas = tkinter.Button(top, text ="go", command = go)

left.pack()
right.pack()
middle.pack()
gas.pack()
left.place(x = 50,y = 50)
right.place(x= 100, y = 50)
middle.place(x=75, y = 0)
gas.place(x=75, y = 100)
slider.grid(
    column=100,
    row=100,
    sticky='we'
)
top.mainloop()

