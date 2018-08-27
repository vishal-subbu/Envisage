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
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


using namespace std;

unsigned char asc[2];
int ascii[2];
int image[16];int temp;

int main()
{
 ifstream myfile;
 myfile.open ("image.txt", ios::in);
  if (myfile.is_open())
  {
    cout<<"Final image"<<endl;
    while (!myfile.eof())
    {
      
          for(int n=0;n<16;n++)       
            {
             image[n]=5;
            }
      myfile>> ascii[0];
      myfile>> ascii[1];
      for(int j=0,k=0;k<2;j+=8,k++)
         {
          temp=ascii[k];
          image[j+7]=temp%2;temp/=2;
          image[j+6]=temp%2;temp/=2;
          image[j+5]=temp%2;temp/=2;
          image[j+4]=temp%2;temp/=2;
          image[j+3]=temp%2;temp/=2;
          image[j+2]=temp%2;temp/=2;
          image[j+1]=temp%2;temp/=2;
          image[j+0]=temp%2;temp/=2;

         }
          for(int n=0;n<16;n++)       
            {
             cout<<image[n];
            }
         cout<<endl;
         } 
   
    myfile.close();
    }

  else 
     cout << "Unable to open file"; 

 return 0;

}

