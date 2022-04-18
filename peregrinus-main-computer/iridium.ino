//Iridium RockBLOCK control script
#include <IridiumSBD.h>
#include <SoftwareSerial.h> 

SoftwareSerial iridiumSerial(IRIDIUM_RX, IRIDIUM_TX);
IridiumSBD modem(iridiumSerial);

//Remove version + quality upon launch
char version[12];
int quality;
int err;

void startIridium(int baud)
{

  iridiumSerial.begin(baud);
  err = modem.begin();
  if (err != ISBD_SUCCESS){
    if (serial) {
      Serial.println("Begin failed!");
          if (err == ISBD_NO_MODEM_DETECTED) Serial.println("No modem detected: check wiring.");
    }
    
    return;
  }
}


void transmitIridium()
{
  
  
}


void iridiumVersion(){
  err = modem.getFirmwareVersion(version, sizeof(version));
  Serial.print(err);
}

void iridiumQuality(){
  err = modem.getSignalQuality(quality);
  Serial.print(err);
}
