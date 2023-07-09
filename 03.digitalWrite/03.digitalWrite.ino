/*
  Author: 
  Learning Intention: The students will learn about configuring PINs and how to write binary data to a specific PIN.
  Success Criteria:
    1. I understand how to configure a PIN for outputting data
    2. I know how to write binary data to a specific PIN
    3. I can change the value in the delay method to change time
    4. I understand that LOW = false = 0 = <1.5 volts (or Off) and that HIGH = true = 1 = >3 volts (or On)
    5. I can create and correctly wire a LED in tinkerCAD and prototype my code
    6. I understand that a resistor is needed to reduce the voltage for the LED
    7. I understand what 'static' means before the int declaration
    8. I can organise output data so it correctly plots on the serial monitor

  Student Notes: 

  Documentation: 
    https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/
    https://www.arduino.cc/reference/en/language/functions/digital-io/digitalwrite/
    https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-serial-plotter
  Schematic:
    https://www.tinkercad.com/things/fuycpi6sawp?sharecode=9PtRkJ5vqehLZ8sWbX51G2KhoWFTE6-bhSy6gL0A4oc
    https://github.com/TempeHS/TempeHS_Ardunio_Boilerplate/blob/main/Ardunio_Bootcamp/03.digitalWrite/LED_Schedmatic.png
*/

static int OnBoardLED = 13;
static int LEDonPin8 = 8;

void setup() {
  Serial.begin(9600);
  pinMode(OnBoardLED, OUTPUT);
  pinMode(LEDonPin8, OUTPUT);
}

void loop() {
  digitalWrite(OnBoardLED, HIGH);
  digitalWrite(LEDonPin8, LOW);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(OnBoardLED, LOW);
  digitalWrite(LEDonPin8, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
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