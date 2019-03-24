/*
   Bell Dress (plan C)
   Idit Barak & Noah Pivnick
   2189.00 Introduction to Wearables (Jingwen Zhu)
*/

//Flora's onboard LED pin
const int ledPin = 7;

//capacitive touch sensor pin
const int ctsPin = 0;

//vibrating motor pins
const int motor1Pin = 9;
const int motor2Pin = 10;

int vibeMax = 255;   // max strength of motors


void setup() {
  Serial.begin(9600);      // We'll send debugging information via the Serial monitor

}

void loop() {

  int ctsValue = digitalRead(ctsPin);
  if (ctsValue == HIGH) {
    digitalWrite(ledPin, HIGH);
    bells();
    Serial.println("TOUCHED");
  }
  else {
    digitalWrite(ledPin, LOW);
    Serial.println("not touched");
  }
  delay(10);
}

void bells() {
    // fade in from min to max in increments of 4
  for (int fadeValue = 0 ; fadeValue <= vibeMax; fadeValue += 4) {
    // sets the value (range from 0 to 255):
    analogWrite(motor1Pin, fadeValue);
    analogWrite(motor2Pin, fadeValue);
    // wait for 20 milliseconds to see the dimming effect
    delay(20);
  }

  // fade out from max to min in increments of 4
  for (int fadeValue = vibeMax ; fadeValue >= 0; fadeValue -= 4) {
    // sets the value (range from 0 to 255):
    analogWrite(motor1Pin, fadeValue);
    analogWrite(motor2Pin, fadeValue);
    // wait for 20 milliseconds to see the dimming effect
    delay(20);
  }
}
