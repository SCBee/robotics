int ledPin = 2;
int potPin = A1;
int potVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);

  Serial.println(potVal);


  digitalWrite(2, HIGH);
  delay(potVal);
  digitalWrite(2, LOW);
  delay(potVal);
}
