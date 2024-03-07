# hand-tracking-arduino

This is a small little project that incorporates ML and Arduino. I have been exploring computer vision with Python and Arduino and it's grown to become one of my favorite topics because of how interactive it is!

Recently, a couple of my friends have started programming and they wanted to do a project similar to those floating around on social media of controlling robots using hand gestures. Helping them inspired this project that I hope to give them and others a simple base-of-sorts to kickstart their projects!

### Functionality

This code will read data from a webcam and then determine which finger(s) are extended (or closed, depending on the orientation of your camera with your hand), and then rapidly blink leds connected to the arduino. Each LED corresponds to a specific finger.

### Requirements

This code should be used with a computer and an arduino together. The .ino file is uploaded to the arduino, and the main.py file is run by your pc!

The arduino code does not use any special libraries that are not a part of the Arduino IDE's ecosystem. The python libraries used are:

opencv2 (getting and transforming data from webcam)
mediapipe (ml hand-tracking model)
time (sleeps)
serial (communicating with the arduino)

### Extra notes

I loved this project because of how simple it is from an electrical perspective, while still allowing myself to explore a lot! I hope that those that are reading this can try and play around with it. The LED pins are 3, 4, 5, and 6, so if you do set it up, make sure to connect to those or modify the variables in the .ino file.

### DEMO

(These two videos happen concurrently)

![Hand View](https://github.com/SCBee/hand-tracking-arduino/blob/main/Demo/HAND_View.gif)

![PC View](https://github.com/SCBee/hand-tracking-arduino/blob/main/Demo/PC_View.gif)
