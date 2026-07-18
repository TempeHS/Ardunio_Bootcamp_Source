/*
  Author: TEACHER SOLUTION

  Learning Intention:
  The students will connect and control a positional servo motor with the Servo library.

  Hardware:
    Servo          -> Grove connector to D3 (yellow = signal)
    Potentiometer  -> A0

  Teacher notes:
    - Out-of-range demo: myServo.write(200) simply moves to 180: the library
      constrains the value. No error, no smoke.
    - Set POT_MODE false to run the automatic sweep instead of knob control.
*/

#include <Servo.h>

const int SERVO_PIN = 3;  // Grove connector to D3 (PWM capable)
const int POT_PIN = A0;   // Grove Potentiometer on A0

const bool POT_MODE = true;

Servo myServo;

void smoothMove(int fromAngle, int toAngle) {
  if (fromAngle < toAngle) {
    for (int a = fromAngle; a <= toAngle; a++) {
      myServo.write(a);
      delay(15);
    }
  } else {
    for (int a = fromAngle; a >= toAngle; a--) {
      myServo.write(a);
      delay(15);
    }
  }
}

void setup() {
  Serial.begin(9600);
  myServo.attach(SERVO_PIN);
  myServo.write(90);        // start at the middle
  delay(500);
}

void loop() {
  if (POT_MODE) {
    // --- Challenge 1: pot steers the servo ---
    int potValue = analogRead(POT_PIN);           // 0 to 1023
    int angle = map(potValue, 0, 1023, 0, 180);   // 0 to 180
    myServo.write(angle);

    Serial.print(potValue);
    Serial.print(" ");
    Serial.println(angle);
    delay(15);                                    // give the servo time to follow
  } else {
    // --- Challenge 2: automatic smooth sweep ---
    smoothMove(0, 180);
    smoothMove(180, 0);
  }
}
