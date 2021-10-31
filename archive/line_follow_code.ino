#include <Adafruit_MotorShield.h>
//#include <Adafruit_MotorShield 2.h>

//#include <AFMotor.h>

//SMARS Demo 2 with Line sensor
//This sketch makes the robot follow a line (you can make it with insulating tape).
//There is a small bug, find it and fix it!
//you'll need an Adafruit Motor shield V1 https://goo.gl/7MvZeo and a IR sensor https://goo.gl/vPWfzx

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *R_motor = AFMS.getMotor(2);
Adafruit_DCMotor *L_motor = AFMS.getMotor(1);

//Adafruit_DCMotor R_motor(2); // defines Right motor pin
//Adafruit_DCMotor L_motor(1); // defines Left motor pin

// declare variables
int lineNumber; //defines the variable where it will store the line sensor value

void setup() {
  Serial.begin(9600); // sets up Serial library at 9600 bps
  //changes the following values to make the robot drive as straight as possible
  L_motor->setSpeed(200); // sets L motor speed
  R_motor->setSpeed(140); // sets R motor speed
  R_motor->run(RELEASE); //turns L motor on
  L_motor->run(RELEASE); //turns R motor on
}

void loop() {
  lineNumber = analogRead(A4); //reads the sensor value from pin A4 and stores it in the variable lineNumber
  
  while(lineNumber>800) // repeats the following part of code until the light sensor will find a darker zone
  {
    L_motor->run(FORWARD); //moves motor L Forward
    R_motor->run(FORWARD); //moves motor L Forward
    lineNumber= analogRead(A4); //reads the sensor value from pin A4 and stores it in the variable lineNumber
  };
  
  if(lineNumber<800) // repeats the following part of code until the light sensor will find a darker zone
  {
    L_motor->run(FORWARD); //moves motor L Forward
    R_motor->run(BACKWARD); //moves motor L Forward
    //reads the sensor value from pin A4 and stores it in the variable lineNumber
  }
  
  // the following operations will make the robot goes backward for 2 seconds and turns left for 1.5 seconds
  else {
    L_motor->run(BACKWARD); //moves motor L Backward
    R_motor->run(FORWARD); //moves motor L Forward
  };
  
  Serial.println(lineNumber); //send the value to the serial monitor
}
