#define output_pin  5
void setup() {
  // put your setup code here, to run once:
  pinMode(output_pin,OUTPUT);
  
}

void squareWave(int pin, float dutyCycle ,int timePeriod,int pulse_mode){
    int on_time = (dutyCycle/100)*timePeriod;
    int off_time = timePeriod-on_time;
    digitalWrite(pin,HIGH);
    delay(on_time);
    digitalWrite(pin,LOW);
    delay(off_time);
    if (pulse_mode == 1){
      while(1){
        
      }
    }
    else{
      
    }
}


void loop() {
  // put your main code here, to run repeatedly:
squareWave(output_pin,100,100,0);
}
