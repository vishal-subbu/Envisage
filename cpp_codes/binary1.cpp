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
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace cv;
using namespace std;

int main()
{
 int temp;
 int image[24];
 for(int i=0;i<24;i++)
    cin>>image[i];
for(int z=0;z<24;z+=8)
  {
   temp=(128*image[z+0])+(64*image[z+1])+(32*image[z+2])+(16*image[z+3])+(8*image[z+4])+(4*image[z+5])+(2*image[z+6])+(image[z+7]);
   cout<<temp<<endl;
  }
  waitKey(0);
  return(0);
}
