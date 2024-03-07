// Control the servo motor arm using a potentiometer
// Purpose: The potentiometer will be read and used to determine the angle the servo motor arm should set to.

#include <Servo.h>

// Create Servo Object
Servo labservo;

// Potentiometer variables (pin & value)
int potPin = A2;
int potVal;

void setup() {
  
  // Attach Servo Object to Pin
  int servoPin = 2;
  labservo.attach(servoPin);

  // Set up Serial Communication for debugging
  //Serial.begin(9600);
}

void loop() {

  // Read potentiometer value
  potVal = analogRead(potPin);

  // Map pot value to [0, 180]
  int angle = map(potVal, 0, 1023, 0, 180);

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
