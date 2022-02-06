#include <Servo.h>

Servo base;
Servo shoulder;
Servo elbow;


void setup() {
base.attach(6);
shoulder.attach(9);
elbow.attach(10);
pinMode(13, OUTPUT);

}

void loop() {
 base.write(0);
 shoulder.write(130);
 elbow.write(0);
 digitalWrite(13, HIGH);
 delay(1000);
 digitalWrite(13, LOW);
 base.write(90);
 shoulder.write(150);
 elbow.write(70);
 digitalWrite(13, HIGH);
 delay(1000);
 digitalWrite(13, LOW);
 


  }
