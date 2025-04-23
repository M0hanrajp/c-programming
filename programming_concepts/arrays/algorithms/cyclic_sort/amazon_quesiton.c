// amazon question
/* Given an array nums containing n distinct numbers in range [0, n] return the 
 * number in the range that is missing from the array */
// example for n = 2 & array [0, 2] answer is 1

#include <stdio.h>

int missingNumber(int *nums, int size) {
    int i = 0;
    while (i < size) {
        if(nums[i] == size) {
            i++;
            continue;
        }
        if(nums[i] != i) {
            int temp = nums[nums[i]];
            nums[nums[i]] = nums[i];
            nums[i] = temp;
        } else {
            i++;
        }
    }
    // search the missing number
    for(int i = 0; i < size; i++) {
        if(i != nums[i])
            return i;
    }
    return size;
}

int main(void) {
    int nums[4] = {1, 0, 3, 2};
    printf("For the give array missing number is %d\n", missingNumber(nums, 4));
    return 0;
}
