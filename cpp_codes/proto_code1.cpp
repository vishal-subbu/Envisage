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

using namespace std;

int number = 0;
int array[16];
unsigned char asc[2];
int ascii[2];         
 
int main()
{
	ifstream readfile;
	readfile.open ("Allpat.txt",ios::in);
	ofstream myfile;
	myfile.open ("image.txt", ios::out | ios::app );
	if((readfile.is_open()) && (myfile.is_open()))
	{
		while(!readfile.eof())
		{
		    ascii[0]=0;
		    ascii[1]=0;
		    string line;
		    getline(readfile,line);
			for(int l=0;l<16;l++)
			{
    			switch(line[l])
    			{
    				case '0':array[l]=0;
    						break;
    				case '1':array[l]=1;
    						break;
    			}
    			ascii[l/8]=ascii[l/8]+pow(2,7-l%8)*array[l];
    		}
    		asc[0]=ascii[0];
    		asc[1]=ascii[1];
    		myfile << ascii[0];myfile << ',';
    		myfile << ascii[1];myfile << ',';
    		cout<<ascii[0]<<"  " <<ascii[1]<<endl;
    		number++;
    		number++;
		}
	}
	cout<<endl<<"Count"<<number<<endl;
	readfile.close();
	myfile.close();
	return 0;
}
