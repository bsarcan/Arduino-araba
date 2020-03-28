#include<AFMotor.h>

AF_DCMotor motorA(1);
AF_DCMotor motorB(2);
AF_DCMotor motorC(3);
AF_DCMotor motorD(4);


int state;

void setup() {

  //motoryon.setSpeed(255);
  //motoryon.run(RELEASE);
  Serial.begin(9600);
  
}

void loop() {

  if (Serial.available() > 0){
    state = Serial.read();
  }

  if (state == '0'){
    motorA.setSpeed(0);
    motorB.setSpeed(0);
    motorC.setSpeed(0);
    motorD.setSpeed(0);
  }
  else if (state == '1'){
    motorA.setSpeed(100);
    motorB.setSpeed(100);
    motorC.setSpeed(100);
    motorD.setSpeed(100);
  }
  else if (state == '2'){
    motorA.setSpeed(180);
    motorB.setSpeed(180);
    motorC.setSpeed(180);
    motorD.setSpeed(180);
  }
  else if (state == '3'){
    motorA.setSpeed(200);
    motorB.setSpeed(200);
    motorC.setSpeed(200);
    motorD.setSpeed(200);
  }
  else if (state == '4'){
    motorA.setSpeed(255);
    motorB.setSpeed(255);
    motorC.setSpeed(255);
    motorD.setSpeed(255);
  }
 

  if (state == 'F'){
    motorA.run(FORWARD);
    motorB.run(FORWARD);
    motorC.run(FORWARD);
    motorD.run(FORWARD);
  }
  else if (state == 'B'){
    motorA.run(BACKWARD);
    motorB.run(BACKWARD);
    motorC.run(BACKWARD);
    motorD.run(BACKWARD);
  }
  else if (state == 'L'){
    motorA.run(FORWARD);
    motorB.run(BACKWARD);
    motorC.run(BACKWARD);
    motorD.run(FORWARD);
  }
  else if (state == 'R'){
    motorA.run(BACKWARD);
    motorB.run(FORWARD);
    motorC.run(FORWARD); 
    motorD.run(BACKWARD);
  }
  else if (state == 'S'){
    motorA.run(RELEASE);
    motorB.run(RELEASE);
    motorC.run(RELEASE);
    motorD.run(RELEASE);
  }
}
