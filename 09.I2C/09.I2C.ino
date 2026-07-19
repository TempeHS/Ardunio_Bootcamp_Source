/*
  Author: TEACHER SOLUTION

  Learning Intention:
  The students will use the I2C communication protocol to send data to the OLED
  display and receive data from the kit's I2C sensors.

  Hardware (Grove cables to the base shield I2C ports):
    OLED display 0.96 inch (0x3C)
    Temperature & Humidity sensor (0x38)
    All I2C devices share the Uno's dedicated SDA and SCL pins. (On an Uno these
    share circuitry with A4 and A5, so leave those analogue ports unused while
    I2C devices are connected.)

  Library setup (once):
    Open the bridge web interface, go to the Libraries tab, search for
    "Arduino_SensorKit" and install it. It bundles the drivers for every kit
    I2C module (OLED via U8g2, Temperature & Humidity, Air Pressure,
    Accelerometer) behind one include.

  Teacher notes:
    - setup() runs the I2C scanner first: expect 0x3C (OLED) and 0x38 (T&H).
    - loop() is the dashboard challenge: live readings on the OLED with a
      threshold alert, structured with functions in functions.ino.
    - Oled and Environment objects come from Arduino_SensorKit.h.
*/

#include <Wire.h>
#include "Arduino_SensorKit.h"

// The kit's Temperature & Humidity sensor is the DHT20 (black, I2C, 0x38).
// This define points the library's Environment object at the I2C driver.
// Requires Arduino_SensorKit v1.0.10 or newer.
#define Environment Environment_I2C

const float ALERT_TEMPERATURE = 30.0;   // threshold for the dashboard alert

void setup() {
  Serial.begin(115200);
  Wire.begin();

  // --- Experiment 1: scan the bus ---
  Serial.println("Scanning the I2C bus...");
  for (byte address = 1; address < 127; address++) {
    Wire.beginTransmission(address);
    if (Wire.endTransmission() == 0) {
      Serial.print("Device found at address 0x");
      Serial.println(address, HEX);
    }
  }
  Serial.println("Scan complete.");

  // --- Experiment 2: drive the OLED ---
  Oled.begin();
  Oled.setFlipMode(true);                       // rotate to suit the mounting
  Oled.setFont(u8x8_font_chroma48medium8_r);    // readable 8x8 text font
  Oled.setCursor(0, 0);
  Oled.print("TempeHS Bootcamp");               // adapted example: your own text
  Oled.refreshDisplay();

  Environment.begin();                          // Temperature & Humidity sensor
}

void loop() {
  // --- Dashboard challenge: read, display, alert ---
  float temperature, humidity;
  readSensor(&temperature, &humidity);
  updateDisplay(temperature, humidity);
  checkAlert(temperature);
  Oled.refreshDisplay();                        // push the finished frame

  Serial.print(temperature);
  Serial.print(" ");
  Serial.println(humidity);

  delay(1000);
}
