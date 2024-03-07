int motorPin = 3;
int potPin = A0;
int potVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Read potentiometer value
  potVal = analogRead(potPin);

  //Serial.println(potVal);

  // Map out value of potentiometer and normalize it from 0 - 255
  int y = map(potVal, 0, 1023, 0, 255);

  Serial.println(y);

  // Turn motor on depending on value read from potentiometer
  analogWrite(motorPin, y);
}
