#include <SPI.h>

const int PWM = 7;
const int val = 127; // PWM amplitude, 26 equals to 55 mV
const int button = 30;

// SPI PinOut and Transmitted 16-bit Word
const int cs = 53;    //chip select
const int clk = 52;   //clock
const int so = 51;    //serial out

const byte MSB = B00000000;     //LNA Gain Red off -          Not Used       -         Not Used       - disable TX pwr on -        AMUX2 0     -   Test Bit  -   Test Bit  -   AMUX1 0
const byte LSB = B00001000;     //    AMUX0 0      - disable 64k divider off - disable 16 divider off - Hi LO buffer off  - High TX buffer off - TW pwr red2 - TW pwr red1 - TW pwr red0

void setup() {

  pinMode(PWM,OUTPUT);
  pinMode(button,INPUT);  //used to write the transceiver 16-bit register
  pinMode(A0,INPUT);  //ADC

  pinMode(cs,OUTPUT);
  pinMode(clk,OUTPUT);
  pinMode(so,OUTPUT);


  Serial.begin(9600);

  int myEraser = 7;     // this is 111 in binary and is used as an eraser
  TCCR4B &= ~myEraser;  // this operation (AND plus NOT),  set b0,b1 and b2 in TCCR1B to 0

  int myPrescaler = 1;    // this could be a number in [1 , 6]. In this case, 1 corresponds in binary to 001.
  TCCR4B |= myPrescaler;  //this operation (OR), replaces the last three bits in TCCR1B with our new value 001

  analogWrite(PWM, val);  //generate a 100kHz pwm signal with 'val' Duty Cycle (val/255 * 100%)

  }

void loop() {

  }

  if ( digitalRead(button) == LOW){
    //val = val+5;
    //delay(500);

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
    delay(1500);
  }
}
