#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
{
    int w = 150, h = 100;
    Mat image(h, w, CV_8UC3, Scalar(255, 100, 100));

    cout << "Size: " << image.size().height << ", " << image.size().width << endl;
    imshow("image", image);

    waitKey(0);
    return 0;
}
