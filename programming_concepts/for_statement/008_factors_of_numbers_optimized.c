#include <stdio.h>

int main(void) {
	// for optimization run the loop only till sqrt(n) in order to avoid repeated checks
	// as 2 * 10 == 10 * 2 for factor of 20
	int num = 36;
	for(int i = 1; i * i <= num; i++) {
		if(num % i == 0) {
			if(num / i == i) {
				printf("%d ", i);
			} else {
				printf("%d %d ", i, num / i);
			}
		}
	}
	printf("are the factors of %d\n", num);
	// In order to get the sorted output put num / i (it will be in decesending)
	// print it out from last index to print in ascending order
	return 0;
}
