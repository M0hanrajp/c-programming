// https://en.wikipedia.org/wiki/Newton%27s_method
#include <stdio.h>
#include <math.h>

double newtonRaphson(double num) {
	double root = 0;
	double x = num;
	while (1) {
		// x is your assumed root
		root = 0.5 * (x + (num/x));
		
		// 0.5 is the error control, bring it down to increase accuracy
		if(fabs(root - x) < 0.5)
			break;

		x = root;
	}
	return root;
}

int main(void) {
	double num = 40;
	printf("square root of %lf = %lf\n", num, newtonRaphson(num));
	return 0;
}
