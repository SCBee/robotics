# Imports
import win32api
import serial
from time import sleep

'''
  Library Breakdown:
    win32api -> Used for detecting user's keystrokes to send flags to the arduino
    serial --> Used to establish a serial communication with the mcu and send/receive data
    time.sleep --> Used for delays
'''

# ----------- Setup -----------
mcuSerialPort = "COM3" # Change this to the serial port for your arduino
mcuBaudRate = 9600 # Change this to your desired rate

# Begin serial comms and wait for it to establish
mcu = serial.Serial(mcuSerialPort, baudrate=mcuBaudRate)
sleep(1)

# ----------- EXAMPLE USE -----------

# This example assumes a simple led circuit with PIN-3 being connected to the positive terminal of the circuit.
# Note that the circuit should have a resistor connected in series with the LED.

run = True
while run:
  # END key | Terminate script and send DISABLE flag to board
  if win32api.GetAsyncKeyState(0x23):
    run = False
    mcu.write(b'0')
    sleep(1)
  
  # Mouse4 | Send ENABLE flag to board
  if win32api.GetAsyncKeyState(0x05):
    mcu.write(b'1')
    sleep(1)

  # Always DISABLE when there is no button pressed
  else:
    mcu.write(b'0')

# ----------------------------------
# Imports
import win32api
import serial
from time import sleep

'''
  Library Breakdown:
    win32api -> Used to get user input via keystrokes
    serial --> Used to establish a serial communication with the mcu and send/receive data
    time.sleep --> Used to set up delays
'''

# ----------- Setup -----------
mcuSerialPort = "COM6" # Change this to the serial port for your arduino
mcuBaudRate = 9600 # Change this to your desired rate

# Begin serial comms and wait for it to establish
mcu = serial.Serial(mcuSerialPort, baudrate=mcuBaudRate)
sleep(1)

# ----------- USE -----------

run = True
while run:
  if win32api.GetAsyncKeyState(0x23):
    run = False
    mcu.write(b'0')
    sleep(0.001)
  
  # Click mouse4 to enable macro
  if win32api.GetAsyncKeyState(0x05):
    mcu.write(b'1')
    sleep(0.001)