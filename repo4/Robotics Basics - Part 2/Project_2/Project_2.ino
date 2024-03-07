// Project 2: Automated Object Avoidance Protocol
// Purpose: Utilize the ultrasonic sensor to determine the presence of objects in path, then steer accordingly.

#include <Servo.h>

// Motor Pins
int ENAp = 6; int ENBp = 5;
int N1p = 11; int N2p = 9;
int N3p = 8; int N4p = 7;

// Ultrasonic Sensor Pins
int echoPin = A4;
int trigPin = A5;

// Servo Object
Servo labservo;

void setup() {
  // Setting pin modes for motors + wheels
  pinMode(ENAp, OUTPUT);
  pinMode(ENBp, OUTPUT);
  pinMode(N1p, OUTPUT);
  pinMode(N2p, OUTPUT);
  pinMode(N3p, OUTPUT);
  pinMode(N4p, OUTPUT);

  // Setting motor strength (0-255)
  analogWrite(ENAp, 128);
  analogWrite(ENBp, 128);

  // Attach servo object to pin
  int servoPin = 3;
  labservo.attach(servoPin);

  // Ultrasonic Setup (trigger + echo)
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, HIGH);
  pinMode(echoPin, INPUT);

  // Serial Communication Setup
  Serial.begin(9600);
}

void loop() {

  if (getDistance() <= 20)
  {
    go(-1); // Reverse
    delay(1000);
    go(0); // Stop

    // turn right
    if (checkSides() == 1)
    {
      turn(1);
    }
    // turn left
    else if (checkSides() == 0)
    {
      turn(-1);
    }
  }
  else
  {
    go(1); // forward
  }
}

void rotateServo(int angle)
{
  // Angle & Direction relations:
  //      0 = RIGHT
  //      90 = FORWARD
  //      180 = LEFT
  
  // Write servo angle
  while(labservo.read() != angle)
  { 
    // Angle vector (normalized potentiometer value and servo angle) will be smoothened out
    // Total angle differential will be broken into +5/-5 degree intervals

    if(abs(labservo.read() - angle) > 5)
    {
      // Add/Subtract 5 degrees depending on the sign of the differential (Smoothing)
      labservo.write(((angle - labservo.read()) > 0) ? (labservo.read() + 5) : (labservo.read() - 5));
    }
    else
    {
      // Differentials less than 5 degrees will be small enough to directly write the desired angle (no smoothing required)
      labservo.write(angle);
    }
  }
}

void go(int direction)
{
  // direction values:
  //      1 = forward
  //      0 = stop
  //      -1 = backward

  rotateServo(90);

  if (direction == 1)
  {
    digitalWrite(N1p, HIGH);
    digitalWrite(N2p, LOW);
    digitalWrite(N3p, LOW);
    digitalWrite(N4p, HIGH);
  }
  else if (direction == 0)
  {
    digitalWrite(N1p, LOW);
    digitalWrite(N2p, LOW);
    digitalWrite(N3p, LOW);
    digitalWrite(N4p, LOW);
  }
  else if (direction == -1)
  {
    digitalWrite(N1p, LOW);
    digitalWrite(N2p, HIGH);
    digitalWrite(N3p, HIGH);
    digitalWrite(N4p, LOW);
  }
}

void turn(int dir)
{
  // dir = 1 --> right
  // dir = -1 --> left

  // right
  if (dir == 1)
  {
    digitalWrite(N1p, LOW);
    digitalWrite(N2p, HIGH);
    digitalWrite(N3p, LOW);
    digitalWrite(N4p, HIGH);
    delay(1000);
    digitalWrite(N1p, LOW);
    digitalWrite(N2p, LOW);
    digitalWrite(N3p, LOW);
    digitalWrite(N4p, LOW);
  }
  // left
  else if (dir == -1)
  {
    digitalWrite(N1p, HIGH);
    digitalWrite(N2p, LOW);
    digitalWrite(N3p, HIGH);
    digitalWrite(N4p, LOW);
    delay(1000);
    digitalWrite(N1p, LOW);
    digitalWrite(N2p, LOW);
    digitalWrite(N3p, LOW);
    digitalWrite(N4p, LOW);

  }
}

long getDistance()
{  
  // Trigger the ultrasonic wave (Low -> High)
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin, HIGH);
  
  // Record Timing
  long echoDuration = pulseIn(echoPin, HIGH);
  
  // Distance (Distance = 1cm per 50ms)
  long distance = echoDuration / 50;

  if (distance == 0)
    distance = 30;

  return distance;
}

int checkSides()
{
  // Rotate Servo to the right
  rotateServo(0);
  delay(500);
  long right = getDistance();

  delay(100);

  // Rotate Servo to the left
  rotateServo(180);
  delay(500);
  long left = getDistance();

  delay(100);

  return ((right >= left) ? 1 : 0);
}
