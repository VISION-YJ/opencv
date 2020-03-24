// http://www.kocw.or.kr/home/search/kemView.do?kemId=1317915&ar=relateCourse
// Color Processing
// - HSI, Pseudo Coloring, Color Balancing

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    Mat gray = imread ( "xray.jpg", 0 );
    Mat color;

    // Applies a colormap on a given image
    // gray: src, color: dst, COLORMAP_JET: the color map to apply
    applyColorMap ( gray, color, COLORMAP_JET );

    imshow ( "gray", gray );
    imshow ( "image", color );
    
    waitKey(0);
    return 0;
}