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
byte values[]={0x00,0x00,0x01,0x00,0x03,0x00,0x07,0x00,0x03,0x00,0x01,0x00,0x00,0x00};
int index =0;
byte shift1;
byte shift2;

void setup()
{
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin, OUTPUT );
  pinMode(dataPin, OUTPUT );
  Serial.begin(9600);  
  Serial.println();
}//  END OF SETUP 

void loop()
{
    shift1=values[index];
    index++;
    shift2=values[index];
    index++;
    digitalWrite(latchPin,0);
    shiftOut(shift2);
    Serial.print("\t");
    shiftOut(shift1);
    Serial.println();
    digitalWrite(latchPin,1);
    delay(500);
    if(index>=13)
      index=0;
}
  


void shiftOut(byte value)
{
  int i=0;
  int pinstate;
  digitalWrite(dataPin,0);
  digitalWrite(clockPin,0);
  for(i=0;i<8;i++)
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
 
      
  


