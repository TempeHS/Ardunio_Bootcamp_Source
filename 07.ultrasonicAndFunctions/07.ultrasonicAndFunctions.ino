/*
  Author: TEACHER SOLUTION

  Learning Intention:
  The students will measure distance with the Grove 3-pin ultrasonic sensor using a
  library, and structure their code with functions (parameters, return values, tabs).

  Hardware (Grove cables to the base shield):
    Ultrasonic sensor (3-pin) -> D2
    Buzzer module             -> D5
    LED module                -> D6

  Teacher notes:
    - The proximity alarm is fully decomposed: loop() is nothing but function
      calls, and all helpers live in functions.ino (criterion: tabs).
    - Zone thresholds (10 cm and 30 cm) are passed as PARAMETERS so students
      can see data flowing instead of hiding in globals.
*/

#include "Ultrasonic.h"

Ultrasonic ultrasonic(2);  // Grove 3-pin ultrasonic on D2 (single signal pin)

const int BUZZER_PIN = 5;  // Grove Buzzer on D5
const int LED_PIN = 6;     // Grove LED on D6

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int distance = readDistance();
  int zone = classifyZone(distance, 10, 30);
  showAlert(zone);
  logStatus(distance, zone);
  delay(100);
}
