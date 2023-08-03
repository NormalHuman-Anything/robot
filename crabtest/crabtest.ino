#include <newlegangle.h>
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
        break;

      case '2': //앞으로 이동 
        walk();
        num = '1';
        break;

      case '3': //회전
        turn();
        num = '1';
        break;   
      
      case '4':
        turnl();
        num = '1';
        break;   
        
      case '5':
        dance();
        num = '1';
        break;

      case '6':
        dance2();
        num = '1';
        break;

    }

  }
}

void dance(){//wave
  leg1(0, 0);
  leg2(0, 0);
  leg3(0, 0);
  leg4(0, 0);
  leg5(0, 0);
  leg6(0, 0);//초기화
  delay(500);

  for (int i = 0; i<=3; i++){//wavve
    leg1(60, 0);
    leg2(40, 0);
    leg3(-10, 0);
    leg4(-30, 0);
    leg5(-10, 0);
    leg6(40, 0);
    delay(300);

    leg1(40, 0);
    leg2(60, 0);
    leg3(40, 0);
    leg4(-10, 0);
    leg5(-30, 0);
    leg6(-10, 0);
    delay(300);

    leg1(-10, 0);
    leg2(40, 0);
    leg3(60, 0);
    leg4(40, 0);
    leg5(-10, 0);
    leg6(-30, 0);
    delay(300);

    leg1(-30, 0);
    leg2(-10, 0);
    leg3(40, 0);
    leg4(60, 0);
    leg5(40, 0);
    leg6(-10, 0);
    delay(300);

    leg1(-10, 0);
    leg2(-30, 0);
    leg3(-10, 0);
    leg4(40, 0);
    leg5(60, 0);
    leg6(40, 0);
    delay(300);

    leg1(40, 0);
    leg2(-10, 0);
    leg3(-30, 0);
    leg4(-10, 0);
    leg5(40, 0);
    leg6(60, 0);
    delay(300);
  };

  delay(1000);

  leg1(0, 0);
  leg2(0, 0);
  leg3(0, 0);
  leg4(0, 0);
  leg5(0, 0);
  leg6(0, 0);
}

void dance2(){//crab dance
  leg1(0, 0);
  leg2(0, 0);
  leg3(0, 0);
  leg4(0, 0);
  leg5(0, 0);
  leg6(0, 0);//초기화
  delay(00);

  kickleg2(-90, 50, 0);
  kickleg5(90, 50, 0);
  delay(150);

  leg2(0, 0);
  leg5(0, 0);
  delay(150);

  kickleg3(-90, 50, 0);
  kickleg6(90, 50, 0);
  delay(150);

  leg3(0, 0);
  leg6(0, 0);
  delay(150);

  kickleg4(90, 50, 0);
  kickleg1(-90, 50, 0);
  delay(150);

  leg4(0, 0);
  leg1(0, 0);
  delay(150);

  kickleg5(90, 50, 0);
  kickleg2(-90, 50, 0);
  delay(150);

  leg5(0, 0);
  leg2(0, 0);
  delay(150);

  kickleg3(-90, 50, 0);
  kickleg6(90, 50, 0);
  delay(150);

  leg3(0, 0);
  leg6(0, 0);
  delay(150);

  kickleg4(90, 50, 0);
  kickleg1(-90, 50, 0);
  delay(150);

  leg4(0, 0);
  leg1(0, 0);
  delay(150);
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
  leg1(-20, 0);
  leg3(-20, 30);
  leg5(-20, 17);
  leg2(-20, -15);
  leg4(-20, -2);
  leg6(-20, -32);
  delay(200);

  leg1(30, 0);
  leg3(30, 30);
  leg5(30, 17);
  leg2(-20, -15);
  leg4(-20, -2);
  leg6(-20, -32);
  delay(200);

  leg1(-20, -30);
  leg3(-20, 0);
  leg5(-20, -17);
  leg2(-20, 15);
  leg4(-20, 32);
  leg6(-20, 2);
  delay(200);

  leg1(-20, -30);
  leg3(-20, 0);
  leg5(-20, -17);
  leg2(30, 15);
  leg4(30, 32);
  leg6(30, 2);
  delay(200);
}

void walk(){
  leg1(-20, -30);
  leg3(-20, 0);
  leg5(-20, -17);
  leg2(30, 15);
  leg4(30, 32);
  leg6(30, 2);
  delay(200);

  leg1(-20, -30);
  leg3(-20, 0);
  leg5(-20, -17);
  leg2(-20, 15);
  leg4(-20, 32);
  leg6(-20, 2);
  delay(200);

  leg1(30, 0);
  leg3(30, 30);
  leg5(30, 17);
  leg2(-20, -15);
  leg4(-20, -2);
  leg6(-20, -32);
  delay(200);

  leg1(-20, 0);
  leg3(-20, 30);
  leg5(-20, 17);
  leg2(-20, -15);
  leg4(-20, -2);
  leg6(-20, -32);
  delay(200);
}

void turn(){
  leg1(-20, 15);
  leg3(-20, 15);
  leg5(-20, -15);
  leg2(30, -15);
  leg4(30, 15);
  leg6(30, 15);
  delay(100);

  leg1(-20, 15);
  leg3(-20, 15);
  leg5(-20, -15);
  leg2(-20, -15);
  leg4(-20, 15);
  leg6(-20, 15);
  delay(100);

  leg1(30, -15);
  leg3(30, -15);
  leg5(30, 15);
  leg2(-20, 15);
  leg4(-20, -15);
  leg6(-20, -15);
  delay(100);

  leg1(-20, -15);
  leg3(-20, -15);
  leg5(-20, 15);
  leg2(-20, 15);
  leg4(-20, -15);
  leg6(-20, -15);
  delay(100);
  
}

void turnl(){
  leg1(-20, -15);
  leg3(-20, -15);
  leg5(-20, 15);
  leg2(-20, 15);
  leg4(-20, -15);
  leg6(-20, -15);
  delay(100);

  leg1(30, -15);
  leg3(30, -15);
  leg5(30, 15);
  leg2(-20, 15);
  leg4(-20, -15);
  leg6(-20, -15);
  delay(100);

  leg1(-20, 15);
  leg3(-20, 15);
  leg5(-20, -15);
  leg2(-20, -15);
  leg4(-20, 15);
  leg6(-20, 15);
  delay(100);

  leg1(-20, 15);
  leg3(-20, 15);
  leg5(-20, -15);
  leg2(30, -15);
  leg4(30, 15);
  leg6(30, 15);
  delay(100);
}
