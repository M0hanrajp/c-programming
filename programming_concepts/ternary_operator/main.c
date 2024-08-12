/* A c program that demonstrates ternary opeartor
 * 10 March
 */
#include <stdio.h>

int main(void)
{
	int exp_one = 0, exp_twp = 0, exp_ans = 0;
	exp_ans = exp_one != exp_twp ? exp_one + 1 : exp_one == exp_twp ? exp_twp+ 2 : exp_one + 3;
	printf("exp ans = %d\n", exp_ans);
	return 0;
}
