#include <SoftwareSerial.h>

/*
 * Kevin McAleer
 * 31 October 2021 - Happy Halloween 
 * 
 * Line Following Code
 * See Lesson 07 for the full tutorial
 * https://www.smarsfan.com/play/lessons/lesson_07_linefollow
 * Watch the livestream video:
 * https://youtu.be/u9VT32q7ero 
 * 
 *
 */

int lineSensorValue; // stores the line sensor value
int lineSensorPin = 5;

// set Motor A to Arduino Pins
int motor_A = 12; // official Arduino Motor Shield uses D12
int motor_B = 13; // official Arduino Motor Shield uses D13
//int buzzer = 4;

// set the Motor Speed using the Arduino Pins
int motor_A_speed = 3; // official Arduino Motor Shield uses D3, Fundumoto uses D10
int motor_B_speed = 11; // official Arduino Motor Shield uses D11, Fundumoto uses D11

// set the time between motor on and motor off
int wait_in_milliseconds = 10;

SoftwareSerial mySerial(2,3);

/////////////////////////////////////
/*
 * Movement block of code, from the movement lessons
 * https://www.smarsfan.com/play/lessons/lesson_01_movement
 * https://www.smarsfan.com/play/lessons/lesson_02_turning
 * 
 */

// move forward
void forward() {
  Serial.println("Forward");
  mySerial.print("Forward");
  // set the direction to forward
  digitalWrite(motor_A, LOW);  
  digitalWrite(motor_B, HIGH);

  // set to full speed
  analogWrite(motor_A_speed, 255);
  analogWrite(motor_B_speed, 255);

  // wait
  delay(wait_in_milliseconds);

  // stop
  analogWrite(motor_A_speed, 0);
  analogWrite(motor_B_speed, 0);
}

void backward(){
  Serial.println("Backward");
  mySerial.print("Backward");
  // set the direction to forward
  digitalWrite(motor_A, HIGH);  
  digitalWrite(motor_B, LOW);

  // set to full speed
  analogWrite(motor_A_speed, 255);
  analogWrite(motor_B_speed, 255);

  // wait
  delay(wait_in_milliseconds);

  // stop
  analogWrite(motor_A_speed, 0);
  analogWrite(motor_B_speed, 0);
}

void turnRight(){
  Serial.println("Turn Right");
  mySerial.print("turn right");
  // set the direction to forward
  digitalWrite(motor_A, HIGH);  
  digitalWrite(motor_B, HIGH);

  // set to full speed
  analogWrite(motor_A_speed, 255);
  analogWrite(motor_B_speed, 255);

  // wait
  delay(wait_in_milliseconds);

  // stop
  analogWrite(motor_A_speed, 0);
  analogWrite(motor_B_speed, 0);
}

void turnLeft(){
  Serial.println("Turn Left");
  mySerial.print("turn left");
  // set the direction to forward
  digitalWrite(motor_A, LOW);  
  digitalWrite(motor_B, LOW);

  // set to full speed
  analogWrite(motor_A_speed, 255);
  analogWrite(motor_B_speed, 255);

  // wait
  delay(wait_in_milliseconds);

  // stop
  analogWrite(motor_A_speed, 0);
  analogWrite(motor_B_speed, 0);
}

/////////////////////////////////////

int readLineSensor() {
  return digitalRead(lineSensorPin);
}

void setup() {
  // set the Serial to 9600 baud and open it for comms
  Serial.begin(9600);
  mySerial.begin(9600);
  mySerial.println("Online");

  // set the Arduino pin to OUTPUT mode
  pinMode(motor_A, OUTPUT);
  pinMode(motor_B, OUTPUT);
  pinMode(lineSensorPin, INPUT);
}

void loop() {
  // Read the value from the line sensor (connected to the line sensor pin)
  lineSensorValue = readLineSensor();

  // move forward while the line sensor is white

  if (lineSensorValue == 1)
  {
    // move forward
    forward();
//     Serial.println(lineSensorValue); 
  }
  else{
    turnRight(); 
  } 
  lineSensorValue = readLineSensor();
  Serial.println(lineSensorValue); 
  mySerial.println(lineSensorValue);
}
