// http://www.kocw.or.kr/home/search/kemView.do?kemId=1317915&ar=relateCourse
// Drawing Function
// line(), circle()

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat image = imread("lena.jpg");
    Point p1(25, 25), p2(100, 50);

    line(image, p1, p2, Scalar(0,255,0), 1, 8, 0);
    circle(image, p2, 50, Scalar(255, 0, 0), 1, 8, 0);
    imshow("line(), circle()", image);
  
    waitKey(0);
    return 0;
}