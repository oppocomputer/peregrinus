unsigned int radiation[10];
long magneto_x[10];
long magneto_y[10];
long magneto_z[10];
int gyro_x[10];
int gyro_y[10];
int gyro_z[10];
unsigned int voltage;
char temperature;
char counter = 0;

void updateData(unsigned int rad_count, long mag_x, long mag_y, long mag_z, int gy_x, int gy_y, int gy_z, unsigned int volt, char temp){
  radiation[counter] = rad_count;
  magneto_x[counter] = mag_x;
  magneto_y[counter] = mag_y;
  magneto_z[counter] = mag_z;
  gyro_x[counter] = gy_x;
  gyro_y[counter] = gy_y;
  gyro_z[counter] = gy_z;
  voltage = volt;
  temperature = temp;

  if (counter == 9) {
    counter = -1; //Counter logic
    transmitData();  
  }
  counter = counter + 1;
}

void transmitData(){
  
}
