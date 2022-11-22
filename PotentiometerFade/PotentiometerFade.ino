int var_pin=A0 ;             //declaring values used in code
int led_pin=11 ;
int value;
void setup() {
  // put your setup code here, to run once:

pinMode(var_pin,INPUT);         //determine modes of pins used
pinMode(led_pin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
value=analogRead(var_pin);           //read potentiometer value 
analogWrite(led_pin,value/4);          //write value to led 
}                               //note that analogRead range is 0-1023
                                //while analogWrite range is 0-255 so divide value by 4
