void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Turning Motor ON
  digitalWrite(3, HIGH);
  delay(2000);

  // Turning Motor OFF
  digitalWrite(3, LOW);
  delay(2000);
}
