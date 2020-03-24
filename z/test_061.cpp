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
    Mat image, AvgImg, GaussianImg;
    image = imread("lena.png");
    imshow ("Input image", image);

    // Blurs an image using the normalized box filter
    blur (image, AvgImg, Size(5,5));
    imshow ("Average image", AvgImg);

    // Blurs an image using a Gaussian filter
    GaussianBlur (image, GaussianImg, Size(5,5), 1.5, 1.5);
    imshow ("Gaussian blurred image", GaussianImg); 
  
    waitKey(0);
    return 0;
}