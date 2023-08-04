/*
  Author: 

  Learning Intention:
  The students will learn basic math and arithmetic operations in C++

  Success Criteria:
    1.  I know the arithmetic operation symbols %, *, +, -, / & =
    2.  I can perform arithmetic calculations
    3.  I know how to access more information in the documentation about math and arithmetic
    4.  I can access the order of operations documentation and use parenthesis to control
        the order of operations
    5.  I understand short-hand incrementation and decrementation 
    6.  I can seed and generate a random number
    7.  I can map an analogue value on a range of 0-1023 to a PWM value on a range of 0-255

  Student Notes:
    % (remainder)
    * (multiplication)
    + (addition)
    - (subtraction)
    / (division)
    = (assignment operator)

  Documentation: 
    https://www.arduino.cc/reference/en/#structure
    https://en.cppreference.com/w/cpp/language/operator_precedence
    https://www.arduino.cc/reference/en/language/functions/random-numbers/random/
    https://www.arduino.cc/reference/en/language/functions/math/map/
  Schematic:
      https://www.tinkercad.com/things/ihcHlUXS9Y7?sharecode=bOdn0Sm9OuCJ6qI9GAwdyLsZDEUcecsmUharAUXXRIQ
      https://github.com/TempeHS/TempeHS_Ardunio_Boilerplate/blob/main/Ardunio_Bootcamp/08.mathComputation/Bootcamp-MAP-PotLED.png
*/

int myNumber1 = 3;
int myNumber2 = 5;
float myResult = 0;

// The setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  Serial.println("Serial monitor is configured to 9600 baud rate");
  Serial.println("-------------------------------------");
  
  myResult = myNumber1 / myNumber2;   // Arithmatic with one datatype will force all to that data type

  // Print out the result
  Serial.print("My Calculation: ");
  Serial.println(String(myResult, 3));
}

// The loop function runs over and over again forever
void loop() {
// myResult = myResult + 1;
// myResult += 1;
// myResult ++;
// Serial.println(String(myResult));
}

/*
long randNumber;

void setup() {
  randomSeed(analogRead(0));
}

void loop() {
  // print a random number from 0 to 100
  randNumber = random(0, 100);
  Serial.println(randNumber);
  delay(50);
}
*/

/*
static int myVariableResistor = A0;
int resistorValue;
static int myLEDPIN = 3;
int LEDStrength;

void setup() {
  pinMode(myLEDPIN, OUTPUT);
}

void loop() {
  resistorValue = analogRead(myVariableResistor);
  LEDStrength = map(resistorValue, 0, 1024, 0, 255);
  analogWrite(myLEDPIN, LEDStrength);
}
*/







