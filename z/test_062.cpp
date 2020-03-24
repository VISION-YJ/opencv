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
    Mat image, laplacian, abs_laplacian, sharpening;
    image = imread("moon.jpg", 0);

    GaussianBlur ( image, image, Size(3,3), 0, 0, BORDER_DEFAULT );

    // calculates the Laplacian of an image
    // image: src, laplacian: dst, CV_16S: desire depth of dst,
    // 1: aperture size used to compute second-derivative (optional)
    // 1: optional scale factor for the computed Laplacian values
    // 0: optional delta value that is added to the result
    Laplacian ( image, laplacian, CV_16S, 1, 1, 0); // 2차 미분
    convertScaleAbs ( laplacian, abs_laplacian );
    sharpening = abs_laplacian + image;

    imshow ( "Input image", image );
    imshow ( "Laplacian", laplacian );
    imshow ( "abs_Laplacian", abs_laplacian );
    imshow ( "Sharpening", sharpening );
  
    waitKey(0);
    return 0;
}