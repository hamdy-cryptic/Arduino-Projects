#include "Servo.h"
Servo AAMT;
Servo MATA;


char m1f = 2;
char m1b = 8;
char m2f = 10;
char m2b = 11;
char bluetooth_reading;

void setup() {
  // put yoursetup code here, to run once:
  AAMT.attach(5);
  MATA.attach(4);
  Serial.begin (9600);
  pinMode(m1f,OUTPUT);
  pinMode(m1b,OUTPUT);
  pinMode(m2f,OUTPUT);
  pinMode(m2b,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()){
  bluetooth_reading = Serial.read();
  if(bluetooth_reading == 'F'){
    digitalWrite(m1f,HIGH);
    digitalWrite(m2f,HIGH);
    digitalWrite(m1b,LOW);
    digitalWrite(m2b,LOW);
    Serial.println(bluetooth_reading);
  }
  if(bluetooth_reading == 'B'){
    digitalWrite(m1f,LOW);
    digitalWrite(m2f,LOW);
    digitalWrite(m1b,HIGH);
    digitalWrite(m2b,HIGH);
    Serial.println(bluetooth_reading);
  }
  if(bluetooth_reading == 'L'){
    digitalWrite(m1f,HIGH);
    digitalWrite(m2f,LOW);
    digitalWrite(m1b,LOW);
    digitalWrite(m2b,HIGH);
    Serial.println(bluetooth_reading);
  }
  if(bluetooth_reading == 'R'){
    digitalWrite(m1f,LOW);
    digitalWrite(m2f,HIGH);
    digitalWrite(m1b,HIGH);
    digitalWrite(m2b,LOW);
    Serial.println(bluetooth_reading);
  }
  if(bluetooth_reading == 'S'){
    digitalWrite(m1f,LOW);
    digitalWrite(m2f,LOW);
    digitalWrite(m1b,LOW);
    digitalWrite(m2b,LOW);
    Serial.println(bluetooth_reading);
  }
  if(bluetooth_reading == 'W'){
    MATA.write(90);
    
  }
  if(bluetooth_reading == 'w'){
    MATA.write(0);
  }
 if(bluetooth_reading == 'U'){
    AAMT.write(180);
    
  }
  if(bluetooth_reading == 'u'){
    AAMT.write(0);
    
  } 
}}
