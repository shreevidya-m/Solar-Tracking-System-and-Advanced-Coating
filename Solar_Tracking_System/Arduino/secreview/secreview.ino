#include <Servo.h>

// Define the pin number for the servo motor
const int SERVO_PIN = 9;

// Create servo object
Servo servoMotor;

void setup() {
  // Attach servo to its pin
  servoMotor.attach(SERVO_PIN);

  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Sweep the servo motor from 0 to 180 degrees
  for (int angle = 0; angle <= 180; angle++) {
    servoMotor.write(angle); // Set servo angle
    delay(15); // Adjust speed of servo movement (lower delay for faster movement)
  }

  // Sweep the servo motor from 180 to 0 degrees
  for (int angle = 180; angle >= 0; angle--) {
    servoMotor.write(angle); // Set servo angle
    delay(15); // Adjust speed of servo movement (lower delay for faster movement)
  }
}