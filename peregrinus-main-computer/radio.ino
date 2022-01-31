/*
  https://github.com/jonsowman/librtty is needed, press the green Code button and Download ZIP. Then go to Sketch -> Include Library -> Add .ZIP Library and open the downloaded file from downloads.
*/
 

#include <rtty.h>
#include <types.h>

const int baud = 50;
const float stopbits = 1.5;


RTTY rtty(0, baud, stopbits, CHECKSUM_CRC16); //0 is placeholder


void initiateRadio(int pin) 
{
  rtty.setPin(pin);
  //rtty.setBaud(baud);
  //rtty.setStopbits(stopbits);
}


void transmitRadio(char *message) 
{
  rtty.transmit(message);
}
