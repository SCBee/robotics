// Ultrasonic Distance Sensing
// Purpose: Use the HC-SR04 Ultrasonic Sensor to determine the distance between the sensor and an object in front of it.

// Assign Echo & Trigger pins
int echoPin = 3;
int trigPin = 2;

void setup() {

  // TRIGGER SETUP
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, HIGH);

  // ECHO SETUP
  pinMode(echoPin, INPUT);

  // Set up Serial Communication
  Serial.begin(9600);
}

void loop() {

  // Trigger the ultrasonic wave (Low -> High)
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin, HIGH);

  // Record Timing
  long echoDuration = pulseIn(echoPin, HIGH);

  // Distance (Distance = 1cm per 50ms)
  long distance = echoDuration / 50;

  // Print Distance to console
  Serial.println(distance);
}
