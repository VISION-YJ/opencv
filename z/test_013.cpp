// http://www.kocw.or.kr/home/search/kemView.do?kemId=1317915&ar=relateCourse
// Mat Operator
// convertTo(), convertScaleAbs(), setTo(Scalar(0))

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat image = imread("hand.png");
    imshow("original", image);

    Mat after_convertTo;
    image.convertTo(after_convertTo, CV_16SC1);
    imshow("after convertTo", after_convertTo);

    Mat after_convertScaleAbs;
    convertScaleAbs(image, after_convertScaleAbs, 2, 3);
    imshow("after convertScaleAbs", after_convertScaleAbs);

    image.setTo(Scalar(0)); // set to black.
    imshow("after setTo", image);
    
    waitKey(0);
    return 0;
}