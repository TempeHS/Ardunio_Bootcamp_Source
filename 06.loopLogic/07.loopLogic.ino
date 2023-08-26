/*
  Author: 

  Learning Intention:
  The students understand binary logic and apply it to a range of control structures.
  
  Success Criteria:
    1.  I understand Binary Logic is asking questions that only have a true and false outcome
    2.  I can apply different comparison operators to get a desired outcome in a basic if else
        control structure 
    3.  I understand 'if', 'if else', and 'if else if else'
    4.  I understand the difference between a 'nested if', and using boolean operators
    5.  I can read a simple logic flowchart
    6.  I know how to find the documentation for advanced control structures like 'for',
        'do while', 'while', and 'switch case'

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
    https://github.com/TempeHS/TempeHS_Ardunio_Boilerplate/blob/main/Ardunio_Bootcamp/06.binaryLogic/Readme.md
    
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

