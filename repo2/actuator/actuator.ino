void setup() {
  // Begin Serial comms and clear buffer
  Serial.begin(9600);
  Serial.flush();
}

void loop() {
  const int ledPin = 3;

  // Check if there is incoming data, only do something if there is
  if (Serial.available() > 0)
  {
    // Read comm data and convert to integer
    int val = char(Serial.read())-'0';

    // Debug logging
    Serial.println(val);

    // Example use
    if (val == 1) {
      digitalWrite(ledPin, HIGH);
    }
    else {
      digitalWrite(ledPin, LOW);
    }
  }
}