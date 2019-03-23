#include <SoftwareSerial.h>

int x_out = A3; 
int y_out = A2; 
int z_out = A1;

void setup() {
  Serial.begin(9600); 
}

void loop() {
  
  Serial.write(analogRead(x_out));
  Serial.write(analogRead(y_out));
  Serial.write(analogRead(z_out));
  
  delay(100);
}
