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

  Library setup (once, via the library manager):
    - "U8g2" by oliver          (drives the OLED, we use the U8x8 text mode)
    - "Grove Temperature And Humidity Sensor" by Seeed Studio (DHT lib), OR
      swap readSensor() in functions.ino for your chosen catalogue example.

  Teacher notes:
    - setup() runs the I2C scanner first: expect 0x3C (OLED) and 0x38 (T&H).
    - loop() is the dashboard challenge: live readings on the OLED with a
      threshold alert, structured with functions in functions.ino.
*/

#include <Wire.h>
#include <U8x8lib.h>
#include "DHT.h"

// 0.96 inch OLED in text mode (the sensor kit catalogue example uses this)
U8X8_SSD1306_128X64_NONAME_HW_I2C oled(U8X8_PIN_NONE);

// Grove Temperature & Humidity (DHT20 on the sensor kit) on I2C
DHT dht(DHT20);

const float ALERT_TEMPERATURE = 30.0;   // threshold for the dashboard alert

void setup() {
  Serial.begin(9600);
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
  oled.begin();
  oled.setFont(u8x8_font_chroma48medium8_r);
  oled.setCursor(0, 0);
  oled.print("TempeHS Bootcamp");   // adapted example: your own text

  dht.begin();
}

void loop() {
  // --- Dashboard challenge: read, display, alert ---
  float temperature, humidity;
  readSensor(&temperature, &humidity);
  updateDisplay(temperature, humidity);
  checkAlert(temperature);

  Serial.print(temperature);
  Serial.print(" ");
  Serial.println(humidity);

  delay(1000);
}
