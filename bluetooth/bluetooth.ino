#include <SoftwareSerial.h>

void setup() {
 Serial1.begin(9600);  //Serial1 == 18 19번핀 --> Bluetooth module 과 arduino 와의 시리얼 통신
 Serial.begin(9600);
}


/*--------------------------------------------------------------------------


사용할 함수 정의


----------------------------------------------------------------------------*/

void loop() {

  while (Serial1.available()) { //Serial 통신으로 값이 들어 왔을 때 참(TRUE) --> Bluetooth stack 방지
    
    char num = Serial1.read();
    Serial.println(num);

    switch(num){
      
      case '1': //명령 대기 상태
        //stand();
        
        break;

      case '2': //앞으로 이동 
        //walk();
        num = '1';
        delay(1000);
        break;

      case '3': //회전
        //turn();
        num = '1';
        delay(1000);
        break;   
    }

  }
  
}


