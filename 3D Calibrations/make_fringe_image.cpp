#include <cv.h>
#include <highgui.h>

/*
	******************** Description ********************
	This function makes the fringe pattern image.
	If you want to make a 4-shift fringe pattern image, you have to call this function through for-loop(4).
	Result image is an IplImage provided at OpenCV.

	******************** Input ********************
	width : Result image's width.
	height : Result image's height.
	n : Fringe pattern's shift index (0~N-1).
	N : Fringe pattern's shift number.
	T : Fringe pattern's period.
	isHorizon : Fringe pattern's direction.

	******************** Output ********************
	Fringe pattern image


*/
IplImage* makeFringeImage(const int width, const int height, const int n, const int N, const int T, const bool isHorizon) {

	IplImage* src = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
	unsigned char Im = 255;
	unsigned char value;

	if (isHorizon) {
		for (int i = 0; i < src->height; i++) {
			value = (Im / 2)*(1 + sin(2 * M_PI * i / T + (2 * M_PI * n / N)));

			for (int j = 0; j < src->width; j++) {
				src->imageData[i * src->widthStep + j] = value;
			}
		}
	}
	else {
		for (int i = 0; i < src->width; i++) {
			value = (Im / 2)*(1 + sin(2 * M_PI * i / T + (2 * M_PI * n / N)));

			for (int j = 0; j < src->height; j++) {
				src->imageData[i + src->widthStep * j] = value;
			}
		}
	}

	return src;
}
