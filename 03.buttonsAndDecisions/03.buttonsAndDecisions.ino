/*
  Author: TEACHER SOLUTION

  Learning Intention:
  The students will read a Grove Button module and control a Grove LED module,
  applying binary selection logic (if, if else, if else if else, switch/case).

  Hardware (Grove cables to the base shield):
    Button module  -> D4
    LED module     -> D6
    Line Finder    -> D7  (swap for the button in the application task)

  Teacher notes:
    - Bug-hunt demo: change `==` to `=` in the button if and the LED locks on.
    - Application task: move BUTTON_PIN reads to LINE_PIN to drive the LED from
      the Line Finder (dark surface = HIGH on most Grove line finders).
*/

const int BUTTON_PIN = 4;  // Grove Button on D4 (reads HIGH while pressed)
const int LED_PIN = 6;     // Grove LED on D6
const int LINE_PIN = 7;    // Grove Line Finder on D7 (application task)

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LINE_PIN, INPUT);
  Serial.begin(115200);
  randomSeed(analogRead(A1));  // for the pretend sensor below (A1 unconnected)
}

void loop() {
  // --- Part 1: button controls LED (if / else) ---
  int buttonState = digitalRead(BUTTON_PIN);
  Serial.println(buttonState);   // 0 released, 1 pressed: plot it!

  if (buttonState == HIGH) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }

  // --- Part 2: else-if chain on a pretend sensor ---
  int reading = random(0, 100);
  Serial.print("Reading: ");
  Serial.println(reading);

  if (reading > 80) {
    Serial.println("  VERY HIGH");
  } else if (reading > 50) {
    Serial.println("  HIGH");
  } else if (reading > 20) {
    Serial.println("  MEDIUM");
  } else {
    Serial.println("  LOW");
  }

  // --- Part 3: switch/case on exact zones ---
  int zone = reading / 25;       // integer division: 0, 1, 2 or 3
  switch (zone) {
    case 0:
      Serial.println("  zone 0: lowest quarter");
      break;
    case 1:
      Serial.println("  zone 1");
      break;
    case 2:
      Serial.println("  zone 2");
      break;
    default:
      Serial.println("  zone 3: highest quarter");
      break;
  }

  // --- Part 4: boolean operators ---
  if (reading > 20 && reading < 80) {
    Serial.println("  in the safe band (20 to 80)");
  }
  if (buttonState == HIGH || reading > 90) {
    Serial.println("  button held OR reading above 90");
  }

  delay(1000);
}
