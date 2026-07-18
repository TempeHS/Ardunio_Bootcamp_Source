// TEACHER SOLUTION: dashboard helper functions.
// Joined automatically with 09.I2C.ino by the Arduino build system.

// Reads temperature (C) and humidity (%) from the Grove T&H sensor.
// Values are returned through pointer parameters.
void readSensor(float *temperature, float *humidity) {
  float readings[2] = {0};
  if (dht.readTempAndHumidity(readings) == 0) {
    *humidity = readings[0];
    *temperature = readings[1];
  }
}

// Shows labelled live values on the OLED.
void updateDisplay(float temperature, float humidity) {
  oled.setCursor(0, 2);
  oled.print("Temp: ");
  oled.print(temperature, 1);
  oled.print(" C  ");

  oled.setCursor(0, 4);
  oled.print("Hum:  ");
  oled.print(humidity, 1);
  oled.print(" %  ");
}

// Threshold alert on the bottom line of the display.
void checkAlert(float temperature) {
  oled.setCursor(0, 6);
  if (temperature > ALERT_TEMPERATURE) {
    oled.print("!! TOO HOT !!  ");
  } else {
    oled.print("conditions OK  ");
  }
}
