#include <stdio.h>
#include <stdbool.h>

double squareRootPrecision(double num) {
	int s = 0;
	int e = num;
	int m = s + (e - s) / 2;
	while (s <= e) {
		m = s + (e - s) / 2;
		if(m * m == num)
			return m;
		else if(m * m > num)
			e = m - 1;
		else 
			s = m + 1;
	}
	// with precision
	double root = 0.0;
	double p = 3, d = 0.1;
	for(int i = 0; i < p; i++) {
		while (root * root <= num) {
			root += d;
		}
		root -= d;
		d /= 10;
	}
	return root;
}

int main(void) {
	double num = 40;
	printf("Square root of %lf is %lf\n", num, squareRootPrecision(num));
	return 0;
}
