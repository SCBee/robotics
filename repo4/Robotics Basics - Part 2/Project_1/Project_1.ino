// Project 1: Robot Moving Forward/Backward
// Purpose: Enable motors to move the robot forward and backward in a sequence.

// Pins for motor control
int ENAp = 6; int ENBp = 5; // Control
int N1p = 11; int N2p = 9; // RSW
int N3p = 8; int N4p = 7; // LSW

void setup() {
  // Setting pin modes for Motors
  pinMode(ENAp, OUTPUT);
  pinMode(ENBp, OUTPUT);

  // Setting pin modes for specific wheels (pins)
  pinMode(N1p, OUTPUT);
  pinMode(N2p, OUTPUT);
  pinMode(N3p, OUTPUT);
  pinMode(N4p, OUTPUT);

  // Setting motor strength
  analogWrite(ENAp, 128);
  analogWrite(ENBp, 128);
}

void loop() {

// FORWARD MOTION
  // (A) RSW -- 1 HIGH + 2 LOW = Forward
  digitalWrite(N1p, HIGH);
  digitalWrite(N2p, LOW);

  // B (LSW) -- 4 HIGH + 3 LOW = Forward
  digitalWrite(N3p, LOW);
  digitalWrite(N4p, HIGH);

  delay(3000);

// STALL
  digitalWrite(N1p, LOW);
  digitalWrite(N4p, LOW);
  delay(1000);

// BACKWARD MOTION
  // (A) RSW -- 1 LOW + 2 HIGH = Backward
  digitalWrite(N1p, LOW);
  digitalWrite(N2p, HIGH);

  // B (LSW) -- 4 LOW + 3 HIGH = Backward
  digitalWrite(N3p, HIGH);
  digitalWrite(N4p, LOW);

  delay(3000);

// STALL
  digitalWrite(N2p, LOW);
  digitalWrite(N3p, LOW);
  delay(1000);
}
