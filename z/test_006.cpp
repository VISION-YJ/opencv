#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat frame;
    VideoCapture cap(0);

    double fps = cap.get(CAP_PROP_FPS);
    cout << "W: " << cap.get(CAP_PROP_FRAME_WIDTH) << endl;

    

    while(1) {
        cap >> frame;
        if (frame.empty()) break;

        cout << "fps: " << fps;
        cout << " W: " << cap.get(CAP_PROP_FRAME_WIDTH);
        cout << " H: " << cap.get(CAP_PROP_FRAME_HEIGHT) << endl;
        imshow("Web cam", frame);
        waitKey(1000/fps);
    }

    waitKey(0);
    return 0;    
}