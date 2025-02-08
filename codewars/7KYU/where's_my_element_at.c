/* An array is a data structure in which a collection of different data 
 * stored continuously in memory. This collection is usually accessed by 
 * a numerical index and allows near instant access to all of the data held 
 * by the array as opposed to other structures such as binary search trees or 
 * linked lists, where the computer has to traverse these structures to find 
 * the item being accessed.
To demonstrate, we'll calculate the position of an array element using some simple arithmetic.

Task Overview
Given:

begin, a number which represents the location of the beginning of the array in memory,
end, a number which represents the location of the end of the array in memory,
index, a zero-based numerical key for the element being accessed,
size, a number representing the size in bytes of each item of the array,
Return the memory address of the element being accessed.

In C, begin and end will be pointers, and you must return a pointer to array[index].
If the index is negative or the address of the memory being accessed is at or greater than 
the end of the array, throw an Error (JS) / IndexError (Python). In C return NULL instead.

Otherwise, who knows what data we could be accessing!

Usage Example
element_location(0x1000, 0x1040, 0x3, 0x8) => 0x1018
element_location(0x1000, 0x1040, 0x8, 0x8) => NULL
element_location(0x2000, 0x2100, 0x3, 0x4) => 0x200C
element_location(0x2000, 0x2100, 0x0, 0x4) => 0x2000
Constraints
All types given will be valid.
All numbers given are integers.
end will be greater than or equal to begin
begin, end, and size will be positive numbers.
size will be a power of 2.
begin is evenly divisible by 4.
The difference of begin and end is evenly divisible by size. */
#include <inttypes.h>
#include <stddef.h>
void *element_location (const void *begin, const void *end, intptr_t index, size_t size) {
  if(index < 0){return NULL;}
  void *element_address = (void *)begin;
  if(end >= begin)
    while(index > 0) { element_address += size; index--;}
	return element_address >= end ? NULL : element_address;
}
