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
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


using namespace cv;
using namespace std;

Mat src; Mat src_blur;Mat src_thresh;
unsigned char asc[100][12];
int ascii[100][12];
int image[100][96];int temp;

void retveive()
{
  for(int m=0; m<100;m++)
      {
        for(int n=0;n<96;n++)       
            {
             image[m][n]=1000;
            }
      }
  /*cout<<"displaying ascii"<<endl;
  for(int m=0; m<100;m++)
      {cout<<m<<"  ";
        for(int n=0;n<12;n++)       
            {
             cout<<asc[m][n]<<"  ";
            }
        cout<<endl;
      }*/
  for(int i=0;i<100;i++)
     {
      for(int j=0,k=0;k<12;j+=8,k++)
         {
          temp=asc[i][k];
          image[i][j+7]=temp%2;temp/=2;
          image[i][j+6]=temp%2;temp/=2;
          image[i][j+5]=temp%2;temp/=2;
          image[i][j+4]=temp%2;temp/=2;
          image[i][j+3]=temp%2;temp/=2;
          image[i][j+2]=temp%2;temp/=2;
          image[i][j+1]=temp%2;temp/=2;
          image[i][j+0]=temp%2;temp/=2;
          /*
          image[i][j]=temp%128;
          image[i][j+1]=temp%64;
          image[i][j+2]=temp%32;
          image[i][j+3]=temp%16;
          image[i][j+4]=temp%8;
          image[i][j+5]=temp%4;
          image[i][j+6]=temp%2;
          image[i][j+7]=temp%1;*/
         }
      }
  cout<<"Final image"<<endl;
  for(int m=0; m<100;m++)
      {cout<<m<<"  ";
        for(int n=0;n<96;n++)       
            {
             cout<<image[m][n];
            }
        cout<<endl;
      }
}
   
               
 
int main()
{
   src = imread("/home/vishal/Envisage/Pictures/e-is-for.jpeg", 0);
   //imshow("SRC",src);
  // resize(src, src_blur, Size(10,10));
  blur( src, src_blur, Size(3,3) );
  threshold( src_blur, src_thresh, 50, 255,THRESH_BINARY );
  //adaptiveThreshold( src_blur , src_thresh, 255,ADAPTIVE_THRESH_MEAN_C,THRESH_BINARY,25, 0 );
  cout<<endl<<endl<<endl;
  //imshow("Binary",src_thresh);
  resize(src_thresh, src_thresh, Size(50,100));
  //imshow("Small",src_thresh);
 /* for(int k=0; k<100;k++)
      {
        for(int l=0;l<12;l++)       
            {
             ascii[k][l]=3000;
            }
      }*/
   //cout<<"Entering ascii loop"<<endl;
  for(int i=0; i<src_thresh.rows;i++)
      {
        for(int j=0,z=0;z<12;j+=8,z++)       
            {
              ascii[i][z]=(128*(int((src_thresh.at<uchar>(i,j+0))/255)))+(64*(int((src_thresh.at<uchar>(i,j+1))/255)))+(32*(int((src_thresh.at<uchar>(i,j+2))/255)))+(16*(int((src_thresh.at<uchar>(i,j+3))/255)))+(8*(int((src_thresh.at<uchar>(i,j+4))/255)))+(4*(int((src_thresh.at<uchar>(i,j+5))/255)))+(2*(int((src_thresh.at<uchar>(i,j+6))/255)))+((int((src_thresh.at<uchar>(i,j+7))/255)));
              asc[i][z]=ascii[i][z];
            }
      }

  cout<<"Origial image"<<endl;
  for(int i=0; i<src_thresh.rows;i++)
      {cout<<i<<"  ";
        for(int j=0;j<src_thresh.cols;j++)       
            {
              cout<<int((src_thresh.at<uchar>(i,j))/255);
            }
        cout<<endl;
      }

/* cout<<"displaying ascii"<<endl;
  for(int m=0; m<100;m++)
      {cout<<m<<"  ";
        for(int n=0;n<12;n++)       
            {
             cout<<int(asc[m][n])<<"  ";
            }
        cout<<endl;
      }*/
  //retveive();

	
   
  waitKey(0);
  return(0);
}
 
/*cout<<int(src_thresh.at<uchar>(i,j));
adaptiveThreshold( InputArray src, OutputArray dst, double maxValue, int adaptiveMethod,
int thresholdType, int blockSize, double C )
threshold( InputArray src, OutputArray dst, double thresh, double maxval, int type )*/
