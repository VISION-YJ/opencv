// http://www.kocw.or.kr/home/search/kemView.do?kemId=1317915&ar=relateCourse
// Spatial filtering (spatial masks, kernels, templates, windows)
// - 일반적인 적용 크기 (3x3, 5x5, 7x7)
// - Averaging filter (고주파 값을 없애는데 사용; 전반적으로 흐릿(blur)해 진다)
// - Gaussian filter 
// - Sharpening (밝기값의 차이를 더 크게만든다, 2차 미분 또는 Unsharp mask를 사용한다.)
// - Median filter (salt and pepper noise 를 없앨때 사용, 연산량이 많다)

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat input = imread ( "lena.jpg" );
    Mat gray, blur, sharp;

    cvtColor ( input, gray, COLOR_BGR2GRAY );
    GaussianBlur ( gray, blur, Size(5,5), 3 );
    imshow ( "gray", gray );

    // 원본 가중치 2.5, 블러 가중치 -1.5 => 2개를 더한다.
    addWeighted ( gray, 2.5, blur, -1.5, 0, sharp );
    imshow ( "sharp", sharp );   
  
    waitKey(0);
    return 0;
}