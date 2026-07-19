/*
  Author: TEACHER SOLUTION
  Learning Intention: Students will use a range of sensors to create a monitoring
  system with either a visual or audio UI

  Solution: FRIDGE MONITOR.
    - Light sensor (A3) detects the door opening (light floods in).
    - If the door stays open longer than 10 seconds, the buzzer (D5) alarms
      and the LED (D6) flashes until the door closes.
    - Fully non-blocking: the millis() pattern paces the alarm flash AND the
      Serial Plotter output. There is no delay() anywhere in the loop.

  Logic flowchart (required in the commit): see the student's design work;
  the flow is read light -> door state changed? -> open too long? -> alarm.

  Grove ports: Light A3, Buzzer D5, LED D6.
*/

const int LIGHT_PIN = A3;
const int BUZZER_PIN = 5;
const int LED_PIN = 6;

const int DOOR_OPEN_THRESHOLD = 20;       // measure your own dark/bright values
const unsigned long ALARM_AFTER = 10000;  // 10 seconds
const unsigned long FLASH_INTERVAL = 250;
const unsigned long PLOT_INTERVAL = 50;

bool doorOpen = false;
unsigned long doorOpenedAt = 0;
unsigned long previousFlash = 0;
unsigned long previousPlot = 0;
bool ledState = false;

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
  if (openNow != doorOpen) {
    doorOpen = openNow;
    if (doorOpen) {
      doorOpenedAt = now;
      Serial.println("Door opened");
    } else {
      digitalWrite(LED_PIN, LOW);
      noTone(BUZZER_PIN);
      Serial.println("Door closed");
    }
  }

  // Alarm when open too long
  if (doorOpen && (now - doorOpenedAt >= ALARM_AFTER)) {
    if (now - previousFlash >= FLASH_INTERVAL) {
      previousFlash = now;
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
      if (ledState)
        tone(BUZZER_PIN, 1000);
      else
        noTone(BUZZER_PIN);
    }
  }

  // Plot light level and door state (non-blocking)
  if (now - previousPlot >= PLOT_INTERVAL) {
    previousPlot = now;
    Serial.print(light);
    Serial.print(" ");
    Serial.println(doorOpen ? 1000 : 0);
  }
}
