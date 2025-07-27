#include <stdio.h>

int main(void) {
	int num = 34;
	// has the complexity O[n]
	for(int i = 1; i < num + 1; i++) {
		if(num % i == 0)
			printf("%d ", i);
	}
	printf("are the factors of %d\n", num);
	return 0;
}
