/*
  Author: TEACHER SOLUTION

  Learning Intention:
  The students will read analogue sensors, use math (map, constrain, integer division)
  to convert value ranges, and write analogue output using PWM to an LED and buzzer.

  Hardware (Grove cables to the base shield):
    Potentiometer  -> A0
    Sound sensor   -> A2
    Light sensor   -> A3
    LED module     -> D6  (PWM capable)
    Buzzer module  -> D5  (PWM capable)

  Teacher notes:
    - The prediction-table lines print once in setup: 3, 3.50, 14, 20, 1.
    - Main loop: pot maps to LED brightness; hold the button of your choice or
      re-comment to switch to the light-theremin stretch task.
    - Measured light range on a classroom desk is typically about 50 to 900:
      students must use THEIR measured min/max in the theremin map().
*/

const int POT_PIN = A0;    // Grove Potentiometer on A0
const int SOUND_PIN = A2;  // Grove Sound sensor on A2
const int LIGHT_PIN = A3;  // Grove Light sensor on A3
const int LED_PIN = 6;     // Grove LED on D6 (PWM)
const int BUZZER_PIN = 5;  // Grove Buzzer on D5 (PWM)

// Set true to play the light-theremin stretch task instead of pot-to-LED
const bool THEREMIN_MODE = false;

// Use YOUR measured light range here (cover the sensor, then torch it)
const int LIGHT_MIN = 50;
const int LIGHT_MAX = 900;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // --- The maths of sensors: predict, run, correct ---
  Serial.println(7 / 2);        // 3    integer division truncates
  Serial.println(7.0 / 2);      // 3.50 one float operand = float division
  Serial.println(2 + 3 * 4);    // 14   multiplication before addition
  Serial.println((2 + 3) * 4);  // 20   parentheses override the order
  Serial.println(7 % 3);        // 1    modulo = remainder
}

void loop() {
  if (!THEREMIN_MODE) {
    // --- Core build: pot controls LED brightness ---
    int potValue = analogRead(POT_PIN);                  // 0 to 1023
    int brightness = map(potValue, 0, 1023, 0, 255);     // 0 to 255
    brightness = constrain(brightness, 0, 255);          // safety clamp
    analogWrite(LED_PIN, brightness);

    // Print input and output side by side for the Serial Plotter
    Serial.print(potValue);
    Serial.print(" ");
    Serial.println(brightness);
  } else {
    // --- Stretch: light theremin (uses MEASURED range, not 0-1023) ---
    int light = analogRead(LIGHT_PIN);
    int pitch = map(light, LIGHT_MIN, LIGHT_MAX, 200, 2000);
    pitch = constrain(pitch, 200, 2000);
    tone(BUZZER_PIN, pitch);

    Serial.print(light);
    Serial.print(" ");
    Serial.println(pitch);
  }

  delay(50);
}
