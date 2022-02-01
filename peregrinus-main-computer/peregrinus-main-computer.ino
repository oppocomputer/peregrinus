/* 
                                 _                 
                                (_)                
  _ __   ___ _ __ ___  __ _ _ __ _ _ __  _   _ ___ 
 | '_ \ / _ \ '__/ _ \/ _` | '__| | '_ \| | | / __|
 | |_) |  __/ | |  __/ (_| | |  | | | | | |_| \__ \
 | .__/ \___|_|  \___|\__, |_|  |_|_| |_|\__,_|___/
 | |                   __/ |                       
 |_|                  |___/                        


v1 - added radio communication


If you place program files (.ino) in the same folder, you can access the functions in them (any #include(d) files will imported aswell)


To compile the program you currently need the following .ZIP Libraries (look in radio for instruction)
  - https://github.com/oppocomputer/librtty


Define all needed pins in the following way:
  #define name pinNumber 

If you need help to include a program, just send the .ino to spaceheadingdeezers at gmail.com
*/


#define RADIOPIN 5 





//RADIO
char message[200]; //String of characters to transmit; Used for radiocommunication
const char callsign[7] = "ON6GMZ";



//TESTING
float temperature = 32.651;
char tempBuffer[10];




//Timing
unsigned long previousMillis = 0; //Timing
const long radioInterval = 10000; //Interval between radio transmissions


void setup()
{ 
  Serial.begin(9600); //Used for debugging; REMOVE ON LAUNCH 
  
  pinMode(RADIOPIN,OUTPUT); //Radio control pin (TXD)

  initiateRadio(RADIOPIN);

}



//We are using millis() to keep track of time (instead of delay(), this can be used to accurately run a function every x seconds without stopping the arduino completely (meaning that you can send read sensor values and transmit radio at the same time!)
//https://docs.arduino.cc/built-in-examples/digital/BlinkWithoutDelay and https://www.arduino.cc/reference/en/language/functions/time/millis/
//If you have a delay in your code and dont know how to adapt it into the program just send us a mail (spaceheadingdeezers at gmail.com)


void loop()
{
  unsigned long currentMillis = millis(); //Update timings                  
  // "if (currentMillis - previousMillis >= 2500) {}" runs every 2.5 seconds! (2500ms = 2.5s)





  //Radio    
  if (currentMillis - previousMillis >= radioInterval) 
  {
    previousMillis = currentMillis; //Update millis


    dtostrf(temperature, 0, 3, tempBuffer); //Float values cant directly be used in sprintf so are first converted to a string; More info https://www.programmingelectronics.com/dtostrf/ 
    sprintf(message, "%s T= %s", callsign, tempBuffer); //More info https://www.programmingelectronics.com/sprintf-arduino/
    
    transmitRadio(message);
    Serial.print(message); //REMOVE ON LAUNCH
  }                   
 
       
}
