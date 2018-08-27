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
 int a=0;
 char alpha;
 for(a=0;a<256;a++)
    {
     alpha=a;
     cout<<a<<"  "<<alpha<<endl;
    }
  waitKey(0);
  return(0);
}
