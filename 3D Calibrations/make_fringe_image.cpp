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

/*
******************** Description ********************
This function is similar to makeFringeImage function.
However, this function performs gamma correction.
step 1 : making the fringe image.
step 2 : Find the fringe image's max value.
step 3 : Scaling the fringe image's value to 0 ~ 1 and Do gamma correction.
step 4 : Re-scaling these values to 0 ~ 255.

******************** Input ********************
width : Result image's width.
height : Result image's height.
n : Fringe pattern's shift index (0~N-1).
N : Fringe pattern's shift number.
T : Fringe pattern's period.
gamma : The value for gamma correction.
isHorizon : Fringe pattern's direction.

******************** Output ********************
Fringe pattern image

******************** Reference ********************
Some practical considerations in fringe projection profilometry, Zhaoyang Wang, Dung A, Nguyen, John C. Barnes, 2010
*/

IplImage* makeFringeImage_gamma(const int width, const int height, const int n, const int N, const int T, const float gamma, const bool isHorizon) {

	IplImage* src = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
	float* temp = new float[width * height];
	float max = 0.;
	unsigned char Im = 255;
	unsigned char value;

	/* make fringe image */
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

	/* calc max value */
	if (isHorizon) {
		for (int i = 0; i < src->height; i++)
			if (max < (unsigned char)src->imageData[i * src->widthStep])
				max = (unsigned char)src->imageData[i * src->widthStep];
	}
	else {
		for (int i = 0; i < src->width; i++)
			if (max < (unsigned char)src->imageData[i])
				max = (unsigned char)src->imageData[i];
	}

	/* scale 0~1 and calc gamma power */
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int index = i * src->widthStep + j;

			temp[i * width + j] = (float)((unsigned char)src->imageData[index] / max);

			temp[i * width + j] = (std::pow(temp[i * width + j], gamma));
		}
	}

	/* calc 0~1 scale's max value */
	max = 0.;

	if (isHorizon) {
		for (int i = 0; i < src->height; i++)
			if (max < temp[i * width])
				max = temp[i * width];
	}
	else {
		for (int i = 0; i < src->width; i++)
			if (max < temp[i])
				max = temp[i];
	}

	/* scale 0~255 */
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			int index = i * src->widthStep + j;

			src->imageData[index] = (unsigned char)(temp[i * width + j] * 255. / max);
		}
	}

	delete[] temp;
	return src;
}