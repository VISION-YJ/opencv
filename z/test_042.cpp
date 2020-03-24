// http://www.kocw.or.kr/home/search/kemView.do?kemId=1317915&ar=relateCourse
// Intensity Transformation
// Log transformation

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat image = imread("lena.png", 0);
    Mat f_img, log_img;
    double c = 1.8f;    // scale constant (어둡게 < 1 < 밝게)
    image.convertTo(f_img, CV_32F); // log 함수를 사용하기 위해서 float형으로 변환한다.
    f_img = abs(f_img) + 1;
    log (f_img, f_img);
    normalize(f_img, f_img, 0, 255, NORM_MINMAX);   // normalize image to (0~255)
    convertScaleAbs(f_img, log_img, c); // scaling by c, conversion to an unsigned 8-bit type
    imshow("input image", image);
    imshow("Log transformation", log_img);
  
    waitKey(0);
    return 0;
}