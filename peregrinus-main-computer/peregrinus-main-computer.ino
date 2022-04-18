/* 
                                 _                 
                                (_)                
  _ __   ___ _ __ ___  __ _ _ __ _ _ __  _   _ ___ 
 | '_ \ / _ \ '__/ _ \/ _` | '__| | '_ \| | | / __|
 | |_) |  __/ | |  __/ (_| | |  | | | | | |_| \__ \
 | .__/ \___|_|  \___|\__, |_|  |_|_| |_|\__,_|___/
 | |                   __/ |                       
 |_|                  |___/                        


v1 - added rtty radio communication
v2 - added iridium communication
v3 - removed rtty radio communication
v4 - added data encoding

If you place program files (.ino) in the same folder, you can access the functions in them (any #include(d) files will imported aswel


To compile the program you currently need the following .ZIP Libraries (https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries + Code > Download ZIP)
  - https://github.com/mikalhart/IridiumSBD


Define all needed pins in the following way:
  #define name pinNumber 

  (technical reason is that it uses less memory and flash on the arduino)
*/

#define IRIDIUM_TX 10
#define IRIDIUM_RX 11

//Settings 
bool serial = true; 
bool iridium = true;


//Timing
unsigned long previousMillis = 0; //Timing
const long radioInterval = 10000; //Interval between radio transmissions


void setup()
{ 
  if (serial) Serial.begin(9600); //Used for debugging; REMOVE ON LAUNCH 
  
  if (iridium) { //Activate Iridium
    startIridium(19200);
    //initDatapoints(10);
  } 
  
}



//We are using millis() to keep track of time (instead of delay(), this can be used to accurately run a function every x seconds without stopping the arduino completely (meaning that you can send read sensor values and transmit radio at the same time!)
//https://docs.arduino.cc/built-in-examples/digital/BlinkWithoutDelay and https://www.arduino.cc/reference/en/language/functions/time/millis/


void loop()
{
  unsigned long currentMillis = millis(); //Update timings
                    
  // "if (currentMillis - previousMillis >= 2500) { previousMillis = currentMillis; Serial.print("Hello world");}" runs every 2.5 seconds! (2500ms = 2.5s)


  if (iridium && currentMillis - previousMillis >= 1000) {
    previousMillis = currentMillis;
    //        Radiation, magneto_x, magneto_y, magneto_z, gyro_x, gyro_y, gyro_z, voltage, temperature  (voltage and temperature will only get sent every 10s, the rest every 1s)
    //addDatapoint(3684,      -5368,      1395,    -513,      19263,  76054,  98862,  8762,     -16); //This function will take care of all iridium transmission needs, every 10th time it will transmit the data block
  }

       
}


//NOT NEEDED FOR LAUNCH; To test type v or q into the serial monitor
void serialEvent() 
{
  if (Serial.readStringUntil('\n') == "v") iridiumVersion(); //DEBUG
  if (Serial.readStringUntil('\n') == "q") iridiumQuality();
}
