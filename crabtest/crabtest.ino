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
      
      case '0': //명령 대기 상태
        stand();
        num = '1';
        break;

      case '1': //후진
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
      
      case '4': //우회전
        turnl();
        num = '1';
        break;   
        
      case '5': //춤
        dance();
        num = '1';
        break;

      case '6': //춤
        dance2();
        num = '1';
        break;

      case '7': //"그" 자세
        high();
        num = '1';
        break;

      case '8': //춤
        dance3();
        num = '1';
        break;

      case '9': //1번다리킥
        leg1kick();
        num = '1';
        break;

      case '10': //6번다리킥
        leg6kick();
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

void dance2(){//handwave
  leg1(0, 0);
  leg2(0, 0);
  leg3(0, 0);
  leg4(0, 0);
  leg5(0, 0);
  leg6(0, 0);//초기화
  delay(00);

  kickleg2(-120, 50, 0);
  kickleg5(120, 50, 0);
  delay(200);

  leg2(0, 0);
  leg5(0, 0);
  delay(200);

  kickleg3(-120, 50, 0);
  kickleg6(120, 50, 0);
  delay(200);

  leg3(0, 0);
  leg6(0, 0);
  delay(200);

  kickleg4(120, 50, 0);
  kickleg1(-120, 50, 0);
  delay(200);

  leg4(0, 0);
  leg1(0, 0);
  delay(200);

  kickleg5(120, 50, 0);
  kickleg2(-120, 50, 0);
  delay(200);

  leg5(0, 0);
  leg2(0, 0);
  delay(200);

  kickleg3(-120, 50, 0);
  kickleg6(120, 50, 0);
  delay(200);

  leg3(0, 0);
  leg6(0, 0);
  delay(200);

  kickleg4(120, 50, 0);
  kickleg1(-120, 50, 0);
  delay(200);

  leg4(0, 0);
  leg1(0, 0);
  delay(200);
}

void high(){//random shit
  kickleg1(-180, 90, 30);
  delay(800);
  kickleg1(-180, 90, 0);
  delay(800);
  kickleg1(0, 0, 0);
}

void dance3(){//useless
  leg1(-40, 0);
  leg3(-40, 0);
  leg5(-40, 0);
  leg2(-40, 0);
  leg4(-40, 0);
  leg6(-40, 0);
  delay(100);

  leg1(40, 0);
  leg3(40, 0);
  leg5(40, 0);
  leg2(40, 0);
  leg4(40, 0);
  leg6(40, 0);
  delay(10);
}

void stand(){
  leg1(0, 0);
  leg2(0, 0);
  leg3(0, 0);
  leg4(0, 0);
  leg5(0, 0);
  leg6(0, 0);
}

void unwalk(){//"un" walk
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

void walk(){//walk forwards
  leg1(-30, -30);
  leg3(-30, 0);
  leg5(-30, -17);
  leg2(40, 15);
  leg4(40, 32);
  leg6(40, 2);
  delay(250);

  leg1(-30, -30);
  leg3(-30, 0);
  leg5(-30, -17);
  leg2(-30, 15);
  leg4(-30, 32);
  leg6(-30, 2);
  delay(250);

  leg1(40, 0);
  leg3(40, 30);
  leg5(40, 17);
  leg2(-30, -15);
  leg4(-30, -2);
  leg6(-30, -32);
  delay(250);

  leg1(-30, 0);
  leg3(-30, 30);
  leg5(-30, 17);
  leg2(-30, -15);
  leg4(-30, -2);
  leg6(-30, -32);
  delay(250);
}

void turn (){//turn right
  leg1(-20, 15);
  leg3(-20, 15);
  leg5(-20, -15);
  leg2(30, -15);
  leg4(30, 15);
  leg6(30, 15);
  delay(200);

  leg1(-20, 15);
  leg3(-20, 15);
  leg5(-20, -15);
  leg2(-20, -15);
  leg4(-20, 15);
  leg6(-20, 15);
  delay(200);

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

void turnl(){//turn left
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

void leg1kick(){
  kickleg1(-80,0,-30);
  leg2(0, 0);
  leg3(0, 0);
  leg4(0, 0);
  leg5(0, 0);
  leg6(0, 0);
  delay(1000);

  kickleg1(-80,0,20);
  leg2(0, -50);
  leg3(0, -50);
  leg4(0, 50);
  leg5(0, 50);
  leg6(0, 50);
  delay(1000);

  leg1(30, 0);
  leg3(30, 0);
  leg5(30, 0);
  leg2(0, -50);
  leg4(0, 50);
  leg6(0, 50);
  delay(500);

  leg1(0, 0);
  leg3(0, 0);
  leg5(0, 0);
  leg2(0, -50);
  leg4(0, 50);
  leg6(0, 50);
  delay(500);

  leg1(0, 0);
  leg3(0, 0);
  leg5(0, 0);
  leg2(30, 0);
  leg4(30, 0);
  leg6(30, 0);
  delay(500);

  leg1(0, 0);
  leg3(0, 0);
  leg5(0, 0);
  leg2(0, 0);
  leg4(0, 0);
  leg6(0, 0);
  delay(500);
}

void leg6kick(){
  leg1(0, 0);
  leg2(0, 0);
  leg3(0, 0);
  leg4(0, 0);
  leg5(0, 0);
  kickleg6(80, 0, -30);
  delay(1000);

  leg1(0, 50);
  leg2(0, 50);
  leg3(0, 50);
  leg4(0, -50);
  leg5(0, -50);
  kickleg6(80, 0, 20);
  delay(1000);

  leg1(0, 50);
  leg3(0, 50);
  leg5(0, 50);
  leg2(30, 0);
  leg4(30, 0);
  leg6(30, 0);
  delay(500);

  leg1(0, 50);
  leg3(0, 50);
  leg5(0, 50);
  leg2(0, 0);
  leg4(0, 0);
  leg6(0, 0);
  delay(500);

  leg1(30, 0);
  leg3(30, 0);
  leg5(30, 0);
  leg2(0, 0);
  leg4(0, 0);
  leg6(0, 0);
  delay(500);

  leg1(0, 0);
  leg3(0, 0);
  leg5(0, 0);
  leg2(0, 0);
  leg4(0, 0);
  leg6(0, 0);
  delay(500);
}