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
int latchPin = 12;
//Pin connected to SH_CP(11) of 74HC595,CLK od SD
int clockPin = 11;
////Pin connected to DS(14) of 74HC595,MOSI
int dataPin = 8;


//*********************************************
//                  HEADER FILES
//*********************************************
#include <SPI.h>
#include <EEPROM.h>


// Variables for holding values 
byte shift1=0x00;
byte shift2=0x00;


void setup()
{
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin, OUTPUT );
  pinMode(dataPin, OUTPUT );
  Serial.begin(9600);  
    
}//  END OF SETUP 

  
void loop()
{
  shift1=0x80;
  shift2=0x00;
  while(shift1!=0)
  {
    digitalWrite(latchPin,0);
    shiftOut(shift2);
    shiftOut(shift1);
    Serial.println();
    digitalWrite(latchPin,1);
    delay(500);
    shift1=shift1/2;
  }
  shift2=0x80;
  while(shift2!=0)
  {
    digitalWrite(latchPin,0);
    shiftOut(shift2);
    shiftOut(shift1);
    Serial.println();
    digitalWrite(latchPin,1);
    delay(500);
    shift2=shift2/2;
  }
}//    END OF LOOP


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
 
      
  


