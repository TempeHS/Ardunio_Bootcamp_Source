/*
  Author: TEACHER SOLUTION

  Learning Intention:
  The students will apply loop logic (count, pre-test and post-test loops) and manage
  time responsively with millis() instead of blocking with delay().

  Hardware (Grove cables to the base shield):
    Button module  -> D4
    Buzzer module  -> D5
    LED module     -> D6

  Teacher notes:
    - setup() demonstrates every loop structure once on the Serial Monitor,
      then plays the two-loop buzzer siren.
    - loop() is the non-blocking millis() pattern: LED blinks at 1 Hz, buzzer
      heartbeat every 3 s, button responsive the whole time.
    - REACTION_TIMER_MODE switches loop() to the reaction timer game.
*/

const int BUTTON_PIN = 4;  // Grove Button on D4
const int BUZZER_PIN = 5;  // Grove Buzzer on D5
const int LED_PIN = 6;     // Grove LED on D6

const bool REACTION_TIMER_MODE = false;

// millis() pattern state
unsigned long previousBlink = 0;
unsigned long previousBeep = 0;
const long BLINK_INTERVAL = 1000;
const long BEEP_INTERVAL = 3000;
int ledState = LOW;

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  randomSeed(analogRead(A1));   // seed from unconnected pin noise (A1 is free)

  // --- FOR (count loop) ---
  Serial.println("Counting up:");
  for (int i = 0; i < 10; i++) {
    Serial.println(i);
  }

  // --- FOR-EACH over an array ---
  int readings[] = {310, 512, 498, 730, 220};
  Serial.println("Sensor log:");
  for (int r : readings) {
    Serial.println(r);
  }

  // --- WHILE (pre-test): body may run zero times ---
  int countdown = 5;
  while (countdown > 0) {
    Serial.println(countdown);
    countdown = countdown - 1;   // forget this line = infinite loop!
  }
  Serial.println("Liftoff!");

  // --- DO-WHILE (post-test): body always runs at least once ---
  int n = 0;
  do {
    Serial.println("do-while body ran (even though n > 0 is false)");
    n = n - 1;
  } while (n > 0);

  // --- Buzzer siren: two count loops driving a real actuator ---
  for (int sweep = 0; sweep < 2; sweep++) {
    for (int pitch = 200; pitch < 1000; pitch += 10) {
      tone(BUZZER_PIN, pitch);
      delay(10);
    }
    for (int pitch = 1000; pitch > 200; pitch -= 10) {
      tone(BUZZER_PIN, pitch);
      delay(10);
    }
  }
  noTone(BUZZER_PIN);

  // --- Random demo: same seed = same sequence, so we seeded above ---
  Serial.println("Five dice rolls:");
  for (int i = 0; i < 5; i++) {
    Serial.println(random(1, 7));   // 1 to 6: maximum is exclusive
  }
}

void loop() {
  if (!REACTION_TIMER_MODE) {
    // --- Non-blocking multitasking with millis() ---
    unsigned long now = millis();

    if (now - previousBlink >= BLINK_INTERVAL) {
      previousBlink = now;
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
    }

    if (now - previousBeep >= BEEP_INTERVAL) {
      previousBeep = now;
      tone(BUZZER_PIN, 880, 100);   // short heartbeat beep
    }

    // Button is checked EVERY cycle: no press is ever missed
    if (digitalRead(BUTTON_PIN) == HIGH) {
      Serial.println("Button pressed!");
    }
  } else {
    // --- Reaction timer game ---
    digitalWrite(LED_PIN, LOW);
    delay(random(2000, 5000));          // blocking is fine pre-game
    digitalWrite(LED_PIN, HIGH);        // GO!

    unsigned long startTime = millis();
    while (digitalRead(BUTTON_PIN) == LOW) {
      // wait for the press
    }
    unsigned long reaction = millis() - startTime;

    Serial.print("Reaction time: ");
    Serial.print(reaction);
    Serial.println(" ms");
    if (reaction < 250) {
      tone(BUZZER_PIN, 1500, 300);      // fanfare for fast reactions
    }
    delay(1000);
  }
}
