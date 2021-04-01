#include <Wire.h> 




int trig = 4;
int echo = 16;
long lecture_echo;
long cm;
int led = 25;
int buzzer = 26;

void setup(){
pinMode(trig, OUTPUT);
pinMode(led, OUTPUT);
pinMode(buzzer, OUTPUT);
digitalWrite(trig, LOW);
pinMode(echo, INPUT);
Serial.begin(9600);
digitalWrite(led, LOW);
digitalWrite(buzzer, LOW);
}

void loop(){
//digitalWrite(led, LOW);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
lecture_echo = pulseIn(echo,HIGH);
cm = lecture_echo /58;
Serial.print("Distance en cm :");
Serial.println(cm);
if(cm<=20){
  if(cm>4){
    digitalWrite(buzzer, HIGH);
    digitalWrite(led, HIGH);
    delay(cm*20);
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    delay(cm*20);
  }
  else{
    digitalWrite(led,HIGH);
    digitalWrite(buzzer, HIGH);
  }
}else{
  delay(1000);
}
}
