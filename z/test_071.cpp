// http://www.kocw.or.kr/home/search/kemView.do?kemId=1317915&ar=relateCourse
// Color Processing
// - HSI, Pseudo Coloring, Color Balancing

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat image = imread ( "colorful.png" );
    imshow ( "image", image );

    Mat HSV, intensity_change, mask_out, change_color;
    vector<Mat> ic(3);
    vector<Mat> mo(3);
    vector<Mat> cc(3);

    int rows = image.rows;
    int cols = image.cols;

    uchar *h;
    uchar *s;
    uchar *v;

    cvtColor ( image, HSV, CV_BGR2HSV );
    split ( HSV, ic );
    split ( HSV, mo );
    split ( HSV, cc );

    // equalizing the histogram of I mat
    equalizeHist ( ic[2], ic[2] );

    // masking out except orange
    for ( int i = 0; i < rows; i++ ) {
        h = mo[0].ptr<uchar>(i);
        s = mo[1].ptr<uchar>(i);
        for ( int j = 0; j < cols; j++ ) {
            if ( h[j] > 9 && h[j] < 23 ) s[j] = s[j];
            else s[j] = 0;
        }
    }

    // changing all colors
    for ( int i = 0; i < rows; i++ ) {
        h = cc[0].ptr<uchar>(i);
        s = cc[1].ptr<uchar>(i);
        for ( int j = 0; j < cols; j++ ) {
            if ( h[j] + 50 > 255 ) h[j] = h[j] + 50 -255;
            else h[j] += 50;
        }
    }

    merge ( ic, intensity_change );
    merge ( mo, mask_out );
    merge ( cc, change_color );

    cvtColor ( intensity_change, intensity_change, CV_HSV2BGR );
    cvtColor ( mask_out, mask_out, CV_HSV2BGR );
    cvtColor ( change_color, change_color, CV_HSV2BGR );

    
    imshow ( "intensity change", intensity_change );
    imshow ( "mask out", mask_out );
    imshow ( "change color", change_color );
  
    waitKey(0);
    return 0;
}