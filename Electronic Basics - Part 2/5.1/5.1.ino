void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:

  analogWrite(3, 127);
  delay(2000);
  digitalWrite(3, 0);
  delay(2000);
}
