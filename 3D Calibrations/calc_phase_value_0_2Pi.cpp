#define _USE_MATH_DEFINES
#include <math.h>

/*
******************** Description ********************
This function calculates phase values using N-steps pixels.
If you want to calculate about whole size(width * height), you have to call this function through for-loop(width * height).
If you project 4-step fringe pattern images and grab 4 images, parameter 'I' must have 4 values(each image's pixel brightness).

******************** Input ********************
I : N-size array about pixel brightness datas.
N : Fringe pattern's shift number.
result : Phase value.

******************** Output ********************
Certain pixel's phase value.
*/

void calc_phase_value_0_2Pi(unsigned char* I, const int& N, float& result) {

	if (N == 3) {
		result = atan2(sqrt(3.0)*(I[0] - I[2]), (2 * I[1] - I[0] - I[2]));

		result += M_PI;	// -Pi ~ Pi -> 0 ~ 2Pi
	}
	else if (N == 4) {
		result = atan2((float)(I[3] - I[1]), (float)(I[0] - I[2]));

		result += M_PI;	// -Pi ~ Pi -> 0 ~ 2Pi
	}
	else {
		float numerator = 0.;		
		float denominator = 0.;		

		for (int i = 0; i < N; i++) {
			numerator += -((float)I[i] * (float)sin(2. * M_PI * (float)i / (float)N));
			denominator += ((float)I[i] * (float)cos(2. * M_PI * (float)i / (float)N));
		}
		if (denominator == 0.0) denominator = 1E-20;

		result = atan2(numerator, denominator);

		result += M_PI;	// -Pi ~ Pi -> 0 ~ 2Pi
	}
}