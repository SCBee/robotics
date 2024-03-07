// IR Line Tracking Sensing
// Purpose: Use the TCRT5000 IR Sensor to determine the current status within the path boundaries (black tape = path)

// IR sensor pins (r = right, m = middle, l = left)
int rPin = 2;
int mPin = 3;
int lPin = 4;

// LED pins (r = right, l = left)
int rLED = 10;
int lLED = 9;


void setup() {

  // Setting up pin modes

  // IR Sensor (INPUTS)
  pinMode(lPin, INPUT);
  pinMode(mPin, INPUT);
  pinMode(rPin, INPUT);

  // LEDs (OUTPUTS)
  pinMode(rLED, OUTPUT);
  pinMode(lLED, OUTPUT);

}

void loop() {

  // LEDS are turned off if nothing is detected.
  digitalWrite(rLED, LOW);
  digitalWrite(lLED, LOW);

  // Check if the left IR sensor is detecting the black tape (NO IR LIGHT DETECTED) -> LED turns on if true
  if (digitalRead(lPin) == LOW)
  {
    digitalWrite(lLED, HIGH);
  }

  // Check if the right IR sensor is detecting the black tape (NO IR LIGHT DETECTED) -> LED turns on if true
  if (digitalRead(rPin) == LOW)
  {
    digitalWrite(rLED, HIGH);
  }
}
