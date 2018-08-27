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
//****************************************************
//                    HEADER FILES 
//****************************************************
#include <iostream>
#include<fstream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"


using namespace cv;
using namespace std;

//****************************************************
//                    VARIABLES 
//****************************************************
Mat src; Mat src_inv ;Mat src_blur;Mat src_thresh;
Mat map_x, map_y;
const int rows=200;
const int cols=64;
const int cols_ascii=cols/8;
int ascii[rows][cols_ascii];
int temp;               
int number=0;
 
int main(int argc, char **argv )
{

  //READING THE IMAGE

  src = imread(argv[1], 0);
  imshow( "Source",src );
  blur( src, src_blur, Size(3,3) );
  map_x.create( src.size(), CV_32FC1 );
  map_y.create( src.size(), CV_32FC1 );

   //INVERTING THE IMAGE
   
   for( int j = 0; j < src.rows; j++ )
   { for( int i = 0; i < src.cols; i++ )
       {
  		map_x.at<float>(j,i) = src_blur.cols-i ;
  		map_y.at<float>(j,i) = src_blur.rows - j;
  		}
  	}
  
  namedWindow( "Binary" , CV_WINDOW_AUTOSIZE );
  namedWindow( "Small", CV_WINDOW_NORMAL );	
  remap( src_blur, src_inv, map_x, map_y, CV_INTER_LINEAR, BORDER_CONSTANT, Scalar(0,0, 0) );
  resize(src_inv, src_thresh, Size(cols,rows),0,0,CV_INTER_AREA); 
  imshow( "Small",src_thresh );
  
  //CONVERTING IT INTO BINARY
 
  threshold( src_thresh, src_thresh, 15, 255,THRESH_BINARY );
  imshow( "Binary",src_thresh );      
     for(int i=0; i<src_thresh.rows;i++)
      {
        for(int j=0;j<src_thresh.cols;j++)       
            {
              src_thresh.at<uchar>(i,j)=int((src_thresh.at<uchar>(i,j))/255);
            }
      }      

  //CONVERTING IT INTO ASCII 	

  for(int i=0; i<src_thresh.rows;i++)
      {
        for(int j=0,z=0;z<8;j+=8,z++)       
            {
              ascii[i][z]=(128*(int(src_thresh.at<uchar>(i,j+0))))+(64*(int(src_thresh.at<uchar>(i,j+1))))+(32*(int(src_thresh.at<uchar>(i,j+2))))+
              (16*(int(src_thresh.at<uchar>(i,j+3))))+(8*(int(src_thresh.at<uchar>(i,j+4))))+(4*(int(src_thresh.at<uchar>(i,j+5))))+
              (2*(int(src_thresh.at<uchar>(i,j+6))))+((int(src_thresh.at<uchar>(i,j+7))));
            }
      }


   //DISPLAYING THE BINARY IMAGE

   for(int i=0; i<src_thresh.rows;i++)
      {
        for(int j=0;j<src_thresh.cols;j++)       
            {
              cout<<int(src_thresh.at<uchar>(i,j));
            }
            cout<<endl;
      }
	ofstream myfile;
	cout<<"Count"<<number<<"\n";

  //WRITING IT TO THE FILE

  myfile.open (argv[2], ios::out );
  if (myfile.is_open())
   { 
      for(int k=0;k<rows;k++)  
          for(int l=0;l<cols_ascii;l++)     
              {
                myfile << ascii[k][l]<<',';
                number++;
              }  
   }
	myfile<<'\n';
	myfile<<"Count"<<number;
	
  
  myfile.close();

	
   
  waitKey(0);
  return(0);
}
//****************************************************
//                    END OF PROGRAM 
//****************************************************

