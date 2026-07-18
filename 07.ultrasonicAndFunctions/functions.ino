// TEACHER SOLUTION: helper functions for the proximity alarm.
// The Arduino build system joins every .ino in this folder into one program,
// so these functions are callable from the main sketch (abstraction in action).

// Returns the distance in centimetres (wraps the Ultrasonic library).
int readDistance() {
  return ultrasonic.read();
}

// Takes the distance and the two thresholds as PARAMETERS and RETURNS a zone:
// 0 = danger, 1 = warning, 2 = safe. Encapsulation: no globals involved.
int classifyZone(int distance, int nearLimit, int farLimit) {
  if (distance < nearLimit) {
    return 0;
  } else if (distance < farLimit) {
    return 1;
  }
  return 2;
}

// Acts on the zone: LED + buzzer urgency scale.
void showAlert(int zone) {
  if (zone == 0) {
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 1200, 80);   // urgent fast beeps (fires every loop pass)
  } else if (zone == 1) {
    digitalWrite(LED_PIN, HIGH);
    tone(BUZZER_PIN, 800, 40);    // slower warning chirps
    delay(200);
  } else {
    digitalWrite(LED_PIN, LOW);
    noTone(BUZZER_PIN);
  }
}

// Prints both values side by side for the Serial Plotter.
void logStatus(int distance, int zone) {
  Serial.print(distance);
  Serial.print(" ");
  Serial.println(zone);
}
