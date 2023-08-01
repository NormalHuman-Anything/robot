#include <legangle.h>
void setup() {
  // put your setup code here, to run once:
  setservos();
  leg1(0, 0);
  leg2(60, 0);
  leg3(0, 0);
  leg4(0, 0);
  leg5(60, 0);
  leg6(0, 0);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  leg1(-10, 0);
  leg4(30, 0);
  delay(500);

  leg4(30, 30);
  delay(500);

  leg1(0, 0);
  leg4(0, 30);
  delay(500);

  leg4(-10, 30);
  leg1(30, 30);
  delay(30000000);

  leg3(-10, 0);
  leg6(30, 0);
  delay(500);

  leg6(30, 30);
  delay(500);

  leg3(0, 0);
  leg6(0, 30);
  delay(500);

  leg6(-10, 30);
  leg3(30, 0);
  delay(500);

  leg3(30, 30);
  delay(500);

  leg3(0, 30);
  leg6(0, 30);
  delay(500);

  leg1(0, 0);
  leg3(0, 0);
  leg4(0, 0);
  leg6(0, 0);
  delay(500);
}