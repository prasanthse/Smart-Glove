#include <SoftwareSerial.h>
#include <Servo.h>

int IN1 = 2;    //Right Motor (-)
int IN2 = 4;    //Right Motor (+)
int IN3 = 7;    //Left Motor (+)
int IN4 = 6;    //Left Motor (-)
int pos = 0;    //for Servo motor

Servo myservo;

void setup() {
  Serial.begin(9600);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  myservo.attach(9);  
}

void loop() {

  int x = Serial.read();
  int y = Serial.read();
  int z = Serial.read();

  /*Serial.print(x);
  Serial.print("\t");
  Serial.print(y);
  Serial.print("\t");
  Serial.print(z);
  Serial.print("\n");*/

  int data[] = {x, y, z};
  
  if(data[0] < 60){
      //forward            
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
    }
    
    if(data[0] > 110){
      //backward              
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
    }
     
    if(data[2] < 100){
      //left
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);

      for (pos = 0; pos <= 90; pos += 1) {//Left
        myservo.write(pos);              
        delay(15);                       
      }
    }

    if(data[2] > 100 && data[2] < 130){
      //right
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);

      for (pos = 90; pos >= 0; pos -= 1) { //Right
        myservo.write(pos);              
        delay(15);                       
      }
    }

    if(data[0] > 80 && data[0] < 90 && data[1] > 70 && data[1] < 110 && data[2] < 150 && data[2] > 140){
      //stop car
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
    }

    delay(500);
}

//Motors
//yellow, Orange - plus 


//Servo Motor
//Red - 5V
//Yellow - pin 9
//Brown - GND
