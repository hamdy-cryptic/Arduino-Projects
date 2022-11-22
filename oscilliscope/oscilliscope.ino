// adjustable variables
int   channels = 2;                                                         // number of channels read

float ChannelHeight;
float ChannelScale;                                                      // proportion og signal to display
float Value;


void setup() {
  Serial.begin(115200);
  ChannelHeight = 5.0 ;
  ChannelScale = 5.0 / 1024.0; 
}

void loop() {
  for (int AnalogPin = 0; AnalogPin <= channels - 1; AnalogPin++) {     // sample 1-6 analog signals and display them
        Value = analogRead(AnalogPin);
        Value = Value * ChannelScale ; 
        Serial.print(Value);
        Serial.print(" ");
      }
      Serial.println("");
}
