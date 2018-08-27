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

Mat src; Mat src_blur;Mat src_thresh;

int main()
{
   src = imread(/home/vishal/Envisage/Pictures/alphabet-d-wallpapers-photos-4.jpg, 0);
  blur( src_blur, src, Size(3,3) );
  threshold( src_blur,src_thresh , 130,255,3 );
  
  for(int i=0; i<src.cols;i++)
      for(int j=0;j<src.rows;j++)
          {{cout<<src_thresh[i][j];}cout<<endl;}

  waitkey(0);
  return 0;
}
  


