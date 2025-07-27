#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void sieveOfEratosthenes(int n, bool *primes) {
	/* Start from 2,
	 * All the elements of primes array are false, false means prime
	 * 2 is prime, make multiples of 2 as not prime (assign true)
	 * 3 is prime, make multiples of 3 as not prime
	 * This way we cancel out all numbers that are not required to be
	 * checked again and again
	 */
	for(int i = 2; i * i <= n; i++) {
		// some number is prime
		if(!primes[i]) {
			// make it's factors till the max range as not prime
			for(int j = i * 2; j <= n; j += i) {
				primes[j] = true;
			}
		}
	}

	// print the array to get primes.
	for(int i = 2; i <= n; i++) {
		if(!primes[i]) {
			printf("%d ", i);
		}
	}
	printf("\n");
}

int main(void) {
	// Max range to print the prime numbers.
	int num = 40;

	// the whole bool array will have false as initial values
	bool *p = calloc(num + 1, sizeof(bool));
	sieveOfEratosthenes(num, p);
	return 0;
}
