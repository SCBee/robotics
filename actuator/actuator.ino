// LED Pins per finger
const int index = 3;
const int middle = 4;
const int ring = 5;
const int pinky = 6;

void setup() {
  // Begin Serial comms and clear buffer
  Serial.begin(9600);
  Serial.flush();

  // RNG seed
  randomSeed(analogRead(0));

  // Set led pin modes
  pinMode(index, OUTPUT);
  pinMode(middle, OUTPUT);
  pinMode(ring, OUTPUT);
  pinMode(pinky, OUTPUT);
}

void loop() {
  // Check if there is incoming data, only do something if there is
  if (Serial.available() > 0)
  {
    // Read comm data and convert to integer
    int val = char(Serial.read())-'0';

    // Debug logging
    Serial.println(val);

    // index
    if (val == 1) {
      digitalWrite(index, HIGH);
    }
    // middle
    else if (val == 2) {
      digitalWrite(middle, HIGH);
    }
    // ring
    else if (val == 3) {
      digitalWrite(ring, HIGH);
    }
    // pinky
    else if (val == 4) {
      digitalWrite(pinky, HIGH);
    }
    // fist
    else if (val == 5) {
      digitalWrite(index, HIGH);
      digitalWrite(middle, HIGH);
      digitalWrite(ring, HIGH);
      digitalWrite(pinky, HIGH);
    }
    // none
    else {
      digitalWrite(index, LOW);
      digitalWrite(middle, LOW);
      digitalWrite(ring, LOW);
      digitalWrite(pinky, LOW);
    }

    // Slow down updates. Decrease the value for quicker blinks.
    delay(200);
  }
}