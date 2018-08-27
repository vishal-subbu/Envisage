//
// Copyright (c) 2018, Vishal_S
// All rights reserved. Please read the "license.txt" for license terms.
//
// Project Title: Waterfall Graphic Print
//
// Developer: Vishal S
//
// Contact Info: vishalsubbu97@gmail.com
//
//*************************************************************
//   CODE TO WRITE INFORMATION INTO TWO SHIFT REGISTERS
//                   USING COMMON PINS
//*************************************************************

//Pin connected to ST_CP(12) of 74HC595
int latchPin = 8;
//Pin connected to SH_CP(11) of 74HC595,CLK od SD
int clockPin = 13;
////Pin connected to DS(14) of 74HC595,MOSI
int dataPin = 11;


//*********************************************
//                  HEADER FILES
//*********************************************
#include <SPI.h>


// Variables for holding values 
byte shift1;
byte shift2;
byte values[]={240,0,15,0,0,240,0,15,240,0,15,0,0,240,0,15,240,0,15,0,0,240,0,15,240,0,15,0,0,240,0,15,240,0,15,0,0,240,0,15,240,0,15,0,0,240,0,15,240,0,15,0,0,240,0,15,240,0,15,0,0,240,0,15,240,0,15,0,0,240,0,15,0,0,192,3,48,12,12,48,3,192,12,48,48,12,192,3,192,3,48,12,12,48,3,192,12,48,48,12,192,3,192,3,48,12,12,48,3,192,12,48,48,12,192,3,192,3,48,12,12,48,3,192,12,48,48,12,192,3,192,3,48,12,12,48,3,192,12,48,48,12,192,3,192,0,48,0,12,0,3,0,0,192,0,48,0,12,0,3,0,12,0,48,0,192,3,0,12,0,48,0,192,0,192,0,48,0,12,0,3,0,0,192,0,48,0,12,0,3,0,12,0,48,0,192,3,0,12,0,48,0,192,0,192,0,48,0,12,0,3,0,0,192,0,48,0,12,0,3,0,12,0,48,0,192,3,0,12,0,48,0,192,0,240,0,240,0,240,0,240,0,15,0,15,0,15,0,15,0,0,240,0,240,0,240,0,240,0,15,0,15,0,15,0,15,0,240,0,240,0,240,0,240,15,0,15,0,15,0,15,0,240,0,240,0,240,0,240,0,240,0,240,0,240,0,240,0,0,0,0};
int index=0;


void setup()
{
  Serial.println("Entering Setup");
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  Serial.begin(9600);
  digitalWrite(latchPin,1);
  Serial.print('\n');
  Serial.println("Exiting Setup");

}//  END OF SETUP 


void loop()
{
  digitalWrite(latchPin,0);
  shift1=values[index];
  index++;
  shift2 = values[index];
  index++;
  shiftOut(shift2);
  Serial.print("\t");
  shiftOut(shift1);
  if(index >= 298)
     index=0;
  Serial.print('\n');
  digitalWrite(latchPin,1);  
  delay(1000);
}//    END OF LOOP


void shiftOut(byte value)
{
  int i=0;
  int pinstate;
  digitalWrite(dataPin,0);
  digitalWrite(clockPin,0);
  for(i=7;i>=0;i--)
    {
      digitalWrite(clockPin,0);
      if ( value & (1<<i) ) 
        {
          pinstate= 1;
        }
      else 
        {	
          pinstate= 0;
        }
      digitalWrite(dataPin,pinstate);
      Serial.print(pinstate);
      digitalWrite(clockPin,1);
      digitalWrite(dataPin,0);
    }
    digitalWrite(clockPin,0) ;
    
}//   END OF SHIFT OUT
 
      
  


