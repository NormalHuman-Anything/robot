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
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  leg1(-40, 0);
  leg4(40, 0);
  delay(1000);

  leg4(40, 30);
  delay(1000);

  leg1(0, 0);
  leg4(0, 30);
  delay(1000);

  leg4(-40, 30);
  leg1(40, 30);
  delay(1000);

  leg3(-40, 0);
  leg6(40, 0);
  delay(1000);

  leg6(40, 30);
  delay(1000);

  leg3(0, 0);
  leg6(0, 30);
  delay(1000);

  leg6(-40, 30);
  leg3(40, 0);
  delay(1000);

  leg3(40, 30);
  delay(1000);

  leg3(0, 30);
  leg6(0, 30);
  delay(1000);

  leg1(0, 0);
  leg3(0, 0);
  leg4(0, 0);
  leg6(0, 0);
  delay(1000);
}