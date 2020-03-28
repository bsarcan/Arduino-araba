#include<AFMotor.h>  // Motor sürücümüzün kütüphanesi

AF_DCMotor motorA(1);  //Motorları tanımlıyoruz. 
AF_DCMotor motorB(2);  //Parantez içindeki numara çıkış pinini gösterir.
AF_DCMotor motorC(3);
AF_DCMotor motorD(4);


int state; //Bluetooth sinyalleri için değişken.

void setup() {

  Serial.begin(9600);  //Port açmak için bu kod kullanıldı.
  
}

void loop() {

  if (Serial.available() > 0){       //Bluetoothdan gelen veriler.
    state = Serial.read();
  }

  //Burda 0-4 arası bir değer girerek motorların hızını belirliyoruz.
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
 
//Gelen komutlara göre hareket sağlanayor.
  //'F' komutu aracın ileri gitmesi için.
  if (state == 'F'){
    motorA.run(FORWARD);
    motorB.run(FORWARD);
    motorC.run(FORWARD);
    motorD.run(FORWARD);
  }
  //'B' komutu aracın geri gitmesi için.
  else if (state == 'B'){
    motorA.run(BACKWARD);
    motorB.run(BACKWARD);
    motorC.run(BACKWARD);
    motorD.run(BACKWARD);
  }
  //'L' komutu aracın sola dönmesi için.
  //Sola dönüş için soldaki motorlar geri gider.
  else if (state == 'L'){
    motorA.run(FORWARD);
    motorB.run(BACKWARD);
    motorC.run(BACKWARD);
    motorD.run(FORWARD);
  }
  //'R' komutu aracın sağa dönmesi için.
  //Sağa dönüş için sağdaki motorlar geri gider.
  else if (state == 'R'){
    motorA.run(BACKWARD);
    motorB.run(FORWARD);
    motorC.run(FORWARD); 
    motorD.run(BACKWARD);
  }
  //'S' komutu aracın durması için.
  else if (state == 'S'){
    motorA.run(RELEASE);
    motorB.run(RELEASE);
    motorC.run(RELEASE);
    motorD.run(RELEASE);
  }
}
