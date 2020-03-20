// http://www.kocw.or.kr/home/search/kemView.do?kemId=1317915&ar=relateCourse
// Mat Operator
// Threshold operation
// 그레이스케일 영상을 받고 바이너리이미지 (각각의 픽셀값이 0 또는 255)를 얻는데 사용된다.

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat image = imread("lena.jpg");
    cvtColor(image, image, CV_BGR2GRAY);
    Mat dst;
    threshold(image, dst, 100, 155, THRESH_BINARY);

    imshow("dst", dst);
    imshow("image", image);
    
    waitKey(0);
    return 0;
}