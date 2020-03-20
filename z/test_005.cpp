#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat frame;

    // Capture from Webcam whose device number = 0
    VideoCapture cap(0);

    while(1) {
        cap >> frame;
        imshow("Web cam", frame);
        waitKey(16);
    }
}