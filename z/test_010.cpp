// http://www.kocw.or.kr/home/search/kemView.do?kemId=1317915&ar=relateCourse
// Mat Operator
// Threshold operation

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat image = imread("lena.png");
    cvtColor(image, image, CV_BGR2GRAY);
    Mat dst;

    // double threshold(Mat src, Mat dst, double thresh, double maxval, int type)
    threshold(image, dst, 100, 255, THRESH_BINARY_INV);

    imshow("dst", dst);
    imshow("image", image);

    waitKey(0);
    return 0;
}