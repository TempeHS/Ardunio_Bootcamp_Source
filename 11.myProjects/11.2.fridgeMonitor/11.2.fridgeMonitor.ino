/*
  Author: TEACHER SOLUTION
  Learning Intention: Students will use a range of sensors to create a monitoring
  system with either a visual or audio UI

  Solution: FRIDGE MONITOR.
    - Light sensor (A3) detects the door opening (light floods in).
    - If the door stays open longer than 10 seconds, the buzzer (D5) alarms
      and the LED (D6) flashes until the door closes.
    - Uses the millis() pattern throughout: nothing blocks.

  Logic flowchart (required in the commit): see the student's design work;
  the flow is read light -> door open? -> timer running? -> alarm after 10 s.

  Grove ports: Light A3, Buzzer D5, LED D6.
*/

const int LIGHT_PIN = A3;
const int BUZZER_PIN = 5;
const int LED_PIN = 6;

// Use YOUR measured values: closed-fridge dark vs door-open bright
const int DOOR_OPEN_THRESHOLD = 400;
const unsigned long ALARM_AFTER = 10000;   // 10 seconds
const long FLASH_INTERVAL = 250;

bool doorOpen = false;
unsigned long doorOpenedAt = 0;
unsigned long previousFlash = 0;
int ledState = LOW;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  unsigned long now = millis();
  int light = analogRead(LIGHT_PIN);
  bool openNow = (light > DOOR_OPEN_THRESHOLD);

  // Door state transitions
  if (openNow && !doorOpen) {
    doorOpen = true;
    doorOpenedAt = now;              // start the too-long timer
    Serial.println("Door opened");
  } else if (!openNow && doorOpen) {
    doorOpen = false;
    digitalWrite(LED_PIN, LOW);      // all clear
    noTone(BUZZER_PIN);
    Serial.println("Door closed");
  }

  // Alarm when open too long
  if (doorOpen && (now - doorOpenedAt >= ALARM_AFTER)) {
    if (now - previousFlash >= FLASH_INTERVAL) {
      previousFlash = now;
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
      tone(BUZZER_PIN, ledState ? 1000 : 600, FLASH_INTERVAL);
    }
  }

  // Plot light level and door state together
  Serial.print(light);
  Serial.print(" ");
  Serial.println(doorOpen ? 1000 : 0);
  delay(50);
}
