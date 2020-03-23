// http://www.kocw.or.kr/home/search/kemView.do?kemId=1317915&ar=relateCourse
// Mat Operator
// convertTo(), setTo(), convertScaleAbs()

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat image = imread("hand.png");
    imshow("hand", image);
    
    cvtColor(image, image, CV_BGR2YCrCb);
    inRange(
        image,                  // 입력영상
        Scalar(0, 133, 77),     // Low boundary
        Scalar(255, 173, 127),  // Upper boundary
        image
    );
        
    imshow("inRange", image);
    
    waitKey(0);
    return 0;
}