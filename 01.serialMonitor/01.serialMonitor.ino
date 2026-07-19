/*
  Author: TEACHER SOLUTION

  Learning Intention:
  The students will understand the difference between the inbuilt setup and loop methods,
  and use the Serial Monitor as a debugging window into a running program.

  Success Criteria:
    1.  I understand the different behaviours of the setup and loop methods
    2.  I can print information to the serial monitor
    3.  I can print information to a new line of the serial monitor
    4.  I understand the impact of having more than one setup or loop method in my sketch
    5.  I understand single-line and multi-line comments
    6.  I can recognise a missing-semicolon compiler error

  Teacher notes:
    - Lesson experiments: duplicate loop() -> "redefinition of 'void loop()'";
      delete a semicolon -> "expected ';' before '}' token";
      Serial Monitor at 4800 baud -> garbage characters.
*/

void setup() {
  Serial.begin(115200);                 // Start talking to the computer at 115200 baud
  Serial.println("Arduino ready!");   // Prints ONCE per power-on or reset
  Serial.print("This runs ");
  Serial.println("in setup only.");
}

void loop() {
  Serial.println("Looping forever!"); // Prints every cycle, once per second
  delay(1000);                        // Wait 1 second each cycle
}
