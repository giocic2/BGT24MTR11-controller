/*
 * Library needed: https://github.com/javifercep/SPI-Slave.git
 */

#include <SPI.h>
#define BYTES_TOT 1

/* Arbitrary slave message. */
/*
byte slaveMessage[BYTES_TOT] = {
  B10000000,
  B11000000
};
*/
byte slaveMessage = B10000000;

/*
byte receivedMessage[BYTES_TOT];
*/
byte receivedMessage;
int index = 0;

void setup(){
  Serial.begin(9600);
  
  SPI.begin(SPI_SLAVE);
  SPI.setDataMode(SPI_MODE1);

  /* Print slave message */
  Serial.print(slaveMessage,BIN);
  /*
  while(index<BYTES_TOT){
    Serial.print(slaveMessage[BYTES_TOT-1-index], BIN);
    index++;
    }
  index=0;
  */

  /* Message exchange */
  SPI.attachInterrupt(messageExchange);

  /* Print received message */
  Serial.print(receivedMessage);
  /*
  while(index<BYTES_TOT){
    Serial.print(receivedMessage[BYTES_TOT-1-index], BIN);
    index++;
    }
  */
}

void loop(){

}

/*
void messageExchange(){
  while(index<BYTES_TOT){
    receivedMessage[BYTES_TOT-1-index]=SPI.transfer(slaveMessage[BYTES_TOT-1-index]);
    index++;
  }
  index=0;
}
*/
void messageExchange(){
  receivedMessage=SPI.transfer(slaveMessage);
}
