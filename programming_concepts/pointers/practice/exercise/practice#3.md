### Practice 3
```c
struct Point { 
    int x, y; 
};
struct Point pts[5];
struct Point *p = pts + 2;

// What member does p->y refer to, and how would you set it to 10?

/* *p = pts + 2;
	- p will point to pts[2] (3rd element)
	- p-> refers to 2nd struct memeber y, of pts[2].
	- since already p points to pts[2], p->y = 10 will set it to 10
*/

struct Item { 
    double price; 
    int qty; 
} items[3] = { {2.5, 1}, {3.0, 2}, {4.0, 3} };
struct Item *ip = items;
// After executing ip += 2;, what are the values of ip->price and ip->qty?

/* ip->price value is 4.0
   ip->qty value is 3
   ip will point to items[2] after ip += 2.
*/

struct Node {
    char label;
    int value;
};
struct Node arr[4];
// If you want to treat the entire arr as a raw byte buffer and advance a char * pointer to the value field of arr[2], what expression would you use?

/*
	- char *buff = (char *)arr; buff now points to the starting address at arr[0].
	- buff += (2 * sizeof(struct Node)); buff is a raw byte buffer now pointing at arr[2].
		- this can also be written as buff += (2 * sizeof(*arr)), arr is of type struct Node *, dereferencing it will gives us struct Node type.
	- struct Node *res = (struct Node *)buff; casting it back to struct Node * type from char *.
	
	// what I missed
	-  + offsetof(struct Node, value);        // skip past the label field
	- the question was to point the pointer to value field not arr[2].
*/

struct Rec {
    int a;
    double b;
    char c[4];
} records[10];

struct Rec *r = records + 5;
// What’s the difference in bytes between (char*)(records + 5) and (char*)records? How does that relate to sizeof(struct Rec)?

/* - (char*)records will be the starting pointer to records[0]
   - (char *)(records + 5), here records points to records[5] but is cast to (char *) type.
   - The difference between them will be 5, as difference between these address gives out the number of elements between them.
   - sizeof(struct Rec) will give you the size of one full struct object, whereas (char *)(records) any pointer arithmetic here moves by 1 byte.
   
   // actual answer.
   - (char*)(records + 5) - (char*)records == 5 * sizeof(struct Rec);
	- always remember when you subtract two pointers of the same type, you get the difference in elements (based on their size), not bytes. So:

*/

struct Data { 
    int id; 
    float nums[3]; 
};
struct Data d = { 42, {1.1f, 2.2f, 3.3f} };
float *fp = d.nums;
// What does *(fp + 2) evaluate to, and why?

/* 	- fp is of type float * & it points to d.nums[0] in the beginging.
	- *(fp + 2) will point to d.nums[2] the thrid element.
*/

struct T { 
    long x; 
    short y; 
} t_array[2];
struct T *tptr = t_array;
// If you cast tptr to (char*) and add sizeof(long), then cast back to (short*), what member are you pointing to?

/* 	- adding by sizeof(long) moves the pointer by sizeof(long) bytes ahead.
	- when we cast back to short * we are pointing to t_array[0].y 
*/

struct S {
    int arr[4];
} s = { {10, 20, 30, 40} };
int *ip = s.arr + 1;
// What happens if you do ip += 3;? Is that defined behavior? What element (if any) does it point to?

/*
	- when *ip = s.arr + 1 is done, ip points to s.arr[1] at the 2nd element.
	- when ip += 3 is done, moves by sizeof(int) it points to s.arr[4]. (out of bounds)
	- accessing element at this memory is undefined behavior
*/

struct A { int v; };
struct B { int u; };
struct A a[3];
struct B b[3];
// Why is pointer arithmetic allowed on a and also on b, but why can’t you do (struct B*)a + 1 to access b[1] safely?

/*
	- pointer arithmetic is allowed on a & b because they are not declared with const keyword qualifier.
	- pointer is not constant here, and neither is the struct object hence pointer arithmetic is allowed.
	- a is of type struct A *, doing (struct B*)a + 1 will move to the next address.
	- the compiler lays out a & b in memory with available locations, there is no gurranty that doing 
	  (struct B*)a + 1 will get us to b[1], becuase both structs are different and both structs are not laid out in contigious memory.
	  
	  // more points
	  - Pointer arithmetic is valid on any array pointer (a or b) because it walks through consecutive elements of the same type.
	  - Casting a (a struct A *) to struct B * and doing arithmetic assumes the memory layout for A matches B and that b happens 
		  to follow a contiguously—but there’s no guarantee of either.
	  - Thus (struct B*)a + 1 does not reliably land at b[1].
*/

struct Mixed {
    char c1;
    int i;
    char c2;
} m_array[2];
struct Mixed *mp = m_array;
// Explain how padding might affect (mp + 1) versus simply adding sizeof(int) + 2 * sizeof(char) to a char* derived pointer.

/* 
	- mp + 1 will move to the next instance m_array[1] as it will move by sizeof(struct Mixed).
	- consider char c1, is at 0x0, then int i needs to be 4 byte aligned, 0x1-0x3 will be padded.
	- int i takes up 0x4 - 0x7, char c2 takes 0x8 since largest element is int, the whole structs needs to be
	  4 byte aligned for the next struct instance hence, 0x9 - 0x11 will be padded so in total the sizeof struct is 12 bytes.
	- simply adding sizeof(int) + 2 * sizeof(char) is total 6 bytes and adding this to a char * derived does not make any sense
*/

struct Leaf {
    float f;
};
struct Branch {
    struct Leaf leaves[2];
} tree[2];
struct Leaf *lp = &tree[0].leaves[0];
// What pointer arithmetic expression gets you to tree[1].leaves[1] starting from lp?

/*
	- the sizeof(struct Leaf) is 4 bytes.
	- That’s key: even though tree is a struct Branch[2], 
	- when you take the address of a single struct Leaf and use a Leaf * pointer, 
	- you’re navigating the memory as if all the leaves were laid out linearly, which they are in this case.
		tree[0].leaves[0]
		tree[0].leaves[1]
		tree[1].leaves[0]
		tree[1].leaves[1]

	- by doing lp += 1 will move it to &tree[0].leaves[1] this is of type struct Leaf *.
	- by doing lp += 2 it will move to &tree[1].leaves[1]
*/
```
