#include<Servo.h>
#include<Stepper.h>
int pot1=A0;
int pot2=A1;
int button1=2;
int button2=4;
Servo servo1;
Servo servo2;
Servo servo3;
Stepper stepper(360,8,9,10,11);
int previous=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
servo1.attach(3);
servo2.attach(5);
servo3.attach(6);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(pot1,INPUT);
pinMode(pot2,INPUT);
pinMode(button1,INPUT);
pinMode(button2,INPUT);
stepper.setSpeed(30);
}

void loop() {
  // put your main code here, to run repeatedly:
int pot1_val=analogRead(pot1);
int pot2_val=analogRead(pot2);
while( digitalRead(button1)==LOW and digitalRead(button2)==LOW){
  Serial.println("COMPLETE motion in action");
  int pos_val1=map(pot1_val,0,1023,0,180);
  servo1.write(pos_val1);
  int pos_val2=map(pot2_val,0,1023,0,180);
  servo2.write(pos_val2);
  break;
  
}
while(digitalRead(button1)==HIGH and digitalRead(button2)==HIGH){
  Serial.println("ROTATE and CATCH in action");
  int pos_val3=map(pot2_val,0,1023,0,180);
  servo3.write(pos_val3);
  int value=map(pot1_val,0,1023,0,360);
  stepper.step(value-previous);
  previous=value;
  break;
  
}
while(digitalRead(button1)==LOW and digitalRead(button2)==HIGH){
  Serial.println("MAIN JOINT and CATCH in action");
  int pos_val1=map(pot1_val,0,1023,0,180);
  servo1.write(pos_val1);
  int pos_val3=map(pot2_val,0,1023,0,180);
  servo3.write(pos_val3);
  break;
  
}
while(digitalRead(button1)==HIGH and digitalRead(button2)==LOW){
  Serial.println("SECONDARY JOINT and ROTATE in action");
  int pos_val2=map(pot2_val,0,1023,0,180);
  servo1.write(pos_val2);
  int value=map(pot1_val,0,1023,0,360);
  stepper.step(value-previous);
  previous=value;
  break;
  
}
}
