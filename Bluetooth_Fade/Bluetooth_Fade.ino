int led_pin=9;
float input;
String string_input="";
int final_input;
void setup() {
  // put your setup code here, to run once:
pinMode(led_pin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()){
    while(Serial.available()){
  input=Serial.read();
  string_input+=input;
  final_input=(int) string_input;}
  
  analogWrite(led_pin,final_input-48);
  Serial.println(ana_input);
  break;

}
delay(40);
}
