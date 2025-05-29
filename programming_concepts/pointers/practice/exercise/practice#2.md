### structs and pointers quiz by AI
```c
struct Point { int x, y; };
struct Point pts[5];
struct Point *p = pts;
/* How would you advance `p` to point to the third element in `pts`? */
/* Answer
	- pts[2] will be the third element.
	- p already points to the first element of struct array
	- p += (2 * sizeof(*p)); will advance the pointer to the third element
	
	// This was wrong
	- p is already of type struct Point.
	- Under the hood, p += 2 moves the pointer forward by 2 * sizeof(struct Point) bytes.
	
	// also note
	char *cp = p;  // error: incompatible pointer type (cannot assign directly without the cast)
	>> This is where I was getting at by overthinking
	char *cp = (char *)pts;                 // start at pts[0]
	cp += 2 * sizeof(struct Point);         // move forward 2×Point bytes
	struct Point *p2 = (struct Point *)cp;  // cast back to struct Point*
	// now p2 == &pts[2]

*/

struct Data { char name[20]; double value; };
struct Data d = { "foo", 3.14 };
char *c = d.name;
/* If you do `c += 5;`, what part of `d` are you pointing to? */
/* Answer
	- c is assigned the address of string "foo"
	- when c += 5 is done, c points to memory that is out of bound. // only this part is wrong (it's not out of bound)
	- this memory is not used in program.
	- will cause undefined behavior if accessed.
	
	// proper way to write was 
	After c += 5;, c points to the sixth character in the name array, i.e. d.name[5], which (in this initialization) is '\0'.
*/

struct S { int a; float b; char c; };
struct S s;
/* Without using `&s.b`, write an expression using `(char*)&s` and offsets to get a pointer to `b`. */
/* Answer
	- currently &s points to the starting element of the struct that is int.
	- In order to make it point to b using (char*) we can add sizeof the first element of struct
	  to make it point to the next element of the struct.
	- s = (char *)&s + sizeof(s.a);
	
	// mistakes
	- s is your struct; you can’t assign a char* to it. What you want is a pointer to b, not to overwrite s itself.
	// correct way
	- float *pb = (float *)((char *)&s + offsetof(struct S, b));
	- (char *)&s treats the start of s as a byte-address.
	- offsetof(struct S, b) gives you exactly how many bytes into s the member b lives.
	- Adding them gives you a char* to the location of b.
	- Casting back to float* lets you dereference it as the right type.
*/

struct Item { int id; };
struct Item arr[10];
struct Item *p1 = &arr[7];
struct Item *p2 = &arr[2];
/* What is the value of `p1 - p2`? */
/* Answer
	- p1 has address of 8th element, p2 has address of 3rd element.
	- p1 will contain LSB of the arr[7].id & p2 will contain LSB of the arr[2].id
	- Not sure about this question, I'm not sure if addresses can be subtracted.

	// answer
	- if you have two pointers into the same array (here arr), you can subtract them.
	- /* p1 - p2 == 7 - 2 == 5 */ ptrdiff_t diff = p1 - p2;  // diff == 5
	- Pointer arithmetic on struct Item * moves in units of sizeof(struct Item), 
	  but when you subtract two struct Item * pointers, the compiler divides out 
	  that size for you and gives you the difference in elements, not in bytes.
*/

struct M { int vals[4]; };
struct M m[3];
int *q = &m[1].vals[2];
/* If you increment `q` by 1, what element of which `struct` are you at? */
/* Answer
	- q holds the address of 2nd element of struct array m & 3rd element struct field/member array.
	- if we increment q by 1, it will hold &m[1].vals[3].
	// extra Pointer arithmetic on an int* advances by sizeof(int)
*/

struct T { short a; short b; };
struct T tarr[4];
void *v = tarr;
/* How would you get to `tarr[2].b` starting from `v` using pointer casts & arithmetic? */
/* Answer
	- *v contains the start address i.e. &tarr[0].
	- In order to move to tarr[2], (struct T *)v += 2
	- now v points to tarr[2]
	- v += sizeof(short) will make it move to tarr[2].be // this is not safe
	
	// short *pb = &(((struct T *)v + 2)->b);
	- In ISO C you cannot do v += ... when v is a void *—you must first cast it to a character or object pointer type.
	- Writing (struct T *)v += 2; doesn’t change v itself; it merely pretends to move a temporary struct T *. 
	  You need to bind that result to a pointer.
	
*/

struct Node { int data; struct Node *next; };
struct Node n;
/* Is `(int *)&n` always equivalent to `&n.data`? Why or why not? */
/* Answer
	- n is a struct instance of struct Node.
	- &n points to the start of struct memory.
	- (int *)&n --> casting (int *) to an address, address remains same.
	- &n.data --> accessing first struct member address remains same.
	- In terms of memory layout both point to the same location.
	- But they are not always equivalent because any pointer arithmetic on (int *)&n will move it by sizeof(int)
	- any pointer arithmetic &n.data will be irrelevant
	
	// corrections
	- &n.data is also an int *, so arithmetic on that actually is the same.
	- Accessing n.data through an int * (&n.data) is fine—data really is an int.
	- Accessing the entire struct via an int * (i.e. treating n itself as if it were an int) 
	  is formally undefined behavior if you dereference (int *)&n to read or write.
	- compiler may work, but it's undefined behavior
	
	int *p = &n.data;    // defined and type-correct
	int x = *p;          // reads n.data

	int *q = (int *)&n;  // legal cast, but dereferencing q for anything other than n.data is undefined
	int y = *q;          // may work, but technically UB under strict-aliasing
*/

struct P { char c; double d; int i; };
/* How does `offsetof(struct P, i)` relate to pointer arithmetic on a `struct P *`? */
/* Answer
	- offsetof(struct P, i) will give offset value of element int i in memory not address.
	- struct P *x here any pointer arithmetic will move the pointer by sizeof(*x)
	
	// extras
	- offsetof(struct P, i)  // e.g. might be 16 on a typical 64-bit ABI
	- This is the number of bytes from the beginning of any struct P object to its i member.

*/

struct X { char a; } xarr[3];
char *cp = (char *)&xarr[0];
/* What happens if you do `cp += sizeof(struct X) * 2 + 1;`—where do you land? */
/* Answer
	- cp has the address of start struct array xarr.
	- sizeof(struct X) = 1, with 1 byte alignment.
	- so expression becomes cp += 3, this will point to out of bound memory.
	- When accessed behavior is undefined.
	- xarr is array of only 3 element.
	
	// extras
	- Pointer arithmetic rule, Advancing a char * by 3 moves you exactly 3 bytes forward.
	- Pointing one element past the end of an array is permitted for pointer arithmetic 
	  (you can compute it), but dereferencing it is undefined behavior.
*/

struct R { int data; struct R *next; };
struct R *head, *cur;
/* Write a single expression using only `head`, pointer arithmetic, and dereferences that gets the `data` of the node two steps after `head`. */
/* Answer
	- head->next = &head;
	- head->next->next->data;
*/
```
