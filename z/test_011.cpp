// http://www.kocw.or.kr/home/search/kemView.do?kemId=1317915&ar=relateCourse
// Mat Operator
// Adaptive threshold operation

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat image = imread("lena.jpg");
    cvtColor(image, image, CV_BGR2GRAY);
    Mat dst;
    adaptiveThreshold(image, dst, 
        255,    // image 영상에서 threshold를 넘었을 때, dst 영상에 표현할 값.
        ADAPTIVE_THRESH_MEAN_C, // 인접한 쓰레쑈울드의 평균값
        THRESH_BINARY, 
        7,      // 블락사이즈
        10);    // 상수 (평균값-10=> 쓰레쑈울드 값이 된다.)
    
    imshow("dst", dst);
    imshow("image", image);
    
    waitKey(0);
    return 0;
}