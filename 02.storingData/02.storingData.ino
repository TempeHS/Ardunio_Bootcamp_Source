/*
  Author: TEACHER SOLUTION

  Learning Intention:
  The students will learn the different data types used in the C++ language,
  watch an integer overflow live, and understand variable scope.

  Success Criteria:
    1.  I understand and can store variables in the datatypes String, int, float, long and bool
    2.  I know how to access more information about the different datatypes in the documentation
    3.  I understand how (1, HIGH and true) and (0, LOW and false) all represent the same concept
    4.  I can convert an int, float and bool to a String and print it to the serial monitor
    5.  I understand the difference between an int and an unsigned int, and a long and an unsigned long
    6.  I understand the difference between a global variable and a function (local) variable

  Teacher notes:
    - Overflow demo: the int counter climbs past 32,767 then wraps to -32,768.
      Change `int counter` to `long counter` and it keeps climbing.
    - Scope demo: move `int counter = 30000;` inside setup() and the sketch fails
      to compile with "'counter' was not declared in this scope" at loop().
*/

// GLOBAL variables: declared outside all functions, visible everywhere
int    count       = 42;           // whole numbers
float  temperature = 23.5;         // decimal numbers
long   bigNumber   = 100000;       // large whole numbers
bool   isOn        = true;         // true or false
String deviceName  = "My Arduino"; // text

int counter = 30000;               // used by the overflow demo in loop()

void setup() {
  Serial.begin(9600);

  // Converting every type to String for printing (criterion 4)
  Serial.println("Name: " + deviceName);
  Serial.println("Count: " + String(count));
  Serial.println("Temperature: " + String(temperature));
  Serial.println("Big number: " + String(bigNumber));
  Serial.println("Switched on: " + String(isOn));  // prints 1: true IS 1

  // (1, HIGH, true) are interchangeable (criterion 3)
  bool a = true;
  bool b = HIGH;
  bool c = 1;
  Serial.println("true/HIGH/1 all print as: " + String(a) + String(b) + String(c));

  // Signed vs unsigned (criterion 5): same 2 bytes, different ranges
  int          signedMax   = 32767;   // int:          -32,768 to 32,767
  unsigned int unsignedMax = 65535;   // unsigned int:       0 to 65,535
  Serial.println("int max: " + String(signedMax));
  Serial.println("unsigned int max: " + String(unsignedMax));

  // LOCAL variable: only exists inside setup()
  int localDemo = 5;
  Serial.println("Local variable: " + String(localDemo));
}

void loop() {
  // Overflow demo: watch the wrap at 32,767
  counter = counter + 1000;
  Serial.println(counter);
  delay(300);
}
