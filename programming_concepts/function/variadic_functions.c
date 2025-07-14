/* Variadic funtions in C
 * https://en.cppreference.com/w/c/variadic.html
 * Variadic functions are functions (e.g. printf) which take a variable number of arguments.
 */
#include <stdarg.h>
#include <stdio.h>
#define MAX_UE 5

double calculateAverageThroughput(int ueCount, ...) {
	int sum = 0;
	// holds the information needed by va_start, va_arg, va_end, and va_copy (typedef)
	// va_start does not scan memory for a terminator. It simply anchors your va_list at the correct start address.
	// You must still tell the function how many args there are—or supply a sentinel— 
	// otherwise you will read off into unrelated stack/register data and invoke undefined behavior.
	// The precise implementation of va_list/va_start is platform/ABI-specific, but the conceptual job is always 
	// “point me right after the last named parameter.”
	va_list ue;
	//va_start does: hand the compiler the location of your first anonymous argument so that va_arg can walk through them correctly.
	va_start(ue, ueCount);

	for(int i = 0; i < ueCount; i++) {
		sum += va_arg(ue, int);
		/* Reads a value of the requested TYPE out of the current position in the var‑args stream.
		 * Advances the internal pointer (or register/stack index) by exactly the amount of space 
		 * that TYPE occupies (including any ABI‑mandated padding or alignment).
		 */
	}
	va_end(ue);
	/* Release any temporary memory or buffers it allocated for spilling argument registers.
	 * Invalidate the va_list so that further use is undefined.
	 * If you forget va_end, you invoke undefined behavior.
	 * You should never call va_end more than once on the same va_list, nor use ap after va_end without re‑initializing via va_start.
	 */
	return sum / (double)ueCount;
}


int main(void) {
	printf("Average throughput :: %lf\n", calculateAverageThroughput(MAX_UE, 334));
	return 0;
}
