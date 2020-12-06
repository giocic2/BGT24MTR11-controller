#include <SPI.h>

// SPI PinOut and Transmitted 16-bit Word
const int cs = 10;    //chip select
const int clk = 13;   //clock
const int so = 11;    //serial out

const byte MSB = B00000000;     //LNA Gain Red off -          Not Used       -         Not Used       - disable TX pwr on -        AMUX2 0     -   Test Bit  -   Test Bit  -   AMUX1 0
const byte LSB = B00001000;     //    AMUX0 0      - disable 64k divider off - disable 16 divider off - Hi LO buffer off  - High TX buffer off - TW pwr red2 - TW pwr red1 - TW pwr red0

void setup() {

  pinMode(cs,OUTPUT);
  pinMode(clk,OUTPUT);
  pinMode(so,OUTPUT);

  Serial.begin(9600);

  Serial.println("SPI communication started...");
  SPI.beginTransaction(SPISettings(16000000,MSBFIRST,SPI_MODE1)); //16MHz
  digitalWrite(cs,HIGH);
  delay(100);
  digitalWrite(cs,LOW);
  delay(1);
  SPI.transfer(MSB);
  SPI.transfer(LSB);
  delay(1);
  digitalWrite(cs,HIGH);
  delay(100);
  SPI.endTransaction();
  Serial.println("SPI communication ended.");

  }

void loop() {

}
