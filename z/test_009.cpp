// http://www.kocw.or.kr/home/search/kemView.do?kemId=1317915&ar=relateCourse
// Mat Operator
// Addition/Subtraction operation

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat img1 = imread("lena.png");
    Mat img2 = imread("lena.png");
    Mat dst;
    add(img1, img2, dst);
    imshow("dst", dst);
    
    waitKey(0);
    return 0;
}