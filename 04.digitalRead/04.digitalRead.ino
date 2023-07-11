/*
  Author: 
  Learning Intention: The students will learn how to wire a pull-up and pull-down switch and configure PINs for digital input and read binary data from those PINs.
  Success Criteria:
    1. I understand how to configure a PIN for input
    2. I can wire a switch for digital input in TINKERCAD
    3. I know how to read binary data from a specific PIN
    4. I understand that LOW = false = 0 = <1.5 volts (or Off) and that HIGH = true = 1 = >3 volts (or On)
    5. I know the difference between a switch and a momentary switch
    6. I can organise output data so it correctly plots on the serial monitor
    7. I can apply this knowledge to the Button and the Line Finder in the sensor kit

  Student Notes: 

  Documentation: 
    https://www.arduino.cc/reference/en/language/functions/digital-io/pinmode/
    https://www.arduino.cc/reference/en/language/functions/digital-io/digitalread/
    https://docs.arduino.cc/built-in-examples/digital/Debounce
  Schematic:
    https://www.tinkercad.com/things/kSX9CqedYeX?sharecode=eYYWDcM8F9OS2TUEujdDsoekSHmj3-VeZ9YSi0uWTYI
    https://github.com/TempeHS/TempeHS_Ardunio_Boilerplate/blob/main/Ardunio_Bootcamp/04.digitalRead/Bootcamp-digitalRead.png
*/

static int PullUpPIN = 3;
static int PullDownPIN = 10;
static int SetupPullDownPIN = 12;

void setup() {
  Serial.begin(9600);
  pinMode(PullUpPIN, INPUT);
  pinMode(PullDownPIN, INPUT);
  pinMode(SetupPullDownPIN, INPUT_PULLUP);
}

void loop() {
  Serial.print("PullUpPIN:");
  Serial.print(digitalRead(PullUpPIN));
  Serial.print(",");
  Serial.print("PullDownPIN:");
  Serial.print(digitalRead(PullDownPIN));
  Serial.print(",");
  Serial.print("SetupPullDownPIN:");
  Serial.println(digitalRead(SetupPullDownPIN));
}