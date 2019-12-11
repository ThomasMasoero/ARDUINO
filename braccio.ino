#define JOYSTICK_X A0
#define JOYSTICK_Y A1
#define JOYSTICK_BUTTON 2

#include <Servo.h>
Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

const byte PULSANTE1=13;
const byte PULSANTE2=12;
const byte PULSANTE3=11;
const byte PULSANTE4=10;


byte stato1=0;
byte stato2=0;
byte stato3=0;
byte stato4=0;

void setup() {
  Serial.begin(9600);
  pinMode(PULSANTE1, INPUT);
  pinMode(PULSANTE2, INPUT);
  pinMode(PULSANTE3, INPUT);
  pinMode(PULSANTE4, INPUT);

  pinMode(JOYSTICK_BUTTON, INPUT_PULLUP);
  myservo1.attach(7);
  myservo2.attach(6);
  myservo3.attach(5);
  myservo4.attach(4);


  
}

void loop() { 
  float x =analogRead(JOYSTICK_X);
  int y = analogRead(JOYSTICK_Y);
  int button = !digitalRead(JOYSTICK_BUTTON);
  byte valore= map(x, 0, 1023, 0, 180);
  byte valore_specc=map(x, 0, 1023, 180, 0);
  stato1= digitalRead(PULSANTE1);
  stato2= digitalRead(PULSANTE2);
  stato3= digitalRead(PULSANTE3);
  stato4= digitalRead(PULSANTE4);
  Serial.println(stato2);
  delay(100);

  if (stato1== HIGH) {
    myservo1.write(valore);
    myservo2.write(valore_specc);
    delay(100);
  } else if (stato2==HIGH) {
    myservo3.write(valore_specc);
  } else if (stato3==HIGH) { 
    myservo4.write(valore);
    }
  delay(100);
  }
