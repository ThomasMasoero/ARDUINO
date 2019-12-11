#define TRIG_PIN 10
#define ECHO_PIN 9
#include <Servo.h>
Servo myservo;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  digitalWrite(TRIG_PIN, LOW);
  myservo.attach(13);
  
}

void loop() {
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  //delayMicroseconds(10);
  unsigned long tempo= pulseIn(ECHO_PIN, HIGH);
  float distanza= 0.03438 * tempo / 2;
  Serial.println("Distanza: "+ String(distanza)+ "cm");
  delay(5 );
  if (distanza <=14) {
  myservo.write(90);
  delay(1000);
  myservo.write(0);

  
}
  

}
