#include <legangle.h>
#include <SoftwareSerial.h>
void setup() {
  // put your setup code here, to run once:
  setservos();
  leg1(0, 0);
  leg2(0, 0);
  leg3(0, 0);
  leg4(0, 0);
  leg5(0, 0);
  leg6(0, 0);
  delay(2000);
  Serial1.begin(9600);
  Serial.begin(9600);
}

void loop() {
  while (Serial1.available()) { //Serial 통신으로 값이 들어 왔을 때 참(TRUE) --> Bluetooth stack 방지
    
    char num = Serial1.read();
    Serial.println(num);

    switch(num){
      
      case '1': //명령 대기 상태
        unwalk();
        num = '1';
        delay(00);
        break;

      case '2': //앞으로 이동 
        walk();
        num = '1';
        delay(00);
        break;

      case '3': //회전
        turn();
        num = '1';
        delay(00);
        break;   
      
      case '4':
        turnl();
        num = '1';
        delay(00);
        break;   
    }

  }
}

void stand(){
  leg1(0, 0);
  leg2(0, 0);
  leg3(0, 0);
  leg4(0, 0);
  leg5(0, 0);
  leg6(0, 0);
}

void unwalk(){
  leg1(-10, 0);
  leg3(-10, 30);
  leg5(-10, 17);
  leg2(-10, -15);
  leg4(-10, -2);
  leg6(-10, -32);
  delay(200);

  leg1(30, 0);
  leg3(30, 30);
  leg5(30, 17);
  leg2(-10, -15);
  leg4(-10, -2);
  leg6(-10, -32);
  delay(200);

  leg1(-10, -30);
  leg3(-10, 0);
  leg5(-10, -17);
  leg2(-10, 15);
  leg4(-10, 32);
  leg6(-10, 2);
  delay(200);

  leg1(-10, -30);
  leg3(-10, 0);
  leg5(-10, -17);
  leg2(30, 15);
  leg4(30, 32);
  leg6(30, 2);
  delay(200);
}

void walk(){
  leg1(-10, -30);
  leg3(-10, 0);
  leg5(-10, -17);
  leg2(30, 15);
  leg4(30, 32);
  leg6(30, 2);
  delay(200);

  leg1(-10, -30);
  leg3(-10, 0);
  leg5(-10, -17);
  leg2(-10, 15);
  leg4(-10, 32);
  leg6(-10, 2);
  delay(200);

  leg1(30, 0);
  leg3(30, 30);
  leg5(30, 17);
  leg2(-10, -15);
  leg4(-10, -2);
  leg6(-10, -32);
  delay(200);

  leg1(-10, 0);
  leg3(-10, 30);
  leg5(-10, 17);
  leg2(-10, -15);
  leg4(-10, -2);
  leg6(-10, -32);
  delay(200);
}

void turn(){
  leg1(-10, 15);
  leg3(-10, 15);
  leg5(-10, -15);
  leg2(30, -15);
  leg4(30, 15);
  leg6(30, 15);
  delay(100);

  leg1(-10, 15);
  leg3(-10, 15);
  leg5(-10, -15);
  leg2(-10, -15);
  leg4(-10, 15);
  leg6(-10, 15);
  delay(100);

  leg1(30, -15);
  leg3(30, -15);
  leg5(30, 15);
  leg2(-10, 15);
  leg4(-10, -15);
  leg6(-10, -15);
  delay(100);

  leg1(-10, -15);
  leg3(-10, -15);
  leg5(-10, 15);
  leg2(-10, 15);
  leg4(-10, -15);
  leg6(-10, -15);
  delay(100);
  
}

void turnl(){
  leg1(-10, -15);
  leg3(-10, -15);
  leg5(-10, 15);
  leg2(-10, 15);
  leg4(-10, -15);
  leg6(-10, -15);
  delay(100);

  leg1(30, -15);
  leg3(30, -15);
  leg5(30, 15);
  leg2(-10, 15);
  leg4(-10, -15);
  leg6(-10, -15);
  delay(100);

  leg1(-10, 15);
  leg3(-10, 15);
  leg5(-10, -15);
  leg2(-10, -15);
  leg4(-10, 15);
  leg6(-10, 15);
  delay(100);

  leg1(-10, 15);
  leg3(-10, 15);
  leg5(-10, -15);
  leg2(30, -15);
  leg4(30, 15);
  leg6(30, 15);
  delay(100);
}
