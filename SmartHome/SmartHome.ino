#include <LiquidCrystal.h>
#include <Key.h>
#include <Keypad.h>

int pir_pin=A4;
int temp_pin=A0;
int fan_pin=13;
int rgb_r=0;
int rgb_g=1;
//int rgb_b=9;
LiquidCrystal lcd(7,8,9,10,11,12);   //RS,E,D4,D5,D6,D7
const byte ROWS = 3; 
const byte COLS = 3; 
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'}
};
byte rowPins[ROWS] = {A5,2,3}; 
byte colPins[COLS] = {4,5,6}; 
int forward_pin=A1;
int backward_pin=A2;
int enable_pin=A3;

Keypad myKeyPad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void smartDoor();
void tempSensor();
void motionSensor();
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pir_pin,INPUT);
pinMode(temp_pin,INPUT);
pinMode(fan_pin,OUTPUT);
pinMode(rgb_r,OUTPUT);
pinMode(rgb_g,OUTPUT);
//pinMode(rgb_b,OUTPUT);
pinMode(forward_pin,OUTPUT);
pinMode(backward_pin,OUTPUT);
pinMode (enable_pin,OUTPUT);
lcd.begin(16,2);
}

void loop() {
  // put your main code here, to run repeatedly:
char input;
input=myKeyPad.getKey();
if (input){
smartDoor();
}
if (pir_pin==HIGH){

  motionSensor();
}

  tempSensor();
}

void motionSensor(){
  lcd.clear();
  lcd.home();
  lcd.print("Call the Police !");
    Serial.println("sensing motion");
    digitalWrite(rgb_g,LOW);
    digitalWrite(rgb_r,HIGH);
    delay(200);
    analogWrite(rgb_r,HIGH);
    analogWrite(rgb_g,150);
    delay(200);
  
    digitalWrite(rgb_r,LOW);
    //digitalWrite(rgb_b,LOW);
    digitalWrite(rgb_g,HIGH);
  }


void tempSensor(){
  int temp_read=analogRead(temp_pin);
  temp_read=temp_read/2;
  int threshold=22;
  if (temp_read>threshold){
    Serial.println("it is hot in here");
        Serial.println (temp_read);
    lcd.clear();
    lcd.home();
    lcd.print("High Temp =");
    lcd.print(temp_read);
    lcd.setCursor(5,1);
    lcd.print("Fan: ON");
    digitalWrite(fan_pin,HIGH);
    delay(150);
  }
  else{
    Serial.println("Temperature is normal");
    Serial.println (temp_read);
    lcd.clear();
    lcd.home();
    lcd.print("Temperature=");
lcd.print(temp_read);
    digitalWrite(fan_pin,LOW);
    delay(150);
  }
}

void doorOpen(){
  analogWrite(enable_pin,150);
  digitalWrite(forward_pin,HIGH);
  digitalWrite(backward_pin,LOW);
  delay(75);
    analogWrite(enable_pin,0);
  digitalWrite(forward_pin,LOW);
  digitalWrite(backward_pin,LOW);
}

void doorClose(){
    analogWrite(enable_pin,150);
  digitalWrite(forward_pin,LOW);
  digitalWrite(backward_pin,HIGH);
  delay(75);
    analogWrite(enable_pin,0);
  digitalWrite(forward_pin,LOW);
  digitalWrite(backward_pin,LOW);
}

bool passCheck(char arr[]){
   if(arr[0]=='1'&& arr[1]=='9'&& arr[2]=='9'&& arr[3]=='8')
      return true;
   else
      return false;
}

void smartDoor(){
  char pass[4];
  char input;
  lcd.clear();
  lcd.home();
  lcd.setCursor(1,0);
  lcd.print("Enter Password");
  lcd.setCursor(6,1);
  input=myKeyPad.getKey();
  while(!input){
  input=myKeyPad.getKey();
  if (input){
    break;
  }}
  Serial.println(input);
  pass[0]=input;
  lcd.print("*");
  input=myKeyPad.getKey();
  while(!input){
  input=myKeyPad.getKey();
  if (input){
    break;
  }}
    Serial.println(input);
  pass[1]=input;
    lcd.print("*");
input=myKeyPad.getKey();
  while(!input){
  input=myKeyPad.getKey();
  if (input){
    break;
  }}
  Serial.println(input);
  pass[2]=input;
    lcd.print("*");
 input=myKeyPad.getKey();
  while(!input){
  input=myKeyPad.getKey();
  if (input){
    break;
  }}
    Serial.println(input);
  pass[3]=input;
    lcd.print("*");
  if (passCheck(pass)){
    Serial.println("correct entry, opening gate");
    lcd.clear();
    lcd.home();
    lcd.print(" Opening Gate");
    doorOpen();
    delay(2000);
    doorClose();
  }
  else{
    Serial.println("Wrong Password");
    lcd.clear();
    lcd.home();
    lcd.print(" Incorrect Pass");
    delay(650);
  }
}

