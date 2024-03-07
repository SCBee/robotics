// Micro Servo Sweep
// Purpose: Micro Servo Motor performs 180 degree sweeps with 5 degree steps.

#include <Servo.h>

// Create Servo object
Servo labservo;

void setup() {
  
  // Assign servo pin (digital)
  int pin = 2;

  // Set Servo to read from pin
  labservo.attach(pin);
}

void loop() {
  
  // Angles = 0 -> 180
  for (int i = 0; i < 37; ++i)
  {
    // Calculate next angle
    int angle = i*5;

    // Send angle to servo
    labservo.write(angle);

    delay(5);
  }

  delay(1000);

  // Angles = 180 -> 0
  for (int i = 36; i >= 0; --i)
  {
    // Calculate next angle
    int angle = i*5;

    // Send angle to servo
    labservo.write(angle);

    delay(5);
  }

  delay(1000);
}
