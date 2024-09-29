/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 https://www.arduino.cc/en/Tutorial/LibraryExamples/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
Servo myservo2;

int pos = 0;    // variable to store the servo position

void setup() {
  Serial.begin(9600);
  myservo.attach(9,1000,2000);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(10,1000,2000);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.print("Servo 1: ");
    Serial.print(myservo.read());
    myservo2.write(180-pos);  
    Serial.print(", Servo 2: ");
    Serial.println(myservo2.read());
    delay(5);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.print("Servo 1: ");
    Serial.print(myservo.read());
    myservo2.write(180-pos);
    Serial.print(", Servo 2: ");
    Serial.println(myservo2.read());
    delay(5);                       // waits 15 ms for the servo to reach the position
  }
}
