int latchPin=11;
int clockPin=9;
int dataPin=12;
int dt=500;

byte LEDs=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(latchPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("DEC: ");
  Serial.print(LEDs);
  Serial.print(" BIN: ");
  Serial.println(LEDs,BIN);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,LSBFIRST,LEDs);
  digitalWrite(latchPin,HIGH);
  LEDs=LEDs+1;
  delay(dt);

}
