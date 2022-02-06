#include <Servo.h>;

//servo definitions
Servo base;
Servo shoulder;
Servo elbow;
Servo claw;
int baserest = 90;

//controller definitions
float gain = 0.1;
int error;
int pos;
int count = 0;
//int oldpos;
//int pstar;
//int servo;

//trig definitions
int armlength = 136.75;

void setup() {
Serial.begin(9600);

base.attach(6);
shoulder.attach(9);
elbow.attach(10);
claw.attach(11);



}

void loop() {
//if button press:
//  base.write();
}

void homepos(int oldpos, int pstar, int servo){
  
  error = pstar - oldpos;
  if (error != 0) {
    while (error != 0){
      if (error <= 1) {
      }
      else { 
        pos = oldpos + (gain * error);
        servo.write(pos);
        count += 1; 
        oldpos = pos;
        delay(65);
        if (count >= 50) {
          gain = 1;

        }
      }
    }
  }
}
