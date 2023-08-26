/*  Author: 

  Learning Intention:
  The students understand binary selection logic and apply it to a simple control structures.
  
  Success Criteria:
    1.  I understand binary selection is asking questions that only have a true and false outcome
    2.  I can apply different comparison operators to get a desired outcome in a basic if else
        control structure 
    3.  I understand 'if', 'if else', and 'if else if else'
    4.  I understand the difference between a 'nested if', and using boolean operators
    5.  I can read a simple logic flowchart

  Student Notes: 
  Comparison Operators
    - != (not equal to)
    - < (less than)
    - <= (less than or equal to)
    - == (equal to)
    - > (greater than)
    - >= (greater than or equal to)

    Boolean Operators
    - ! (logical not)
    - && (logical and)
    - || (logical or)


  Documentation: 
    https://www.arduino.cc/reference/en/#structure
    https://github.com/TempeHS/TempeHS_Ardunio_Bootcamp/blob/main/03.binarySelection/Readme.md

*/

static int OnBoardLED = 13;
static int LEDonPin8 = 8;

void setup() {
  Serial.begin(9600);
  pinMode(OnBoardLED, OUTPUT);
  pinMode(LEDonPin8, OUTPUT);
}

void loop() {
  Serial.begin(9600);
  Serial.println("--TRUE or FALSE?--");
  Serial.println("-------------------------------------");
  if (myBoolean) {
    Serial.println("** It is TRUE! **");
  } else {
    Serial.println("** It is FALSE! **");
  }
  Serial.println("=====================================");
}

/*
  int OnBoardLEDValue = 1;
  int LEDonPin8Value = 0;

  OnBoardLEDValue = !OnBoardLEDValue;
  LEDonPin8Value = !LEDonPin8Value;
  Serial.print("OnBoardLED:");
  Serial.print(OnBoardLEDValue);
  Serial.print(",");
  Serial.print("LEDonPIN8:");
  Serial.println(LEDonPin8Value);
  digitalWrite(OnBoardLED, OnBoardLEDValue);
  digitalWrite(LEDonPin8, LEDonPin8Value);
  delay(1000); // Wait for 1000 millisecond(s)
*/