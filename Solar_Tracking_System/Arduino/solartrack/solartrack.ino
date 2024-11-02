#include <Servo.h>

const int LDR_PIN_1 = A0;   // First LDR pin
const int LDR_PIN_2 = A1;   // Second LDR pin
const int SERVO_PIN = 9;    // Servo motor pin

Servo servoMotor;

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  servoMotor.attach(SERVO_PIN);
  Serial.println("Setup complete");  // Attach servo motor to its pin
}


void loop(){
  int ldrValue1 = analogRead(LDR_PIN_1);
  int ldrValue2 = analogRead(LDR_PIN_2);
  
  // Print LDR values to Serial Monitor for debugging
  Serial.print("LDR Value 1: ");
  Serial.println(ldrValue1);
  Serial.print("LDR Value 2: ");
  Serial.println(ldrValue2);

  // Map LDR values to servo angle (adjust these values as needed)
  int servoAngle = map(ldrValue1-ldrValue2, 0, 1023, 0, 180);

  // Print mapped servo angle for debugging
  Serial.print("Servo Angle: ");
  Serial.println(servoAngle);

  // Set servo position
  servoMotor.write(servoAngle);

  // Add a delay to slow down the loop for debugging
  delay(1000);
} // Read LDR values