/* Write a function that returns both the minimum and maximum number of the given list/array.

Examples (Input --> Output)
[1,2,3,4,5] --> [1,5]
[2334454,5] --> [5,2334454]
[1]         --> [1,1] */
void min_max (const int arr[/* count */], int count, int *min, int *max) {
  *max = arr[0];
  *min = arr[0];
  for(int i = 1; i < count; i++) {
   if(*max < arr[i])
     *max = arr[i];
   if(*min > arr[i])
     *min = arr[i];
  }
}
