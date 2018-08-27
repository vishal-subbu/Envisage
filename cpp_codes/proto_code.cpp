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
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


using namespace cv;
using namespace std;

Mat src; Mat src_blur;Mat src_thresh;
unsigned char asc[10][2];
int ascii[10][2];         
 
int main()
{
   src = imread("/home/vishal/Envisage/Pictures/Rectangle.jpeg", 0);
  blur( src, src_blur, Size(3,3) );
  threshold( src_blur, src_thresh, 50, 255,THRESH_BINARY );
  //adaptiveThreshold( src_blur , src_thresh, 255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,25, 0 );
  cout<<endl<<endl<<endl;
  resize(src_thresh, src_thresh, Size(16,10));
  for(int i=0; i<src_thresh.rows;i++)
      {
        for(int j=0,z=0;z<2;j+=8,z++)       
            {
              ascii[i][z]=(128*(int((src_thresh.at<uchar>(i,j+7))/255)))+(64*(int((src_thresh.at<uchar>(i,j+6))/255)))+(32*(int((src_thresh.at<uchar>(i,j+5))/255)))+(16*(int((src_thresh.at<uchar>(i,j+4))/255)))+(8*(int((src_thresh.at<uchar>(i,j+3))/255)))+(4*(int((src_thresh.at<uchar>(i,j+2))/255)))+(2*(int((src_thresh.at<uchar>(i,j+1))/255)))+((int((src_thresh.at<uchar>(i,j+0))/255)));
              asc[i][z]=ascii[i][z];
            }
      }
  
    for(int i=0; i<src_thresh.rows;i++)
      {cout<<i<<"  ";
        for(int j=0;j<src_thresh.cols;j++)       
            {
              cout<<int((src_thresh.at<uchar>(i,j))/255);
            }
        cout<<endl;
      }
  ofstream myfile;
  myfile.open ("valve_comm.txt", ios::out | ios::app );
  if (myfile.is_open())
   { 
      for(int k=9;k>=0;k--)  
          for(int l=1;l>=0;l--)     
              {
                myfile << asc[k][l];
              }  
   }

	
  
  myfile.close();
  return 0;
}
 
/*cout<<int(src_thresh.at<uchar>(i,j));
adaptiveThreshold( InputArray src, OutputArray dst, double maxValue, int adaptiveMethod,
int thresholdType, int blockSize, double C )
threshold( InputArray src, OutputArray dst, double thresh, double maxval, int type )*/



