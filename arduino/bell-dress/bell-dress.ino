/*
   Bell Dress
   Idit Barak & Noah Pivnick
   2189.00 Introduction to Wearables (Jingwen Zhu)
*/

#include <Wire.h>                // include arduino library for communicating with I2C devices
#include "Adafruit_DRV2605.h"    // include Adafruit library for working with the DRZV2605 Haptic Motor Driver

#define TCAADDR 0x70

Adafruit_DRV2605 drv;


void tcaselect(uint8_t i) {
  if (i > 7) return;

  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
}


void setup() {
  Serial.begin(9600);
  Serial.println("DRV test");

  tcaselect(0);
  drv.begin();

//  tcaselect(1);
//  drv.begin();
//
//  tcaselect(2);
//  drv.begin();
//
//  tcaselect(3);
//  drv.begin();
//
//  tcaselect(4);
//  drv.begin();
//
//  tcaselect(5);
//  drv.begin();
//
//  tcaselect(6);
//  drv.begin();
//
//  tcaselect(7);
//  drv.begin();

  // I2C trigger by sending 'go' command
  drv.setMode(DRV2605_MODE_INTTRIG); // default, internal trigger when sending GO command

  drv.selectLibrary(1);

  /*
    82 − Transition Ramp Up Long Smooth 1 – 0 to 100%
    83 − Transition Ramp Up Long Smooth 2 – 0 to 100%
  */

  drv.setWaveform(0, 82);  // see datasheet part 11.2
  drv.setWaveform(1, 83);  // see datasheet part 11.2
  drv.setWaveform(2, 0);   // end of waveforms

  Serial.println("end of setup");

}

void loop() {

  Serial.println("start of loop");

  tcaselect(0);
  Serial.println("bus 0 selected");
  // play the effect!
  drv.go();
  // wait a bit
  delay(1000);

//  tcaselect(1);
//  Serial.println("bus 1 selected");
//  // play the effect!
//  drv.go();
//  // wait a bit
//  delay(1000);
//
//  tcaselect(2);
//  Serial.println("bus 2 selected");
//  // play the effect!
//  drv.go();
//  // wait a bit
//  delay(1000);
//
//  tcaselect(3);
//  Serial.println("bus 3 selected");
//  // play the effect!
//  drv.go();
//  // wait a bit
//  delay(1000);
//
//  tcaselect(4);
//  Serial.println("bus 4 selected");
//  // play the effect!
//  drv.go();
//  // wait a bit
//  delay(1000);
//
//  tcaselect(5);
//  Serial.println("bus 5 selected");
//  // play the effect!
//  drv.go();
//  // wait a bit
//  delay(1000);
//
//  tcaselect(6);
//  Serial.println("bus 6 selected");
//  // play the effect!
//  drv.go();
//  // wait a bit
//  delay(1000);
//
//  tcaselect(7);
//  Serial.println("bus 7 selected");
//  // play the effect!
//  drv.go();
//  // wait a bit
//  delay(1000);
}
