// http://www.kocw.or.kr/home/search/kemView.do?kemId=1317915&ar=relateCourse
// Memory management
// MatIterator (이미지의 모든 픽셀값을 읽을 때 사용 -> 특정 픽셀 접근(X))

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat image = imread("lena.png");
    Mat gray = imread("lena.png", 0);

    int value, value_B, value_G, value_R;

    // try both image & gray
    int channels = image.channels();
    MatIterator_ <uchar> it, end;
    MatIterator_ <Vec3b> it3, end3;

    switch (channels)
    {
    case 1:
        for (it = image.begin<uchar>(), image.end<uchar>(); it != end; ++it) {
            value = *it;
            cout << "value: " << value << endl;
        }
        break;
    
    case 3:
        for (it3 = image.begin<Vec3b>(), end3 = image.end<Vec3b>(); it3 != end3; ++it3) {
            value_B = (*it3)[0];
            value_G = (*it3)[1];
            value_R = (*it3)[2];
            cout << "B: " << value_B << ", G: " << value_G << ", R: " << value_R << endl;
        }
        break;
    }
  
    waitKey(0);
    return 0;
}