/* Unfinished Loop - Bug Fixing #1
Oh no, Timmy's created an infinite loop! Help Timmy find and fix the bug in his unfinished for loop! */
/* #include <stddef.h>
void create_array(size_t length, unsigned array[length]) {
    for(size_t counter = 1; counter <= length;) {
        array[counter - 1] = counter;
    }
} */
// solution
#include <stddef.h>
void create_array(size_t length, unsigned array[length]) {
    for(size_t counter = 1; counter <= length;counter++) {
        array[counter - 1] = counter;
    }
}
