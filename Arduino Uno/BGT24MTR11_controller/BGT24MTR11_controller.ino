#include <SPI.h>

// SPI PinOut and Transmitted 16-bit Word
const int chipSelectNegPin = 10;    //chip select
const int clockPin = 13;   //clock
const int serialOutPin = 11;    //serial out

// const byte MSB = B00000000;     //LNA Gain Red off -          Not Used       -         Not Used       - disable TX pwr on -        AMUX2 0     -   Test Bit  -   Test Bit  -   AMUX1 0
// const byte LSB = B00001000;     //    AMUX0 0      - disable 64k divider off - disable 16 divider off - Hi LO buffer off  - High TX buffer off - TW pwr red2 - TW pwr red1 - TW pwr red0

const byte communication_MSB = B00000000;

// Full TX power:
const byte communication_LSB = B00001000;

// TX power reduced of 9dB:
// const byte communication_LSB = B00001111;

// TX power reduced of 6dB:
// const byte communication_LSB = B00001110;

// TX power reduced of 4dB:
// const byte communication_LSB = B00001101;

void setup() {

  pinMode(chipSelectNegPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(serialOutPin,OUTPUT);

  // Serial.begin(9600);

  // Serial.println("SPI communication started...");
  SPI.beginTransaction(SPISettings(125000,MSBFIRST,SPI_MODE0)); // min. 125kHz; strange signals on clockPin line due to this line.
  delay(1000);
  digitalWrite(chipSelectNegPin,HIGH);
  delay(0.2);
  digitalWrite(chipSelectNegPin,LOW);
  delay(0.2);
  SPI.transfer(communication_MSB);
  SPI.transfer(communication_LSB);
  delay(0.2);
  digitalWrite(chipSelectNegPin,HIGH);
  delay(0.2);
  SPI.endTransaction();
  // Serial.println("SPI communication ended.");

  }

void loop() {

}

/* Oscilloscope settings:
 *  channel: serialOutPin or clockPin
 *  channel 2: chipSelectPin
 *  trigger: channel 2, mode:edge, slope:positive, sweep:single
 *  horizontal scale: 20us
 *  vertical scale: 2V for both channels
 *  trigger: 108.8 us earlier
 */
