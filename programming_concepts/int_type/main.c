#include <stdio.h>

int main(void)
{
	short short_a = 5;
	unsigned unsigned_a = 2;
	int normal_a = 1;
	long long_a = 4;
	
	printf("short a = %hd, divide by 2 = %d, size of short = %lu\n", short_a, short_a/2, sizeof(short_a));
	printf("unsigned a = %hd, divide by 2.0 = %lf, size of unsigned = %lu\n", unsigned_a, unsigned_a/2.0, sizeof(unsigned_a));
	printf("long a = %ld, sizeof of long = %lu\n", long_a, sizeof(long_a));
	//printf("character of long_a = %c\n", long_a);
	return 0;
}

