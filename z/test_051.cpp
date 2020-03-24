// http://www.kocw.or.kr/home/search/kemView.do?kemId=1317915&ar=relateCourse
// Histogram Equalization (도수분포도 평활화) 
//  - 픽셀들을 전범위에 걸처 골고루 위치하도록 배치하는 작업 (구분을 쉽게 하기 위함)
// Histogram Normalization (도수분포도 정규화)

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

Mat drawHistogram(Mat src) {
    Mat hist, histImage;

    // establish the number of bins
    int i, hist_w, hist_h, bin_w, histSize;
    float range[] = { 0, 256 };
    const float* histRange = { range };

    hist_w = 512;
    hist_h = 400;
    histSize = 256;
    bin_w = cvRound((double) hist_w / histSize);

    // compute the histogram
    // &src: input image, 1: #of src image, 0: #of channels numberated from 0 ~ channels()-1, Mat(): optional mask
    // hist: output histogram, 1: histogram dimension, &hisSize: array of histogram size, &histRange: array of histogram's boundaries 
    calcHist(&src, 1, 0, Mat(), hist, 1, &histSize, &histRange);

    // draw the histogram
    histImage = Mat(hist_h, hist_w, CV_8UC3, Scalar(255, 255, 255));

    // normalize the result to [0, histImage.rows]
    // hist: input Mat, hist: output Mat, 0: lower range negative, the output array has the same type as src, Mat(): optional mask 
    normalize(hist, hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

    for (i = 1; i < histSize; i++) {
        rectangle(histImage, Point(bin_w*i, hist_h), 
        Point(bin_w*i, hist_h - cvRound(hist.at<float>(i))),
        Scalar(0,0,0), 2, 8, 0);
    }

    return histImage;
}

int main()
{
    Mat image;
    Mat hist_equalized_image;
    Mat hist_graph;
    Mat hist_equalized_graph;

    image = imread("lena.png", 0);
    if (!image.data) exit(0); // check image.

    equalizeHist(image, hist_equalized_image); // histogram equalization

    hist_graph = drawHistogram(image);
    hist_equalized_graph = drawHistogram(hist_equalized_image);

    imshow("Input Image", image);
    imshow("Hist Equalized Image", hist_equalized_image);
    imshow("Hist Graph", hist_graph);
    imshow("Hist Equalized Graph", hist_equalized_graph);
  
    waitKey(0);
    return 0;
}