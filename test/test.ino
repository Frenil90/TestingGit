//
// test
//
// Description of the project
// Developed with [embedXcode](http://embedXcode.weebly.com)
//
// Author 		Fredrik Nilsson
// 				Fredrik Nilsson
//
// Date			2017-03-15 10:07
// Version		<#version#>
//
// Copyright	© Fredrik Nilsson, 2017
// Licence		<#licence#>
//
// See         ReadMe.txt for references
//


// Core library for code-sense - IDE-based
#if defined(ENERGIA) // LaunchPad specific
#include "Energia.h"
#elif defined(TEENSYDUINO) // Teensy specific
#include "Arduino.h"
#elif defined(ESP8266) // ESP8266 specific
#include "Arduino.h"
#elif defined(ARDUINO) // Arduino 1.8 specific
#include "Arduino.h"
#else // error
#error Platform not defined
#endif // end IDE

// Set parameters


// Include application, user and local libraries


// Define structures and classes


// Define variables and constants


// Prototypes


// Utilities


// Functions

#include "VarSpeedServo.h"


VarSpeedServo myservo;


const unsigned short DEFAULT_SERVO_PIN = 6; // the digital pin used for the servo
const int STRAIGHT_WHEELS = 90;             //start angle
const int MAX_RIGHT_DEGREES = 0;            //Absolute max angle to right
const int MAX_LEFT_DEGREES = 180;           //Absolute max angle to left

void Begin(){
    Serial.begin(9600);
    myservo.attach(DEFAULT_SERVO_PIN);      //attaches the servo on pin 9 to the servo object
    myservo.write(STRAIGHT_WHEELS,255,true); //starting angle at servo
}
int getAngle(){
    return myservo.read();
}

void setup() {
    Begin();
}

void loop() {
 
    if (Serial.available()) {          //if input from keyboard available then write to servo
        int input_angle = Serial.parseInt();   //Read input from serial
        Serial.print("Typed from keyboard: ");
        Serial.println(input_angle);
        
        if (input_angle > MAX_LEFT_DEGREES ) {
            input_angle = MAX_LEFT_DEGREES;
        }
        if (input_angle < MAX_RIGHT_DEGREES ) {
            input_angle = MAX_RIGHT_DEGREES;
        }
        myservo.write(input_angle,255,true);   //writing setpoint angle to servo
        Serial.print("Actual servo angle: ");
        Serial.println(getAngle());     //read actual value to servo
    }
   
}
