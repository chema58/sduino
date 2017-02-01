/*
 Controlling a servo position using a potentiometer (variable resistor)
 by Michal Rinott <http://people.interaction-ivrea.it/m.rinott>

 modified on 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Knob
 modified to C syntax on 30 Jan 2017 for use with the sdunio environment
 by Michael Mayer
*/

#include <Arduino.h>
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup() {
  myservo = Servo_attach(9);  // attaches the servo on pin 9 to the servo object
}

#define myservo_write(V)	Servo_write(myservo,V)

void loop() {

  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
//  Servo_write(myservo,val);                  // sets the servo position according to the scaled value
  myservo_write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}