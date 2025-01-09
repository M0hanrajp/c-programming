/* false xor false == false // since both are false
true xor false == true // exactly one of the two expressions are true
false xor true == true // exactly one of the two expressions are true
true xor true == false // Both are true.  "xor" only returns true if EXACTLY one of the two expressions evaluate to true.
Task
Since we cannot define keywords in Javascript (well, at least I don't know how to do it), 
your task is to define a function xor(a, b) where a and b are the two expressions to be 
evaluated. Your xor function should have the behaviour described above, returning true if 
exactly one of the two expressions evaluate to true, false otherwise. */
#include <stdbool.h>
bool xor(bool a, bool b) {
    return a ^ b;
}
