```bash
struct Point { int x, y; };

struct Point pts[3] = { {1, 2}, {3, 4}, {5, 6} };
struct Point *p = pts;

/*
a. What is the value of p->x?
	>> p->x the value is 1
b. After executing p++;, what are p->x and p->y?
	>> after p++, p moves 1 step ahead by the sizeof(struct Point)
	- p->x is 3, p->y is 4
c. What is the difference (in bytes) between (char*)(p + 2) and (char*)p?
	>> the difference will be 2 * sizeof(struct Point)
*/

struct Employee {
    int id;
    double salary;
    char grade;
};

struct Employee arr[5];

/*

Suppose struct Employee *pe = arr + 3;.
What C-expression would you write to set the salary of that 4th element to 75000.0 using only pe and pointer arithmetic (no indexing)?

	char *s = (char*)pe + offsetof(struct Employee, salary);
	double *pr = (double *)s;
	*pr = 75000.0;
	
	// or in one liner
	*(double *)((char *)pe + offsetof(struct Employee, salary)) = 75000.0;

*/

struct Matrix {
    int rows;
    int cols;
    float data[2][2];
};

struct Matrix M = { 2, 2, { {1.1f, 2.2f}, {3.3f, 4.4f} } };
struct Matrix *mp = &M;

/*
Write an expression using mp (with pointer arithmetic) that accesses the element in the second row, first column (data[1][0]).
		char *m = (char *)mp + offsetof(struct Matrix, data); // here I get the pointer to point to data[0][0].
		float *p = (float *)m + 2;
		now p points to data[1][0]; *p will be able to access data 3.3f.
		
		// if you want to write in one liner
		*((float *)((char *)mp + offsetof(struct Matrix, data)) + 2)

*/

struct Node {
    char label;
    int value;
};

struct Node n = {'A', 100};
void *vptr = &n;

/*

If you want to modify n.value by accessing it through vptr, what sequence of casts and pointer dereferences would you use? 
(E.g., cast to some pointer type, then dereference, then assign.)

	(char *)vptr += offsetof(struct Node, value);
	int v = 101;
	(int *)vptr = &v; // value is modified with different value, dereferencing vptr will now give 101 not 100
	
	// or in one line
	*(int *)((char *)vptr + offsetof(struct Node, value)) = 101
	
	// proper way of doing 
	
	/* 1) Compute a byte‐pointer to n.value, without modifying the original vptr */
	char *byte_ptr = (char *)vptr + offsetof(struct Node, value);

	/* 2) Cast that byte‐pointer to an int*, so you can write to it */
	int *int_ptr = (int *)byte_ptr;

	/* 3) Finally, store the new integer into n.value */
	*int_ptr = 101;
*/

#include <stddef.h>
struct Sample {
    char a;       // offset 0
    double b;     // offset 8 (assuming typical alignment)
    short c;      // offset 16
};

/* Use pointer arithmetic (e.g., (char*)&s + offset) to obtain the address of member c in an instance struct Sample s;. 
What arithmetic expression reproduces offsetof(struct Sample, c)? How many bytes is that, assuming usual 64-bit alignment?

	>> struct Sample s = {'A', 1.0', 1};
	In order to access the member c, using offsetof, 
	char *p = (char *)&s + offsetof(struct Sample, c); >> this obtains the address of member c;
	
	In a similar way
	char *p = (char *)&s + sizeof(char) + sizeof(double) >> also gives access to struct member c;
	
	// forgot to calculate using padding
	/* (char *)&s  is at offset 0,
   + sizeof(char)  brings you to offset 1,
   + padding of 7 bytes = offset 8,
   + sizeof(double) = 8 more bytes, landing you at offset 16 */

char *p = (char *)&s    /* start at address of s */
            + sizeof(char)       /* 1 byte for ‘a’        => offset 1  */
            + (7 /*padding to align `b` on 8-byte */) 
            + sizeof(double)    /* 8 bytes for ‘b’       => offset 16 */
; p now points to s.c 

*/
struct Record {
    long id;
    char flag;
    float score;
};

void process(struct Record *r);

int main() {
    struct Record recs[10];
    // ... initialize recs ...
    struct Record *rp = recs;
    // QUESTION: call process() on each element using only rp and pointer arithmetic
}

/*
Write the loop (in C) that calls process() on each of the 10 Record elements by incrementing rp, without using an index variable.

	for(int i = 0; i < 10; i++) {
		process(rp + i);
	}
	
	// without indexing 
	struct Record *end = recs + 10;
	for ( ; rp < end; rp++ ) {
		process(rp);
	}
*/

struct Data {
    short v1;
    short v2;
};

struct Data d[4] = { {1,2}, {3,4}, {5,6}, {7,8} };

/* Without using the array index d[i].v2, write an expression involving a pointer struct Data *pd = d; and pointer arithmetic 
  that retrieves the value 6 from the third element’s v2.
  
  struct Data *pd = d; // pd points to d[0].v1
  
  pd += 2; // pd now points to d[2].v1
  
  short *value = (short *)pd + 1; // value now points to d[2].v2;
  printf("v2 = %hd\n", *value);
*/

struct Info {
    int code;
    float weight;
    int ids[3];
};

struct Info items[3] = {
    { 10, 1.5f, {100, 200, 300} },
    { 20, 2.5f, {110, 210, 310} },
    { 30, 3.5f, {120, 220, 320} }
};

/* Given int *pid = &items[1].ids[2];, what is the effect of (struct Info*)pid - 1? Specifically, 
   to which structure does that pointer arithmetic expression point? And why?
   
   (struct info *)pid - 1, will move the address back 1 step by sizeof(struct info)
   it will point to &items[0].ids[2].
*/

struct A { int a; char c; };
struct A arrA[5];
struct A *p1 = &arrA[1];
struct A *p2 = &arrA[4];

/* a. Is (p2 - p1) well-defined? If so, what value does it yield?
	yes, it yeilds the difference of elements between them i.e. 3

b. If you cast them to (char*) like char *cp1 = (char*)p1; char *cp2 = (char*)p2;, what is (cp2 - cp1)? 
   Explain how this relates to the size of struct A.
   
   cp2 - cp1 = 3 * sizeof(struct A);
*/

struct Container {
    int count;
    struct Item {
        float weight;
        char type;
    } items[4];
};

struct Container boxes[2];

/* If you have struct Container *cb = boxes;, write a single expression (no loops) to get a pointer to the 
   type of the third Item in the second Container (i.e., boxes[1].items[2].type). 
   
   Then show how you’d modify that char to 'X' using only that pointer.
   
   Given, struct Container *cb = boxes
   
   1. cb += 1, cb now points to boxes[1].
   2. char *ptr = (char *)cb + offsetof(struct Container, items), cb now points to boxes[1].items[0].
   3. struct Item *p = (struct Item *)ptr + 2, ptr now points to boxes[1].items[2]
   4. char *x = (char *)p + offsetof(struct Item, type); ptr now points to boxes[1].items[2].type
   5. *x = 'X' is how we can modify it.
   
   
   /* 1) Pointer to the `type` field of boxes[1].items[2] */
char *type_ptr =
   (char *)(cb + 1)                                /* point to boxes[1] */
  + offsetof(struct Container, items)              /* skip past `count` to the start of `items[0]` */
  + 2 * sizeof(struct Item)                        /* skip two whole Item structs → now at items[2].weight */
  + offsetof(struct Item, type);                   /* skip past `weight` within Item to reach `type` */

	/* 2) Store 'X' into that `type` */
	*type_ptr = 'X';

*/
```
