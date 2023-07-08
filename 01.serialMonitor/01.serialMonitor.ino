/*
  Author: 
  Learning Intention: The students will understand the difference between the inbuilt setup and loop methods, and understand the basics of the serial monitor'.
  Success Criteria:
    1. I understand the different behaviours of the setup and loop methods
    2. I can print information to the serial monitor
    3. I can print information to a new line of the serial monitor
    4. I can access the serial plotter to see data output over time
    5. I understand the impact of having more than one setup or loop methods in my sketch
  
  Student Notes: 

  Documentation: 
    https://www.arduino.cc/reference/en/language/functions/communication/serial/
    https://docs.arduino.cc/software/ide-v2/tutorials/ide-v2-serial-plotter
*/

// The setup function runs once when you press reset or power the board
void setup() {
  // Setup a serial conection and configure the communication speed
  Serial.begin(9600);
  // Debug serial connection by printing a confirmation to the serial monitor
  Serial.print("Serial monitor is configured to 9600 baud rate");
}

// The loop function runs over and over again forever
void loop() {
  while(!Serial.available());
  String myString = Serial.readString();
  Serial.println(myString);
}

  /*
  Serial.println("Hello Computer");
  Serial.println(analogRead(0));
  
  while(!Serial.available());
  String myString = Serial.readString();
  Serial.println(myString);
  */

