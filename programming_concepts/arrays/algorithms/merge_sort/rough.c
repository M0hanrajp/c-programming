/* Merge sort
 * What: Divide array into 2 parts
 * Get both parts sorted using recursion
 * merge the two sorted parts (not simple merge, during merge, compare and merge)
 */

#include <stdio.h>
#include <strings.h>
#include <stdbool.h>

// Function definition - to display array
void displayArray(int *arr, int array_size) {
    for(int i = 0; i < array_size; i++)
        printf("Array[%d] = %d & address: %p\n", i, arr[i], &arr[i]);
    printf("\n");
}

// Function definition - merge arrays
void mergeArrays(int *a, int l, int m, int r) {

	int as = m - l + 1, bs = r - m;
	int ai = 0, bi = 0, ci = 0;

	int la[as]; int ra[bs];
	for(int i = 0; i < as; i++) {
		la[i] = a[l + i];
	}
	for(int i = 0; i < bs; i++) {
		ra[i] = a[m + 1 + i];
	}

	// merge
	while (ai < as && bi < bs) {
		if(la[ai] < ra[bi]) {
			a[ci++] = la[ai++];
		} else {
			a[ci++] = ra[bi++];
		}
	}
	
	while (ai < as) {
		a[ci++] = la[ai++];
	}
	while (bi < bs) {
		a[ci++] = ra[bi++];
	}
	displayArray(a, 2);
}

void mergeSort(int *a, int l, int r) {
	if(l < r) {
		int m = l + (r - l) / 2;
		mergeSort(a, l, m); // left 
		mergeSort(a, m + 1, r); // right
		mergeArrays(a, l, m, r); // merge
	}
}

int main(void) {

	int arr[7] = {4, 5, 5, 2, 1, 6, 7};
	mergeSort(arr, 0, 6);
	displayArray(arr, 6);
	return 0;
}
