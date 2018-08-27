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
int latchPin = 6;
//Pin connected to SH_CP(11) of 74HC595,CLK od SD
int clockPin = 7;
////Pin connected to DS(14) of 74HC595,MOSI
int dataPin = 4;

////Pin connected to SS of SD card
int S_S = 10;


//*********************************************
//                  HEADER FILES
//*********************************************
#include <SPI.h>
#include <EEPROM.h>
#include <SD.h>



// Variables for holding values 
int d=10;
File myFile;
int pinstate;
char c;  

void setup()
{
  pinMode(latchPin,OUTPUT);
  pinMode(clockPin, OUTPUT );
  pinMode(dataPin, OUTPUT );
  pinMode(S_S, OUTPUT);
  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  Serial.print("Initializing SD card...");
  if (!SD.begin(S_S)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  
    // re-open the file for reading:
  myFile = SD.open("main.TXT");
  if (myFile) {
    Serial.println("main.txt:");
    
    // read from the file until there's nothing else in it:
    // close the file:
  } else {
  	// if the file didn't open, print an error:
    Serial.println("error opening main.txt");
  }  
}//  END OF SETUP 

  


void loop()
{
 digitalWrite(latchPin,0);
 for(int i=0;i<64;)
 {
   c=myFile.read();
   digitalWrite(clockPin,0);
   digitalWrite(dataPin,0);
   if(c=='1')
   {
     pinstate=1;
     i++;    
     digitalWrite(dataPin,pinstate);
     Serial.print(pinstate);
     digitalWrite(clockPin,1);
   }
    else if(c=='0')
    {
      pinstate=0;
      i++;
      digitalWrite(dataPin,pinstate);
      Serial.print(pinstate);
      digitalWrite(clockPin,1);
     }
    
  }
  digitalWrite(latchPin,1);
  Serial.println();
  delay(d); 
  if(myFile.available()==0)
   {
     myFile.close();
     return;
   }


}//    END OF LOOP


