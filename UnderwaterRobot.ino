// Pin Definitions
const int upMotorPin = 2;       // Pin for Motor 1 (Up)
const int downMotorPin = 3;     // Pin for Motor 2 (Down)
const int forwardMotorPin = 4;   // Pin for Motor 3 (Forward)
const int backwardMotorPin = 5;  // Pin for Motor 4 (Backward)

// Joystick Pins
const int joyXPin = A0;         // X-axis pin
const int joyYPin = A1;         // Y-axis pin

void setup() {
  // Set motor pins as OUTPUT
  pinMode(upMotorPin, OUTPUT);
  pinMode(downMotorPin, OUTPUT);
  pinMode(forwardMotorPin, OUTPUT);
  pinMode(backwardMotorPin, OUTPUT);
  
  // Start with motors off
  stopMotors();
}

void loop() {
  // Read joystick values
  int joyXValue = analogRead(joyXPin);
  int joyYValue = analogRead(joyYPin);

  // Map joystick values to motor controls
  // Dead zone for joystick
  int deadZone = 100;

  // Control up/down motors
  if (joyYValue < 512 - deadZone) {  // Move up
    digitalWrite(upMotorPin, HIGH);
    digitalWrite(downMotorPin, LOW);
  } else if (joyYValue > 512 + deadZone) {  // Move down
    digitalWrite(upMotorPin, LOW);
    digitalWrite(downMotorPin, HIGH);
  } else {  // Stop vertical movement
    digitalWrite(upMotorPin, LOW);
    digitalWrite(downMotorPin, LOW);
  }

  // Control forward/backward motors
  if (joyXValue < 512 - deadZone) {  // Move forward
    digitalWrite(forwardMotorPin, HIGH);
    digitalWrite(backwardMotorPin, LOW);
  } else if (joyXValue > 512 + deadZone) {  // Move backward
    digitalWrite(forwardMotorPin, LOW);
    digitalWrite(backwardMotorPin, HIGH);
  } else {  // Stop horizontal movement
    digitalWrite(forwardMotorPin, LOW);
    digitalWrite(backwardMotorPin, LOW);
  }
}

// Function to stop all motors
void stopMotors() {
  digitalWrite(upMotorPin, LOW);
  digitalWrite(downMotorPin, LOW);
  digitalWrite(forwardMotorPin, LOW);
  digitalWrite(backwardMotorPin, LOW);
}
