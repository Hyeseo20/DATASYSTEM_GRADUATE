#include<Servo.h>
#define RAIN_SENSOR A0
#define SERVO_PIN 10
Servo myservo;

void setup(){
  Serial.begin(9600);
  myservo.attatch(SERVO_PIN);
  myservo.write(0);
}

void loop(){
  int rainValue = analogRead(RAIN_SENSOR);
  Serial.println(rainValue);
  if(rainValue >= 900) {
    myservo.rite(0);
    delay(10);
  }
  else{
    myservo.write(90);
    delay(10);
  }
}