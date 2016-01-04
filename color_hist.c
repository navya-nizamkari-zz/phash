#include "highgui.hpp"
#include "imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
using namespace std;
using namespace cv;
clock_t begin, end;
double time_spent;
/**
 * @function main
 */
int main( int argc, char** argv )
{

    int s,i;
    char str[9];  
    char str2[5]=".jpg";
     Mat src_base, hsv_base;
    Mat src_test1, hsv_test1;
    for(s=1;s<=4;s++)
   {
    for(i=1;i<=300;i++)
    
   {
      int l=(s*1000)+i;
      sprintf(str,"%d",l);
      strcat(str,str2);
      char *ss=str;
      
      src_base = imread( argv[1], 1 );
    src_test1 = imread( argv[2], 1 );
    cvtColor( src_base, hsv_base, COLOR_BGR2HSV );
    cvtColor( src_test1, hsv_test1, COLOR_BGR2HSV );
    int h_bins = 50; int s_bins = 60;
    int histSize[] = { h_bins, s_bins };
    float h_ranges[] = { 0, 180 };
    float s_ranges[] = { 0, 256 };

    const float* ranges[] = { h_ranges, s_ranges };

    // Use the o-th and 1-st channels
    int channels[] = { 0, 1 };
    
    MatND hist_base;
    MatND hist_test1;
    calcHist( &hsv_base, 1, channels, Mat(), hist_base, 2, histSize, ranges, true, false );
    normalize( hist_base, hist_base, 0, 1, NORM_MINMAX, -1, Mat() );
    
    calcHist( &hsv_test1, 1, channels, Mat(), hist_test1, 2, histSize, ranges, true, false );
    normalize( hist_test1, hist_test1, 0, 1, NORM_MINMAX, -1, Mat() );

    
   
    double l0 = compareHist( hist_base, hist_test1, 0 );
    l0=1-l0;
    double l1 = compareHist( hist_base, hist_test1, 1 );
    double l2 = compareHist( hist_base, hist_test1, 2 );
    l1=1-l1;
    double l3 = compareHist( hist_base, hist_test1, 3 );
    if(l0<0.1&&l1<0.1&&l2<0.1&&l3<0.1);
    {
       printf("it might be from %d rd video",s);
    exit(0);
    }
  }
  }  
   return 0;
   } 
    
    
    
