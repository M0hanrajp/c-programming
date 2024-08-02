/* NOTE: 
 * The following program copies the content of an array into another array in reverse order 
 */
#include <stdio.h>
#define SIZE 5 
// Function prototype
void CopyAndReverseArray(int *SourceArray, int *DestinationArray, int ArraySize);
int main(void)
{
    int SourceArray[SIZE] = {1, 2, 3, 4, 5}, DestinationArray[SIZE] = {};
    // Printing out default values & address of source and destination array in main function
    printf("Source & Destination array elements & address before funciton call:\n");
    for(int elements = 0; elements < SIZE; elements++)
    {
        printf("Source[%d] = %d & Address: %u :: Destination[%d] = %d & Address: %u\n",
                elements, SourceArray[elements], &SourceArray[elements],
                elements, DestinationArray[elements], &DestinationArray[elements]);
    }
    // Calling function to copy source into destination and reverse the array
    CopyAndReverseArray(SourceArray, DestinationArray, SIZE);
    return 0;
}
// Function definiton
void CopyAndReverseArray(int *SourceArray, int *DestinationArray, int ArraySize)
{
    printf("Source & Destination array elements & address after funciton call:\n");
    for(int elements = 0; elements < ArraySize; elements++, DestinationArray++)
    {
        *DestinationArray = *(SourceArray + (ArraySize - 1 - elements));
        printf("Source[%d] = %d & Address: %u :: Destination[%d] = %d & Address: %u\n",
                elements, *(SourceArray + elements), SourceArray + elements, 
                elements, *DestinationArray, DestinationArray);
    }
}
