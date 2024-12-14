/* Don't give me five!
In this kata you get the start number and the end number of a 
region and should return the count of all numbers except numbers 
with a 5 in it. The start and the end number are both inclusive!

Examples:
1,9 -> 1,2,3,4,6,7,8,9 -> Result 8
4,17 -> 4,6,7,8,9,10,11,12,13,14,16,17 -> Result 12 */
int dontGiveMeFive(int start, int end) {
  unsigned count = 0;
    for (int i = start; i <= end; i++) {
        int temp = i;
        int hasFive = 0;
        while (temp != 0) {
            if (temp % 10 == 5 || temp % 10 == - 5) {
                hasFive = 1;
                break;
            }
            temp /= 10;
        }
        if (hasFive) continue;
        count++;
    }
    return count;
}
