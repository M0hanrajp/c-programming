#include <stdbool.h>
#include <stdio.h>

int squareRoot(int num) {
	/* use binary search from initial value to num 
	 * check if the middle element square is equal to num
	 * if yes, return the middle
	 * if not, check if the middle squared was greater or smaller than num
	 * if smaller then update new middle
	 * then check again
	 * */
	if(num < 4) {
		return num;
	}
	int start = 0, end = num;
	while (true) {
		int m = (start + end) / 2;
		if(m * m == num) {
			return m;
		} else if(m * m > num) {
			end = m - 1;
		} else {
			start = m + 1;
		}
	}
	return -1;
}


int main(void) {
	/* program only for perfect square */
	int num = 256;
	printf("square root of %d = %d\n", num, squareRoot(num));
	return 0;
}
