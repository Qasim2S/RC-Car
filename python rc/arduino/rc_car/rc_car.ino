#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial hc06(9,10);
int pos = 90;
int newpos = 0;
Servo servo_9;
int motorPin = 4;
int motorPin2 = 5;
int motorPinspeed = 3;

void setup()
{
  pinMode(motorPin, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  hc06.begin(9600);
  Serial.begin(9600);
  Serial.println("hi");
  servo_9.attach(9);
  servo_9.write(pos);
  
}
void loop()
{
  //servo_9.write(90);
  //delay(3000);
  //servo_9.write(45);
  //delay(3000);
  if (hc06.available()>0){
    delay(10);
    String a = hc06.readString();
    Serial.println(a);
    if (a = "go"){
      if (digitalRead(motorPin) == HIGH){
        analogWrite(3, 0);
        digitalWrite(motorPin, LOW);
        digitalWrite(motorPin2, LOW);
        delay(100);
      } else {
        analogWrite(3, 10);
        digitalWrite(motorPin, HIGH);
        digitalWrite(motorPin2, LOW);
        delay(100);
      }
    } else {
      int pos = a.toInt();
      servo_9.write(pos);
      delay(100);
    }
    

    //if (pos = go){
      //#turn on and off motor pin
    //}
  }
  
}
