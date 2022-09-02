char* message[1000];


struct dec_int {
  
    byte arr[2] = {0b00000000, 0b00000000}; 

};

struct dec_float {
  
    byte arr[4] = {0b00000000, 0b00000000, 0b00000000, 0b00000000};

};

struct dec_int i_getBytes(int a){
  struct dec_int i_struct;
  int b;

  for(int m = 1; m >= 0; m--){
    for(int n = 0; n <= 7; n++){
      bitWrite(i_struct.arr[m], n, bitRead(a, b));
      b++;
    }
  }

  return i_struct;
}

struct dec_float f_getBits(float a){
  struct dec_float f_struct;
  //https://stackoverflow.com/questions/14018894/how-to-convert-float-to-byte-array-of-length-4-array-of-char
  unsigned char const * p = reinterpret_cast<unsigned char const *>(&a);
  for (size_t i = 0; i != sizeof(float); ++i)
  { 
    f_struct.arr[3-i] = p[i]; //Change order of bytes to match IEEE-754
  }
  return f_struct;
}



void printIntStruct(struct dec_int a){
  for (int b = 0; b <= 1; b++){
      Serial.println(a.arr[b],BIN);
      //Serial.println(a.arr[b]);
  }
}

void printFloatStruct(struct dec_float a){
  for (int b = 0; b <= 3; b++){
      Serial.println(a.arr[b],BIN);
      //Serial.println(a.arr[b]);
  }
}




void setup() {
  Serial.begin(9600);
  int x = -26407;
  float y = -235.14;

  //printIntStruct(i_getBits(x));
  Serial.println();
  //printFloatStruct(f_getBits(y));

  Serial.print(f_getBits(y).arr[0],BIN);
  Serial.println();
  Serial.print(f_getBits(y).arr[1],BIN);
  Serial.println();
  Serial.print(f_getBits(y).arr[2],BIN);
  Serial.println();
  Serial.print(f_getBits(y).arr[3],BIN);

  for (int m=0; m<=3; m++){
  char cat;
  cat = char(f_getBits(y).arr[m]);
  strcat(message,cat);
  }
}
void loop() {
  
  
while (1);
  
}