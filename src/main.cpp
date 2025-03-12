#include <Arduino.h>

int motor1pin1 = 2;
int motor1pin2 = 3;

int motor2pin1 = 4;
int motor2pin2 = 5;

void setup() {
  Serial.begin(115200);

  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  pinMode(9,  OUTPUT); 
  pinMode(10, OUTPUT);
}

void loop() {
  if(Serial.available() > 0) {
    String s = Serial.readStringUntil('\n');
    s.trim();
    Serial.println("=== " + s);

    int index = s.indexOf(' ');

    String mode = s.substring(0, index);
    String speedStr = s.substring(index+1);

    int speed = speedStr.toInt();

    analogWrite(9, speed);
    analogWrite(10, speed);

    if(mode == "forward") {
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);
      //digitalWrite(motor2pin1, HIGH);
      //digitalWrite(motor2pin2, LOW);
    } else if(mode == "back") {
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, HIGH);
      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, HIGH);
    } else if(mode == "left") {
      digitalWrite(motor1pin1, HIGH);
      digitalWrite(motor1pin2, LOW);
      digitalWrite(motor2pin1, LOW);
      digitalWrite(motor2pin2, HIGH);
    } else if(mode == "right") {
      digitalWrite(motor1pin1, LOW);
      digitalWrite(motor1pin2, HIGH);
      digitalWrite(motor2pin1, HIGH);
      digitalWrite(motor2pin2, LOW);
    }
  }

  //Controlling speed (0  = off and 255 = max speed):     
  //(Optional)
  /*analogWrite(9, 100); //ENA  pin
  analogWrite(10, 200); //ENB pin
  //(Optional)
  
  digitalWrite(motor1pin1,  HIGH);
  digitalWrite(motor1pin2, LOW);

  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
  delay(3000);

  digitalWrite(motor1pin1,  LOW);
  digitalWrite(motor1pin2, HIGH);

  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
  delay(3000);*/
}
