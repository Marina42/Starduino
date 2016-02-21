#include <Servo.h>
Servo test;
const int servoPin = 11;

void setup() {
  // put your setup code here, to run once:
  test.attach(servoPin);
  test.write(0);

}

void loop() {
  // put your main code here, to run repeatedly:
  test.write(90);
}
