// http://www.kocw.or.kr/home/search/kemView.do?kemId=1317915&ar=relateCourse
// Mat Operator
// ROI (Region of Interest) : A sub-region in an image that we are interested in.
// ROI 영상을 편집하면, 원본 영상도 영향을 받게 된다.

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat image = imread("lena.png");
    Rect rect(100, 30, 250, 300);   // start pos (x0,y0), width, height
    Mat rect_roi = image(rect);
    imshow("rectROI", rect_roi);

    waitKey(0);
    return 0;
}