#include <Servo.h>
#include <SoftwareSerial.h>

int motorPin = 4;
int motorPin2 = 5;
int motorPinspeed = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin, OUTPUT);
  pinMode(motorPin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
        analogWrite(3, 100);
        digitalWrite(motorPin, HIGH);
        digitalWrite(motorPin2, LOW);
}
