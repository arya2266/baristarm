#include <Servo.h>;

//servo definitions
Servo base;
Servo shoulder;
Servo elbow;
Servo claw;
int baserest = 90;
int shoulderrest = 70;
int elbowrest = 100;
int clawrest = 90;

//controller definitions
float gain = 0.1;
int error;
int pos;
int count = 0;

//trig definitions
int armlength = 136.75;

//ultrason definitions
int ultraval;
int rotationcount = 0;
int angle1;
int angle2;
int midpoint;
int trigPin = 7;
int echoPin = 13;
long duration;
int distance;

void setup() {
  Serial.begin(9600);
  
  base.attach(6);
  shoulder.attach(9);
  elbow.attach(10);
  claw.attach(11);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  Serial.println("ready");

  base.write(baserest);
  shoulder.write(shoulderrest);
  elbow.write(elbowrest);
  claw.write(clawrest);
  delay(3000);
  

}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.0343 / 2;
  Serial.print(distance);
  
  //if button press
  int objangle = scan();
  base.write(objangle);
  //pickup(ultraval);
//  base.write(180);
  

}

int scan(){
  ultraval = distance;
  while (ultraval >=20){
    rotationcount += 1;
    base.write(rotationcount);
    delay(100);
    if (ultraval <= 20){
      angle1 = rotationcount;
      while (ultraval <= 20){
        rotationcount += 1;
        delay(100);
        base.write(rotationcount);
        if (ultraval >= 20) {
          angle2 = rotationcount;
          break;
      break;
  midpoint = (angle1 + angle2)/2;
  return midpoint;
        }
      }
    }
  }
}


//int pickup(ultraval){
  


//}

//int deposit(){
  


//}
