int led_pin=13;           //declaring variables used in code
int temp_pin=A0;
float temp;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(led_pin,OUTPUT);               // determining modes for pins and connectiong to serial monitor
pinMode(temp_pin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
temp=analogRead(temp_pin)*0.48828125;
if (temp<30){                                                //if statements to make code
  digitalWrite(led_pin,HIGH);
  delay(2000);}
else if (temp>35 and temp<60){
  Serial.println("it is getting hot here");
  digitalWrite(led_pin,LOW);
  delay(2000);}
else if (temp>=60){
  Serial.println("WE ARE LITERALLY ON FIRE");
  digitalWrite(led_pin,LOW);
  delay(2000);}
}
