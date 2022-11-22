#include<Servo.h>
int servo_pin=9;
int pos=90;
int echo_pin=3;
int trig_pin=2;
int distance;
int distance_1=0;
int distance_2=0;
int duration;
int led_1=13;
int led_2=12;
Servo myservo;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myservo.attach(servo_pin);
pinMode(trig_pin,OUTPUT);
pinMode(echo_pin,INPUT);
pinMode(led_1,OUTPUT);
pinMode(led_2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trig_pin,LOW);
delay(200);
digitalWrite(trig_pin,HIGH);
delay(200);
digitalWrite(trig_pin,LOW);
duration=pulseIn(echo_pin,HIGH);
distance=(duration/2)/29.1;
Serial.print("distance seen is: ");
Serial.println(distance);
if (distance<8 and distance>0){
  myservo.write(30);
  digitalWrite(trig_pin,LOW);
  delay(200);
  digitalWrite(trig_pin,HIGH);
  delay(200);
  digitalWrite(trig_pin,LOW);
  duration=pulseIn(echo_pin,HIGH);
  distance_1=(duration/2)/29.1;
  Serial.print("distance seen at right: ");
  Serial.println(distance_1);
  delay(500);
  myservo.write(150);
  digitalWrite(trig_pin,LOW);
  delay(200);
  digitalWrite(trig_pin,HIGH);
  delay(200);
  digitalWrite(trig_pin,LOW);
  duration=pulseIn(echo_pin,HIGH);
  distance_2=(duration/2)/29.1;
  Serial.print("distance seen at left: ");
  Serial.println(distance_2);
  delay(500);
}
myservo.write(pos);
if (distance_1>distance_2){
  digitalWrite(led_1,HIGH);
  digitalWrite(led_2,LOW);
  Serial.println("yellow on");
  delay(1000);
}
else if (distance_1<distance_2){
  digitalWrite(led_2,HIGH);
  digitalWrite(led_1,LOW);
  Serial.println("white on");
  delay(1000);
}
else{
  digitalWrite(led_2,HIGH);
  digitalWrite(led_1,HIGH);
  Serial.println("both on");
  delay(1000);
}
}
