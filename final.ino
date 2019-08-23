#include <Servo.h>

const int trigPin = 2;
const int echoPin = 3;

long duration;
int distance;

int motorLpin1=4;
int motorLpin2=5;
int motorRpin1=6;
int motorRpin2=7;
int motorLpwm=10;
int motorRpwm=9;

Servo servo01;
Servo servo02;
Servo servo03;

int servo1Pos, servo2Pos, servo3Pos; // current position
int servo1PPos, servo2PPos, servo3PPos; // previous position
int speedDelay = 20;
int index = 0;

int motorSpeed=255;
String input;


void setup() {
  Serial.begin(9600);
  Serial.flush();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  servo01.attach(12);
  servo02.attach(13);
  servo03.attach(11);

  servo1PPos = 0;
  servo01.write(servo1PPos);
  servo2PPos = 0;
  servo02.write(servo2PPos);
  servo3PPos = 90;
  servo03.write(servo3PPos);
  
  pinMode(motorLpin1,OUTPUT);
  pinMode(motorLpin2,OUTPUT);
  pinMode(motorRpin1,OUTPUT);
  pinMode(motorRpin2,OUTPUT);
  pinMode(motorLpwm,OUTPUT);
  pinMode(motorRpwm,OUTPUT);
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
  distance= duration*0.034/2;

  Serial.print("Distance: ");
  Serial.println(distance);
  //delay(1000);




  
  input="";

  while(Serial.available()){
    input+=(char)Serial.read();
    delay(5);
  }
  if(input=="B"){
  Serial.println(input);

  analogWrite(motorLpwm,motorSpeed);
  analogWrite(motorRpwm,motorSpeed);
  digitalWrite(motorLpin1,0);
  digitalWrite(motorLpin2,1);
  digitalWrite(motorRpin1,0);
  digitalWrite(motorRpin2,1);
  }

  if(input=="F"){
  Serial.println(input);

  analogWrite(motorLpwm,motorSpeed);
  analogWrite(motorRpwm,motorSpeed);
  digitalWrite(motorLpin1,1);
  digitalWrite(motorLpin2,0);
  digitalWrite(motorRpin1,1);
  digitalWrite(motorRpin2,0);
  }
  
    if(input=="L"){
  Serial.println(input);

  analogWrite(motorLpwm,motorSpeed);
  analogWrite(motorRpwm,motorSpeed);
  digitalWrite(motorLpin1,0);
  digitalWrite(motorLpin2,1);
  digitalWrite(motorRpin1,1);
  digitalWrite(motorRpin2,0);
  }
  if(input=="R"){
  Serial.println(input);

  analogWrite(motorLpwm,motorSpeed);
  analogWrite(motorRpwm,motorSpeed);
  digitalWrite(motorLpin1,1);
  digitalWrite(motorLpin2,0);
  digitalWrite(motorRpin1,0);
  digitalWrite(motorRpin2,1);
  }
  if(input=="S" || (distance>1 && distance<6)){
  Serial.println(input);

  analogWrite(motorLpwm,0);
  analogWrite(motorRpwm,0);
  digitalWrite(motorLpin1,1);
  digitalWrite(motorLpin2,1);
  digitalWrite(motorRpin1,1);
  digitalWrite(motorRpin2,1);
  }

  if (input.startsWith("G")) {
    Serial.println(input);
      String dataInS = input.substring(1, input.length());
      servo1Pos = dataInS.toInt();
      Serial.println(servo1Pos);

      if (servo1PPos > servo1Pos) {
        for ( int j = servo1PPos; j >= servo1Pos; j--) {
          servo01.write(j);
          delay(20);
        }
      }

      if (servo1PPos < servo1Pos) {
        for ( int j = servo1PPos; j <= servo1Pos; j++) {
          servo01.write(j);
          delay(20);
        }
      }
      servo1PPos = servo1Pos;
    }
      if (input.startsWith("E")) {
    Serial.println(input);
      String dataInS = input.substring(1, input.length());
      servo2Pos = dataInS.toInt();
      Serial.println(servo2Pos);

      if (servo2PPos > servo2Pos) {
        for ( int j = servo2PPos; j >= servo2Pos; j--) {
          servo02.write(j);
          delay(20);
        }
      }

      if (servo2PPos < servo2Pos) {
        for ( int j = servo2PPos; j <= servo2Pos; j++) {
          servo02.write(j);
          delay(20);
        }
      }
      servo2PPos = servo2Pos;
    }
          if (input.startsWith("W")) {
    Serial.println(input);
      String dataInS = input.substring(1, input.length());
      servo3Pos = dataInS.toInt();
      Serial.println(servo3Pos);

      if (servo3PPos > servo3Pos) {
        for ( int j = servo3PPos; j >= servo3Pos; j--) {
          servo03.write(j);
          delay(20);
        }
      }

      if (servo3PPos < servo3Pos) {
        for ( int j = servo3PPos; j <= servo3Pos; j++) {
          servo03.write(j);
          delay(20);
        }
      }
      servo3PPos = servo3Pos;
    }
}
