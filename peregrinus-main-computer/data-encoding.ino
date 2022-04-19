//Data encoding

char bitstring[265];
char counter = 0;

//If you have never encountered structs before please review https://youtu.be/q24-QTbKQS8


//Object which contains the sensor readings
struct datapoint
{ 
  unsigned int radiation;
  long magneto_x;
  long magneto_y;
  long magneto_z;
  int gyro_x; 
  int gyro_y;
  int gyro_z;
  int accel_x;
  int accel_y;
  int accel_z;
};

struct status
{
  char voltage;
  char temperature;
};


//Initialize dataPoint objects
struct datapoint datapoints[10]; // dataPoint array of num length
struct datapoint *p_datapoint = datapoints; // "cursor" for changing data inside the dataPoint objects

struct status stat;

void addDatapoint(unsigned int rad_count, long mag_x, long mag_y, long mag_z, int gy_x, int gy_y, int gy_z, int acc_x, int acc_y, int acc_z, int volt, int temp)
{
  p_datapoint->radiation = rad_count; // 2 + 3*4 +3*2 + 3*2 = 26 bytes w/o volt + temp
  p_datapoint->magneto_x = mag_x; // 26*10 = 260 bytes -> 260 + 2 + 2 = 264 bytes w/ volt + temp -> 264 byte packet size
  p_datapoint->magneto_y = mag_y;
  p_datapoint->magneto_z = mag_z;
  p_datapoint->gyro_x = gy_x;
  p_datapoint->gyro_y = gy_y;
  p_datapoint->gyro_z = gy_z;
  p_datapoint->accel_x = acc_x;
  p_datapoint->accel_y = acc_y;
  p_datapoint->accel_z = acc_z;

  
  //Counter logic
  if (counter == 9){
    stat.voltage = volt;
    stat.temperature = temp;

    p_datapoint -= 9;
    counter = 0; 
    transmitData(datapoints, stat);  
  } else 
  {
    p_datapoint++; //Move "cursor" to next p_dataPoint
    counter++;
  }  
}


void transmitData(datapoint data1[], stat data2)
{
  
}
