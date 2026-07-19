// TEACHER SOLUTION: dashboard helper functions.
// Joined automatically with 09.I2C.ino by the Arduino build system.
// Oled and Environment objects come from Arduino_SensorKit.h.

// Reads temperature (C) and humidity (%) from the kit's T&H sensor.
// Values are returned through pointer parameters.
void readSensor(float *temperature, float *humidity) {
  *temperature = Environment.readTemperature();
  *humidity = Environment.readHumidity();
}

// Shows labelled live values on the OLED.
void updateDisplay(float temperature, float humidity) {
  Oled.setCursor(0, 2);
  Oled.print("Temp: ");
  Oled.print(temperature, 1);
  Oled.print(" C  ");

  Oled.setCursor(0, 4);
  Oled.print("Hum:  ");
  Oled.print(humidity, 1);
  Oled.print(" %  ");
}

// Threshold alert on the bottom line of the display.
void checkAlert(float temperature) {
  Oled.setCursor(0, 6);
  if (temperature > ALERT_TEMPERATURE) {
    Oled.print("!! TOO HOT !!  ");
  } else {
    Oled.print("conditions OK  ");
  }
}
