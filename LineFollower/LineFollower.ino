int motor_R_enable=6;
int motor_R_forward=7;
int motor_R_backward=8;
int motor_L_enable=9;
int motor_L_forward=10;
int motor_L_backward=11;
int right_sensor=2;
int left_sensor=3;

void setup() {
  // put your setup code here, to run once:
pinMode(motor_R_enable,OUTPUT);
pinMode(motor_R_forward,OUTPUT);
pinMode(motor_R_backward,OUTPUT);
pinMode(motor_L_enable,OUTPUT);
pinMode(motor_L_forward,OUTPUT);
pinMode(motor_L_backward,OUTPUT);
pinMode(right_sensor,INPUT);
pinMode(left_sensor,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if (digitalRead(right_sensor)==true and digitalRead(left_sensor)==true)
{analogWrite(motor_R_enable,170);
digitalWrite(motor_R_backward,LOW);
digitalWrite(motor_R_forward,HIGH); 
analogWrite(motor_L_enable,170);
digitalWrite(motor_L_backward,LOW);
digitalWrite(motor_L_forward,HIGH);
Serial.println("Moving Forward");
delay(200);
}
else if (digitalRead(right_sensor)==true and digitalRead(left_sensor)==false)
{analogWrite(motor_R_enable,0);
digitalWrite(motor_R_backward,LOW);
digitalWrite(motor_R_forward,LOW); 
analogWrite(motor_L_enable,170);
digitalWrite(motor_L_backward,LOW);
digitalWrite(motor_L_forward,HIGH);
Serial.println("Turning Right");
delay(200);
}
else if (digitalRead(right_sensor)==false and digitalRead(left_sensor)==true)
{analogWrite(motor_R_enable,170);
digitalWrite(motor_R_backward,LOW);
digitalWrite(motor_R_forward,HIGH); 
analogWrite(motor_L_enable,0);
digitalWrite(motor_L_backward,LOW);
digitalWrite(motor_L_forward,LOW);
Serial.println("Turning Left");
delay(200);
}
else if (digitalRead(right_sensor)==false and digitalRead(left_sensor)==false)
{analogWrite(motor_R_enable,0);
digitalWrite(motor_R_backward,LOW);
digitalWrite(motor_R_forward,LOW); 
analogWrite(motor_L_enable,0);
digitalWrite(motor_L_backward,LOW);
digitalWrite(motor_L_forward,LOW);Serial.println("Finish Line :D");
delay(200);}}
