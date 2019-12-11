const byte PULSANTE=2;
const byte MOTORE=5;
const byte LED=11;

void setup() {
pinMode(MOTORE, OUTPUT);
pinMode(PULSANTE, INPUT);
pinMode(LED,OUTPUT);

}

void loop() {
 byte statoBottone = digitalRead(PULSANTE);
 if (statoBottone== HIGH) {
  digitalWrite(LED, HIGH);
 }
 else {
  digitalWrite(LED, LOW);
 }
 delay(10);
  
}
