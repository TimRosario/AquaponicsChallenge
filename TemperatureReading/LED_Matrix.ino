#include "LedControl.h"

/*
 LED Matrix Pins:
 pin 12 is connected to the DataIn 
 pin 11 is connected to LOAD(CS)
 pin 10 is connected to the CLK 
 */  
LedControl lc = LedControl(12,10,11,1);

byte arr[] = {B00000000,B00000000,
B00000000,B00000000,
B00000000,B00000000,
B00000000,B00000000};
 
void setBars(int height1, int height2,int height3){
  for(int i = 8 - height1; i < 8; i++){
    arr[i] = arr[i] | B11000000;
  }
  for(int i = 8 - height2; i < 8; i++){
    arr[i] = arr[i] | B00011000;
  }
  for(int i = 8 - height3; i < 8; i++){
    arr[i] = arr[i] | B00000011;
  }
  
  lc.setRow(0,0,arr[0]);
  lc.setRow(0,1,arr[1]);
  lc.setRow(0,2,arr[2]);
  lc.setRow(0,3,arr[3]);
  lc.setRow(0,4,arr[4]);
  lc.setRow(0,5,arr[5]);
  lc.setRow(0,6,arr[6]);
  lc.setRow(0,7,arr[7]);
  lc.setRow(0,8,arr[8]);
}

void setup() {
  lc.shutdown(0,false);
  lc.setIntensity(0,8);
  lc.clearDisplay(0);
}

void loop() { 
  setBars(4,4,4);
}
