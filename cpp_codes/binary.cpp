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
 int temp[3];
for(int k=0;k<3;k++)
 cin>>temp[k];
 int image[24];
 for(int j=0,l=0;l<3;l++,j+=8)
 {
 image[j+7]=temp[l]%2;temp[l]/=2;
 image[j+6]=temp[l]%2;temp[l]/=2;
 image[j+5]=temp[l]%2;temp[l]/=2;
 image[j+4]=temp[l]%2;temp[l]/=2;
 image[j+3]=temp[l]%2;temp[l]/=2;
 image[j+2]=temp[l]%2;temp[l]/=2;
 image[j+1]=temp[l]%2;temp[l]/=2;
 image[j+0]=temp[l]%2;temp[l]/=2;
 }
 for(int i=0;i<24;i++)
    cout<<image[i]<<"  ";
  cout<<endl;
  waitKey(0);
  return(0);
}
  
 
