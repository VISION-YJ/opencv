// http://www.kocw.or.kr/home/search/kemView.do?kemId=1317915&ar=relateCourse
// Drawing Function
// rectangle()

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat image = imread("lena.jpg");
    Rect rect = Rect(10, 10, 100, 100); // LT pos, width, height
    rectangle(image, rect, Scalar(0, 255, 0), 1, 8, 0);
    imshow("draw a rangtangle on an image", image);
    
    waitKey(0);
    return 0;
}