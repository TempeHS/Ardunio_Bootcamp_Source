/*
  Author: TEACHER SOLUTION

  Learning Intention:
  The students will learn about the Object Oriented Paradigm and build their own
  classes and objects to manage hardware components.

  Hardware (Grove cables to the base shield):
    LED module -> D6, plus the built-in LED on pin 13 as the second instance.
    Button module -> D4 (for the student-written Button class).

  Teacher notes:
    - Break-it demo: add `moduleLed.pin = 2;` in setup() and the compiler
      reports "'int Led::pin' is private within this context".
    - The Button class is the Option A challenge solution: the alternating
      blink only runs while the button object reports pressed.
*/

// ---------- The Led class: blueprint for every LED we own ----------
class Led {
  private:
    int pin;           // properties: data each Led remembers
    bool isOn;

  public:
    Led(int ledPin) {  // constructor: runs when an object is created
      pin = ledPin;
      isOn = false;
    }

    void begin() {
      pinMode(pin, OUTPUT);
      digitalWrite(pin, LOW);
    }

    void turnOn() {
      digitalWrite(pin, HIGH);
      isOn = true;
    }

    void turnOff() {
      digitalWrite(pin, LOW);
      isOn = false;
    }

    void toggle() {
      if (isOn) {
        turnOff();
      } else {
        turnOn();
      }
    }
};

// ---------- Challenge Option A: a Button class ----------
class Button {
  private:
    int pin;

  public:
    Button(int buttonPin) {
      pin = buttonPin;
    }

    void begin() {
      pinMode(pin, INPUT);
    }

    bool isPressed() {
      return digitalRead(pin) == HIGH;   // Grove button reads HIGH pressed
    }
};

// Two Led objects from one blueprint, plus a Button object
Led moduleLed(6);     // the Grove LED module on D6
Led builtinLed(13);   // the LED soldered onto the Uno
Button goButton(4);   // the Grove Button on D4

void setup() {
  moduleLed.begin();
  builtinLed.begin();
  goButton.begin();
  builtinLed.turnOn();   // start opposite to the module LED
}

void loop() {
  // Railway-crossing alternating blink, but only while the button is held:
  // proves the objects work together and each keeps its own state.
  if (goButton.isPressed()) {
    moduleLed.toggle();
    builtinLed.toggle();
    delay(500);
  }
}
