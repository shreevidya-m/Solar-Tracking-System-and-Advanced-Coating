#include <Servo.h>

// Define pin numbers for LDRs and servo motor
const int LDR_PIN_1 = A3;
const int LDR_PIN_2 = A4;
const int SERVO_PIN = 9;

// Define threshold for detecting light (adjust as needed)
const int LIGHT_THRESHOLD = 500;

// Create servo object
Servo servoMotor;

void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);

  // Attach servo to its pin
  servoMotor.attach(SERVO_PIN);

  // Print debug message indicating setup is complete
  Serial.println("Setup complete");
}

void loop() {
  // Read light intensity from LDRs
  int lightIntensity1 = analogRead(LDR_PIN_1);
  int lightIntensity2 = analogRead(LDR_PIN_2);
  
  // Print LDR values to Serial Monitor for debugging
  Serial.print("LDR Value 1: ");
  Serial.println(lightIntensity1);
  Serial.print("LDR Value 2: ");
  Serial.println(lightIntensity2);

  // Calculate difference in light intensity between LDRs
  int lightDifference = abs(lightIntensity1 - lightIntensity2);
  
  // Print light difference for debugging
  Serial.print("Light Difference: ");
  Serial.println(lightDifference);

  // Check if light intensity difference is above threshold
  if (lightDifference > LIGHT_THRESHOLD) {
    // Calculate target angle for servo motor (0 to 90 degrees)
    int targetAngle = map(lightDifference, 0, 1023, 0, 180);
  
    // Print target angle for debugging
    Serial.print("Target Angle: ");
    Serial.println(targetAngle);

    // Move servo motor to target angle
    servoMotor.write(targetAngle);
  }

  // Delay for stability (adjust as needed)
  delay(100);
}
