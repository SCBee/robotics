
// CONSTANT GLOBAL VARS
int motorPin = 3;
int pushButtonPin = 8;
int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin, OUTPUT);
  pinMode(pushButtonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Read Button State
  buttonState = digitalRead(pushButtonPin);

  // Check Button State: Motor ON if Button PRESSED, Otherwise OFF
  if (buttonState == HIGH)
  {
    digitalWrite(motorPin, HIGH);
  }
  else
  {
    digitalWrite(motorPin, LOW);
  }
}
