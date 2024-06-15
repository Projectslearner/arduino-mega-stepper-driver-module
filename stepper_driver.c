/*
    Project name : Stepper Driver Module
    Modified Date: 15-06-2024
    Code by : Projectslearner
    Website : https://projectslearner.com/learn/arduino-mega-stepper-driver-module
*/

// Define the pins for stepper motor control
const int stepPin = 9; // Step pin
const int dirPin = 8;  // Direction pin

void setup() {
  // Set the two pins as outputs
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  // Initialize Serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Set the direction of rotation (CW or CCW)
  digitalWrite(dirPin, HIGH); // Set direction to clockwise

  // Step the motor 200 steps in one direction (full revolution for a 200-step motor)
  for (int i = 0; i < 200; i++) {
    digitalWrite(stepPin, HIGH); // Trigger one step forward
    delayMicroseconds(1000);     // Delay between steps (adjust as needed)
    digitalWrite(stepPin, LOW);  // Pull step pin low to complete step
    delayMicroseconds(1000);     // Delay between steps (adjust as needed)
  }

  // Reverse direction
  digitalWrite(dirPin, LOW); // Set direction to counter-clockwise

  // Step the motor 200 steps in the opposite direction
  for (int i = 0; i < 200; i++) {
    digitalWrite(stepPin, HIGH); // Trigger one step forward
    delayMicroseconds(1000);     // Delay between steps (adjust as needed)
    digitalWrite(stepPin, LOW);  // Pull step pin low to complete step
    delayMicroseconds(1000);     // Delay between steps (adjust as needed)
  }

  // Add a delay before starting the next loop
  delay(1000);
}
