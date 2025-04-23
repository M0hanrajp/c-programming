/* A c program to implement merge sort */
// C program for Merge Sort 
/* what: use recursion to split the array in to smallest size possible
 * when in smallest size merge the arrays in such a way that they are in the right order
 *
 * Why: each subarray is sorted, follows divide and conquer method
 */
#include <stdio.h> 
// Merges two subarrays of arr[]. 
// First subarray is arr[l..m] 
// Second subarray is arr[m+1..r] 

// Function to print an array 
void printArray(int A[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		printf("A[%2d] = %2d & address: %p\n", i, A[i], &A[i]); 
	printf("\n"); 
}

void merge(int arr[], int leftIndex, int midIndex, int rightIndex) 
{ 
	int i, j, k;
	int leftSize = midIndex - leftIndex + 1;
	int rightSize = rightIndex - midIndex;

	// Create temp arrays
	int leftArr[leftSize], rightArr[rightSize];

	// Copy data to temp arrays L[] and R[]
	for (i = 0; i < leftSize; i++)
		leftArr[i] = arr[leftIndex + i]; // from the left index start copying
	for (j = 0; j < rightSize; j++)
		rightArr[j] = arr[midIndex + 1 + j]; // from the middle copy the next element hence m + 1

	i = 0;
	j = 0;
	k = leftIndex; // because when adding elements from right, you need to add it from right index
	while (i < leftSize && j < rightSize) {
		if (leftArr[i] <= rightArr[j]) {
			arr[k++] = leftArr[i++];
		} else {
			arr[k++] = rightArr[j++];
		}
	}

	// Copy the remaining elements
	// of L[], if there are any
	while (i < leftSize) {
		arr[k++] = leftArr[i++];
	}
	// Copy the remaining elements of
	// R[], if there are any
	while (j < rightSize) {
		arr[k++] = rightArr[j++];
	}
}

// left index and right index of the sub-array of arr to be sorted 
void mergeSort(int arr[], int leftIndex, int rightIndex)
{ 
	if (leftIndex < rightIndex) {
		// Same as (l+r)/2, but avoids
		// overflow for large l and r
		int midIndex = leftIndex + (rightIndex - leftIndex) / 2;

		mergeSort(arr, leftIndex, midIndex);// sort left
		mergeSort(arr, midIndex + 1, rightIndex); // sort right

		merge(arr, leftIndex, midIndex, rightIndex); // merge arrays
	}
}

// Driver code 
int main() 
{ 
	int arr[] = {5, 4, 7, 6}; 
	int arr_size = sizeof(arr) / sizeof(arr[0]); 
	printf("Given array is \n"); 
	printArray(arr, arr_size); 
	mergeSort(arr, 0, arr_size - 1); // void mergeSort(int arr[], int leftIndex, int rightIndex) 
									 // is the reason why you need to pass arr_size - 1
	printf("\nSorted array is \n"); 
	printArray(arr, arr_size); 
	return 0; 
}

// output
/* For the desired output include print function to print array in mergeArray funciton

Given array is
A[ 0] =  5 & address: 0x7ffd30c4b430
A[ 1] =  4 & address: 0x7ffd30c4b434
A[ 2] =  7 & address: 0x7ffd30c4b438
A[ 3] =  6 & address: 0x7ffd30c4b43c

// 0 & 1 index element are sorted
A[ 0] =  4 & address: 0x7ffd30c4b430
A[ 1] =  5 & address: 0x7ffd30c4b434
A[ 2] =  7 & address: 0x7ffd30c4b438
A[ 3] =  6 & address: 0x7ffd30c4b43c
// 2 & 3 index element are sorted
A[ 0] =  4 & address: 0x7ffd30c4b430
A[ 1] =  5 & address: 0x7ffd30c4b434
A[ 2] =  6 & address: 0x7ffd30c4b438
A[ 3] =  7 & address: 0x7ffd30c4b43c

Sorted array is
A[ 0] =  4 & address: 0x7ffd30c4b430
A[ 1] =  5 & address: 0x7ffd30c4b434
A[ 2] =  6 & address: 0x7ffd30c4b438
A[ 3] =  7 & address: 0x7ffd30c4b43c
*/
