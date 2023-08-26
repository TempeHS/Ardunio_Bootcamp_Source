/*
  Author: 

  Learning Intention:
  The students will learn what 'pulse width modulation' is and how to use it to write
  analogue data on a digital PIN.
  
  Success Criteria:
    1.  I understand what pulse width modulation is
    2.  I can identify the PWM PINS on the Arduino Uno
    3.  I can wire an RGB LED for PWM control in TINKERCAD
    5.  I can write PWM data to multiple pins and manually change the colour of the LED

  Student Notes: 

  Documentation: 
    https://www.w3schools.com/colors/colors_rgb.aspt
    https://github.com/TempeHS/TempeHS_Ardunio_Bootcamp/blob/main/07.pulseWidthModulation/Pulse-Width-Modulation.jpg
  Schematic:
    https://www.tinkercad.com/things/drNDsMxGMIY?sharecode=D6x4_xTTRl_zGs7B-XGqfbQhG_xgjj3TVS_c-GNTK-c
    https://github.com/TempeHS/TempeHS_Ardunio_Bootcamp/blob/main/07.pulseWidthModulation/Bootcamp-PWMOutput.png
*/

static unsigned int redPIN = 3;
static unsigned int greenPIN = 5;
static unsigned int bluenPIN = 6;
static unsigned int myLED = 13;

void setup() {
  Serial.begin(9600);
  pinMode(greenPIN, OUTPUT);
  pinMode(redPIN, OUTPUT);
  pinMode(bluenPIN, OUTPUT);
}

void loop() {
  analogWrite(redPIN, 255)
  analogWrite(greenPINn, 0)
  analogWrite(bluePIN, 0)

 for (i=0; i <=255; i++) {
    analogWrite(myLED, i);
    delay(15);
 }

}