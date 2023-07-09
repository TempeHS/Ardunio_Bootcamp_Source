/*
  Author: 
  Learning Intention: The students will learn how to connect and control a continuous 360-degree servo.
  Success Criteria:
    1. I understand how to power the Servo externally from the Arduino
    2. I understand the benefits of powering a motor externally
    2. I can manually write different directions and speeds to two servos
    3. I understand the advantages and disadvantages of a continuous servo over a motor and H bridge

  Student Notes: 

  Documentation: 
    https://github.com/arduino-libraries/Servo <-- We are still using this library

  Schematic:
    https://www.tinkercad.com/things/hTsjepywCmg?sharecode=X7VwGCzTAYM39hS_s1bzLKdL9PZwyLUDhjnhJQOaCIk
    https://github.com/TempeHS/TempeHS_Ardunio_Boilerplate/blob/main/Ardunio_Bootcamp/12.motorFundamentals/12.mF.continuousServoMotor/Bootcamp-continuousServoMotor.png
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = A0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}