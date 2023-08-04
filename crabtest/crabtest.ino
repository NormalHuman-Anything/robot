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

  pinMode(2, OUTPUT);
  pinMode(3, INPUT);

  pinMode(4, OUTPUT);
  pinMode(5, INPUT);
}

void loop() {

  while (Serial1.available()) { //Serial 통신으로 값이 들어 왔을 때 참(TRUE) --> Bluetooth stack 방지
    
    char num = Serial1.read();
    Serial.println(num);
    


    switch(num){
      
      case '1': //후진
        unwalk();
        break;

      case '2': //앞으로 이동 
        walk();
        break;

      case '3': //회전
        turn();
        break;   
      
      case '4': //좌회전
        turnl();
        break;   
        
      case '5': //느린걸음
        slowalk();
        break;

      case '6': //느린후진
        slounwalk();
        break;

      case '7': //느린회전
        sloturn();
        break;

      case '8': //느린좌회전
        sloturnl();
        break;

      case '9': //1번다리킥
        leg1kick();
        break;

      case 'a': //6번다리킥
        leg6kick();
        break;

      case 's': //자율주행모드
        selfdrive();
        break;

      case 'b': //wave
        dance();
        break;

      case 'c': //handwave
        dance2();
        break;

      case 'd': //handshake
        high();
        break;

      default: //명령 대기 상태
        stand();
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
    delay(100);

    leg1(40, 0);
    leg2(60, 0);
    leg3(40, 0);
    leg4(-10, 0);
    leg5(-30, 0);
    leg6(-10, 0);
    delay(100);

    leg1(-10, 0);
    leg2(40, 0);
    leg3(60, 0);
    leg4(40, 0);
    leg5(-10, 0);
    leg6(-30, 0);
    delay(100);

    leg1(-30, 0);
    leg2(-10, 0);
    leg3(40, 0);
    leg4(60, 0);
    leg5(40, 0);
    leg6(-10, 0);
    delay(100);

    leg1(-10, 0);
    leg2(-30, 0);
    leg3(-10, 0);
    leg4(40, 0);
    leg5(60, 0);
    leg6(40, 0);
    delay(100);

    leg1(40, 0);
    leg2(-10, 0);
    leg3(-30, 0);
    leg4(-10, 0);
    leg5(40, 0);
    leg6(60, 0);
    delay(100);
  };

  delay(500);

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
  leg1(0, 0);
  leg2(0, 0);
  leg3(0, 0);
  leg4(0, 0);
  leg5(0, 0);
  leg6(0, 0);
  delay(500);

  kickleg1(-180, 90, 30);
  delay(300);
  kickleg1(-180, 90, -10);
  delay(300);
  kickleg1(-180, 90, 30);
  delay(300);
  kickleg1(-180, 90, -10);
  delay(300);
  kickleg1(0, 0, 0);
}
/*
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
*/
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
  kickleg6(70, 50, 20);
  delay(1000);

  leg1(0, 50);
  leg2(0, 50);
  leg3(0, 50);
  leg4(0, -50);
  leg5(0, -50);
  kickleg6(70, 50, -30);
  delay(1000);

  leg1(0, 50);
  leg3(0, 50);
  leg5(0, -50);
  leg2(30, 50);
  leg4(30, 0);
  leg6(30, 0);
  delay(500);

  leg1(0, 50);
  leg3(0, 50);
  leg5(0, -50);
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

int ultrasonic1(){//앞
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);
  int distance1 = pulseIn(3, HIGH) * 17 / 1000;
  Serial.print("1st:");
  Serial.println(distance1);
  return distance1;
}

int ultrasonic2(){//오른쪽
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);
  int distance2 = pulseIn(3, HIGH) * 17 / 1000;
  Serial.print("2nd:");
  Serial.println(distance2);
  return distance2;
}

int cnt = 0;
void selfdrive(){
  if(ultrasonic1()<=30 && cnt == 0){
      turnl();
      delay(300);
      turnl();
      delay(300);
      turnl();
      delay(300);
      cnt++;
    }
    else if(ultrasonic1()<=30 && cnt == 1){
      turn();
      delay(300);
      turn();
      delay(300);
      turn();
      delay(300);
      cnt++;
    }else{
      walk();
      delay(400);
  }
}

void slounwalk(){//"un" walk
  leg1(-20, 0);
  leg3(-20, 15);
  leg5(-20, 8);
  leg2(-20, -7);
  leg4(-20, -1);
  leg6(-20, -16);
  delay(200);

  leg1(30, 0);
  leg3(30, 15);
  leg5(30, 8);
  leg2(-20, -7);
  leg4(-20, -1);
  leg6(-20, -16);
  delay(200);

  leg1(-20, -15);
  leg3(-20, 0);
  leg5(-20, -8);
  leg2(-20, 7);
  leg4(-20, 16);
  leg6(-20, 1);
  delay(200);

  leg1(-20, -15);
  leg3(-20, 0);
  leg5(-20, -8);
  leg2(30, -7);
  leg4(30, 16);
  leg6(30, 1);
  delay(200);
}

void slowalk(){//walk forwards
  leg1(-30, -15);
  leg3(-30, 0);
  leg5(-30, -8);
  leg2(40, 7);
  leg4(40, 16);
  leg6(40, 1);
  delay(150);

  leg1(-30, -15);
  leg3(-30, 0);
  leg5(-30, -8);
  leg2(-30, 7);
  leg4(-30, 16);
  leg6(-30, 1);
  delay(150);

  leg1(40, 0);
  leg3(40, 15);
  leg5(40, 8);
  leg2(-30, -7);
  leg4(-30, -1);
  leg6(-30, -16);
  delay(150);

  leg1(-30, 0);
  leg3(-30, 15);
  leg5(-30, 8);
  leg2(-30, -7);
  leg4(-30, -1);
  leg6(-30, -16);
  delay(150);
}

void sloturn (){//turn right
  leg1(-20, 5);
  leg3(-20, 5);
  leg5(-20, -5);
  leg2(30, -5);
  leg4(30, 5);
  leg6(30, 5);
  delay(100);

  leg1(-20, 5);
  leg3(-20, 5);
  leg5(-20, -5);
  leg2(-20, -5);
  leg4(-20, 5);
  leg6(-20, 5);
  delay(100);

  leg1(30, -5);
  leg3(30, -5);
  leg5(30, 5);
  leg2(-20, 5);
  leg4(-20, -5);
  leg6(-20, -5);
  delay(100);

  leg1(-20, -5);
  leg3(-20, -5);
  leg5(-20, 5);
  leg2(-20, 5);
  leg4(-20, -5);
  leg6(-20, -5);
  delay(100);
  
}

void sloturnl(){//turn left
  leg1(-20, -5);
  leg3(-20, -5);
  leg5(-20, 5);
  leg2(-20, 5);
  leg4(-20, -5);
  leg6(-20, -5);
  delay(100);

  leg1(30, -5);
  leg3(30, -5);
  leg5(30, 5);
  leg2(-20, 5);
  leg4(-20, -5);
  leg6(-20, -5);
  delay(100);

  leg1(-20, 5);
  leg3(-20, 5);
  leg5(-20, -5);
  leg2(-20, -5);
  leg4(-20, 5);
  leg6(-20, 5);
  delay(100);

  leg1(-20, 5);
  leg3(-20, 5);
  leg5(-20, -5);
  leg2(30, -5);
  leg4(30, 5);
  leg6(30, 5);
  delay(100);
}

