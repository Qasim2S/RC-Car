#include <SoftwareSerial.h>
SoftwareSerial Bluetooth(9,10);

char c =' ';


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("ready");
  Bluetooth.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Bluetooth.available()){
  c=Bluetooth.read();
  Serial.write(c);
}
if(Serial.available()){
  c = Bluetooth.read();
  Bluetooth.write(c);
}
}
