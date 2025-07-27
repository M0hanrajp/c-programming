#include <math.h>
#include <stdio.h>
#include <stdbool.h>

bool isPrime(int num) {
	if(num <= 1) {
		return false;
	}
	for(int i = 2; i <= sqrt(num); i++) {
		if(num % i == 0) {
			return false;
		}
	}
	return true;
}

int main(void) {
	// to print the prime numbers less than 20
	for(int i = 0; i < 21; i++) {
		isPrime(i) ? printf("%d is prime\n", i) : printf("%d is not prime\n", i);
	}
	return 0;
}
