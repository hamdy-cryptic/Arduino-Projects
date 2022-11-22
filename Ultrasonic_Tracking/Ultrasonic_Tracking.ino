int echo_pin=5 , trig_pin=6;              //declaring ultrasonic variables
int distance;
int duration;
int motor_a_enable=9 , motor_b_enable=10;
int motor_a_forward=7 , motor_a_reverse=8;      //declaring motor variables
int motor_b_forward=11 , motor_b_reverse=12;    //please make the needed changes here to match the pins of your code
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);       //for debugging
pinMode(echo_pin,INPUT);
pinMode(trig_pin,OUTPUT);
pinMode(motor_a_enable,OUTPUT);
pinMode(motor_a_forward,OUTPUT);          //determine pin types
pinMode(motor_a_reverse,OUTPUT);
pinMode(motor_b_enable,OUTPUT);
pinMode(motor_b_reverse,OUTPUT);
pinMode(motor_b_forward,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trig_pin,LOW);
delay(200);                               // code for ultrasonic sensor
digitalWrite(trig_pin,HIGH);
delay(200);
digitalWrite(trig_pin,LOW);
duration= pulseIn(echo_pin,HIGH);
distance= (duration/2)/29.1;             //solve to get distance to use for motor direction
Serial.println(distance);
while(distance<0){
  analogWrite(motor_a_enable,200);
  digitalWrite(motor_a_forward,HIGH);
  digitalWrite(motor_a_reverse,LOW);          //looking for target
  analogWrite(motor_b_enable,0);
  digitalWrite(motor_b_forward,LOW);
  digitalWrite(motor_b_reverse,LOW);
  delay(1500);
  break;
  
}
if (distance>=0 and distance<7){
  analogWrite(motor_a_enable,110);
  digitalWrite(motor_a_forward,LOW);
  digitalWrite(motor_a_reverse,HIGH);          //too close to target
  analogWrite(motor_b_enable,110);
  digitalWrite(motor_b_forward,LOW);
  digitalWrite(motor_b_reverse,HIGH);
  delay(100);
}
else if(distance>=7 and distance<70){
  analogWrite(motor_a_enable,100);
  digitalWrite(motor_a_forward,HIGH);
  digitalWrite(motor_a_reverse,LOW);          //tracking target
  analogWrite(motor_b_enable,100);
  digitalWrite(motor_b_forward,HIGH);
  digitalWrite(motor_b_reverse,LOW);
}
else{
  analogWrite(motor_a_enable,0);
  digitalWrite(motor_a_forward,LOW);
  digitalWrite(motor_a_reverse,LOW);          //looking for target (out of range) other direction of rotation
  analogWrite(motor_b_enable,200);               
  digitalWrite(motor_b_forward,HIGH);
  digitalWrite(motor_b_reverse,LOW);
  
}
}
