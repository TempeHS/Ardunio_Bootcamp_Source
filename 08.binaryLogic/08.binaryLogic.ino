/*
  Author: 
   Learning Intention: The students understand how time is used in microcontrollers and best practices
    1. I understand Binary Logic is asking questions that only have a true and false outcome
    2. I can apply different comparison operators to get a desired outcome in a basic if else control structure 
    3. I understand 'if', 'if else', and 'if else if else'
    4. I understand the differenvce between a 'nested if', and using boolean operators
    5. I know how to find out more about advanced control structures like 'for', 'do while', 'while', and 'switch case'

  Student Notes: 
  Comparison Operators
    - != (not equal to)
    - < (less than)
    - <= (less than or equal to)
    - == (equal to)
    - > (greater than)
    - >= (greater than or equal to)

    Boolean Operators
    - ! (logical not)
    - && (logical and)
    - || (logical or)


  Documentation: 
    https://www.arduino.cc/reference/en/#structure
  Schematic: 
    
*/

bool myBoolean = true;
static unsigned int myInt1 = 3;
static unsigned int myInt2 = 7; 

void setup() {
  Serial.begin(9600);
  Serial.println("--TRUE or FALSE?--");
  Serial.println("-------------------------------------");
  if (myBoolean) {
    Serial.println("** It is TRUE! **");
  } else {
    Serial.println("** It is FALSE! **");
  }
  Serial.println("=====================================");
}

// The loop function runs over and over again forever
void loop() {
      
}

