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

//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595,CLK od SD
int clockPin = 12;
////Pin connected to DS of 74HC595,MOSI
int dataPin = 11;
//MISO pin
int valuePin =13;
//
int CS =4; 


//   SD card attached to arduino ass follows
// ** MOSI - pin 11
// ** MISO - pin 12
// ** CLK - pin 13
// ** CS - pin 4

//*********************************************
//                  HEADER FILES
//*********************************************
#include <SPI.h>
#include <SD.h>



// Variables for holding values 
byte shift1;
byte shift2;
File image;



void setup()
{
  pinMode(latchPin,OUTPUT);
  pinMode(CS,OUTPUT);
  pinMode(clockPin,OUTPUT);
  pinMode(valuePin,INPUT);
  Serial.begin(9600);
///////CHECK THE NEXT FEW LINES
  digitalWrite(latchPin,1);
  digitalWrite(CS,0);
  while (!Serial) 
   {
    ; // wait for serial port to connect. Needed for Leonardo only
   }
  
  
  Serial.print("Initializing SD card...");

  if (!SD.begin(CS)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
   image= SD.open("image.txt")
   if(image)
      {
        Serial.println("Opened file successfully");
      }
    
}//  END OF SETUP 


void loop()
{
  digitalWrite(latchpin,1);
  digitalWrite(CS,0);
  if(image.available())
    {
      shift1=image.read();
      shift2=image.read();
    }
  else
    {
      image.close();
      return;
    }
  
  digitalWrite(CS,1);
  digitalWrite(latchpin,0);
  shiftOut(shift2);
  shiftOut(shift1);
  digitalWrite(CS,1);
  digitalWrite(latchpin,1);
  delay(300);
}//    END OF LOOP


void shiftOut(byte value)
{
  int i=0;
  int pinstate;
  digitalWrite(dataPin,0);
  digitalWrite(clockPin,0);
  //Change the looping variables if the code works inverse
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
      digitalWrite(clockPin,1);
      digitalWrite)dataPin,0);
    }
    digitalWrite(clockPin,0) ;
    
}//   END OF SHIFT OUT
 
      
  

