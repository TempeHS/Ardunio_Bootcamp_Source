/*
  Author: TEACHER SOLUTION
  Learning Intention: Students will use a range of simple sensors to control an LED UI

  Solution: HOLD-TO-LATCH light switch (the "unconventional" input use).
    - Tap the button: nothing happens.
    - HOLD the button for 2 seconds: the light latches ON (stays on when released).
    - Hold again for 2 seconds: the light latches OFF.
    - The pot sets the latched brightness as a dimmer with zones.

  Grove ports: Button D4, Potentiometer A0, LED D6 (PWM).
*/

const int BUTTON_PIN = 4;
const int POT_PIN = A0;
const int LED_PIN = 6;

const unsigned long HOLD_TIME = 2000;   // ms the button must be held

bool lightOn = false;
bool wasPressed = false;
unsigned long pressStarted = 0;
bool latchedThisPress = false;

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  bool pressed = (digitalRead(BUTTON_PIN) == HIGH);
  unsigned long now = millis();

  // Track the start of each press (millis pattern, no blocking)
  if (pressed && !wasPressed) {
    pressStarted = now;
    latchedThisPress = false;
  }

  // Held long enough during THIS press, and not yet toggled? Latch.
  if (pressed && !latchedThisPress && (now - pressStarted >= HOLD_TIME)) {
    lightOn = !lightOn;
    latchedThisPress = true;
    Serial.println(lightOn ? "Latched ON" : "Latched OFF");
  }

  wasPressed = pressed;

  if (lightOn) {
    // Pot as a zoned dimmer: 4 brightness zones instead of a smooth fade
    int potValue = analogRead(POT_PIN);
    int zone = potValue / 256;                    // 0, 1, 2 or 3
    int brightness = map(zone, 0, 3, 60, 255);    // dim, low, mid, full
    analogWrite(LED_PIN, brightness);
  } else {
    analogWrite(LED_PIN, 0);
  }
}
