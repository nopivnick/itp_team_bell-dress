/*
   Bell Dress (plan B)
   Idit Barak & Noah Pivnick
   2189.00 Introduction to Wearables (Jingwen Zhu)
*/

// When Sig Output is high, touch sensor is being pressed
const int ctsPin = 0; // Pin for capactitive touch sensor
const int ledPin = 7; // pin for Flora's onboard LED
const int motor1Pin = 9;
const int motor2Pin = 10;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);
  pinMode(ctsPin, INPUT);
}

void loop() {
  int ctsValue = digitalRead(ctsPin);
  if (ctsValue == HIGH) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(motor1Pin, HIGH);
    digitalWrite(motor2Pin, HIGH);
    Serial.println("TOUCHED");
  }
  else {
    digitalWrite(ledPin, LOW);
    digitalWrite(motor1Pin, LOW);
    digitalWrite(motor2Pin, LOW);
    Serial.println("not touched");
  }
  delay(10);
}
