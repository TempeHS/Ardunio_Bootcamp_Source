/*
  Author: TEACHER SOLUTION
  Learning Intention: Students will use an ultrasonic sensor to control a servo motor

  Solution: BOOM GATE with TWO logic approaches (required comparison).
    Set USE_STATE_MACHINE to switch between them.

    Approach A (simple threshold):
      Gate opens whenever distance < 25 cm, closes as soon as it is clear.
      PROBLEM: the gate slams shut the instant the car edge passes, and jitters
      when readings flicker around the threshold.

    Approach B (state machine):
      CLOSED -> OPENING -> HOLD (while vehicle present) -> CLEAR-WAIT (3 s) -> CLOSING.
      Handles the edge cases: a car stopped under the gate keeps it open, and a
      second car arriving during the clear-wait resets the timer.

  Grove ports: Ultrasonic D2 (single signal pin), Servo D3, LED D6 (moving warning).
*/

#include <Servo.h>
#include "Ultrasonic.h"

const bool USE_STATE_MACHINE = true;

Ultrasonic ultrasonic(2);
Servo gateServo;

const int SERVO_PIN = 3;
const int LED_PIN = 6;
const int DETECT_CM = 25;               // vehicle detected inside this distance
const unsigned long CLEAR_WAIT = 3000;  // road must stay clear this long

const int GATE_DOWN = 0;
const int GATE_UP = 90;

// State machine states
enum GateState { CLOSED, OPEN_HOLD, CLEAR_WAIT_STATE };
GateState state = CLOSED;
unsigned long clearSince = 0;

void moveGate(int angle) {
  digitalWrite(LED_PIN, HIGH);          // warning light while moving
  gateServo.write(angle);
  delay(600);                           // give the arm time to travel
  digitalWrite(LED_PIN, LOW);
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  gateServo.attach(SERVO_PIN);
  gateServo.write(GATE_DOWN);
}

void loop() {
  int distance = ultrasonic.read();
  bool vehicle = (distance > 0 && distance < DETECT_CM);
  unsigned long now = millis();

  if (!USE_STATE_MACHINE) {
    // ---------- Approach A: simple threshold ----------
    if (vehicle) {
      moveGate(GATE_UP);
    } else {
      moveGate(GATE_DOWN);
    }
  } else {
    // ---------- Approach B: state machine ----------
    switch (state) {
      case CLOSED:
        if (vehicle) {
          moveGate(GATE_UP);
          state = OPEN_HOLD;
        }
        break;

      case OPEN_HOLD:                       // hold while the vehicle is present
        if (!vehicle) {
          clearSince = now;                 // road just became clear: start timer
          state = CLEAR_WAIT_STATE;
        }
        break;

      case CLEAR_WAIT_STATE:
        if (vehicle) {
          state = OPEN_HOLD;                // second car arrived: hold again
        } else if (now - clearSince >= CLEAR_WAIT) {
          moveGate(GATE_DOWN);              // clear for 3 full seconds: close
          state = CLOSED;
        }
        break;
    }
  }

  Serial.print(distance);
  Serial.print(" ");
  Serial.println(state);
  delay(100);
}
