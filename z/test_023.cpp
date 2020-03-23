// http://www.kocw.or.kr/home/search/kemView.do?kemId=1317915&ar=relateCourse
// Drawing Function
// putText()

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat image = Mat::zeros(400, 600, CV_8UC3);
    int w = image.cols;
    int h = image.rows;

    putText(image, format("width: %d, height: %d", w, h), 
        Point(50, 80), FONT_HERSHEY_SIMPLEX, 1, 
        Scalar(0,255,0), 1);
    
    imshow("image", image);
  
    waitKey(0);
    return 0;
}