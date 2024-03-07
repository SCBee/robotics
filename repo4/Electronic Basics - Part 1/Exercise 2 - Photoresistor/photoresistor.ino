int ledPin = 2;
int phPin = A1;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(ledPin, OUTPUT);
  pinMode(phPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  int phState = analogRead(phPin);

  //Serial.println(phState); // Used this to check what my ambient light value is to determine dark/bright threshold.

  if (phState <= 150) // My room has a value of around 195 so I am using 150 as my threshold since it makes it easier to test my program.
  {
    digitalWrite(ledPin, HIGH);
    Serial.println("DARK --> LED ON");
  }
  else
  {
    digitalWrite(ledPin, LOW);
    Serial.println("BRIGHT --> LED OFF");
  }
}
