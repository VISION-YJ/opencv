// http://www.kocw.or.kr/home/search/kemView.do?kemId=1317915&ar=relateCourse
// Intensity Transformation
// negatives, log, Power-Law, Thresholding

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat image = imread("lena.png", 0);
    Mat negative_img = image.clone();

    for (int i = 0; i < image.rows; i++)
        for (int j = 0; j < image.cols; j++)
            negative_img.at<uchar>(i,j) = 255 - image.at<uchar>(i,j);
    
    imshow("Input image", image);
    imshow("Negative transformation", negative_img);
  
    waitKey(0);
    return 0;
}