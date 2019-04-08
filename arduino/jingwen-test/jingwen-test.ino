/**
   Using TCA9548 I2C Multiplexer to control multiple DRV2605 vibration motor drivers
   TCA9548 code Based on code c. 2009, Tod E. Kurt, http://todbot.com/blog/

*/

#include <Wire.h>

extern "C" {
#include "utility/twi.h"  // from Wire library, so we can do bus scanning
}
#include "Adafruit_DRV2605.h"

Adafruit_DRV2605 drv;

#define TCAADDR 0x70 //define TCA address

//function for TCA9548A write to individual I2C devices
void tcaselect(uint8_t i) {
  if (i > 7) return;

  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission();
}

void setup() {
  Serial.begin(9600);
  Wire.begin();

  //set up driver on port 0
  tcaselect(0);
  drv.begin();
  // I2C trigger by sending 'go' command
  drv.setMode(DRV2605_MODE_INTTRIG); // default, internal trigger when sending GO command
  drv.selectLibrary(1);
  drv.setWaveform(0, 84);  // ramp up medium 1, see datasheet part 11.2
  drv.setWaveform(1, 1);  // strong click 100%, see datasheet part 11.2
  drv.setWaveform(2, 0);  // end of waveforms

  //set up driver on port 1
  tcaselect(1);
  drv.begin();
  // I2C trigger by sending 'go' command
  drv.setMode(DRV2605_MODE_INTTRIG); // default, internal trigger when sending GO command
  drv.selectLibrary(1);
  drv.setWaveform(0, 84);  // ramp up medium 1, see datasheet part 11.2
  drv.setWaveform(1, 1);  // strong click 100%, see datasheet part 11.2
  drv.setWaveform(2, 0);  // end of waveforms
}

void loop() {

  tcaselect(0);
  drv.go();

  tcaselect(1);
  drv.go();

}
