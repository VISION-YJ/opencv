#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat frame;
    VideoCapture cap;

    // check if file exists.
    // If none program end 
    if (cap.open("../samples/cpp/tutorial_code/calib3d/real_time_pose_estimation/Data/box.mp4") == 0)
    {
        cout << "no such file!" << endl;
        waitKey(0);
    }

    while (1) {
        cap >> frame;
        if (frame.empty()) {
            cout << "end of video" << endl;
            break;
        }
        imshow("vdeo", frame);
        waitKey(33);
    }
}