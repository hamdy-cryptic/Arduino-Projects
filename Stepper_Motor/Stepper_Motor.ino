#include<Stepper.h>
int pin1 = 8;
int pin2 = 9;
int pin3 = 10;
int pin4 = 11;
int pot_pin = A0;
int pot_val;
int previous = 0;
Stepper mystepper(1000, pin1, pin2, pin3, pin4);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pot_pin, INPUT);
  mystepper.setSpeed(30);
}

void loop() {
  // put your main code here, to run repeatedly:
  pot_val = analogRead(pot_pin);
  Serial.println((pot_val - previous));
  mystepper.step(1 * (pot_val - previous));
  previous = pot_val;

}
