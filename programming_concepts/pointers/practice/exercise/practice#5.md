struct Point {
    int x;
    int y;
};

struct Point pts[3] = { {1, 2}, {3, 4}, {5, 6} };
struct Point *p = pts;
printf("%d %d\n", (p + 2)->x, (p + 1)->y);

/* Given the following structure and variable declarations, what is the output of the printf statement? 
  (Assume a 32-bit system where sizeof(int) = 4 and no padding is added.)
  
  prints > 5 4 with new line.
  
*/

struct Node {
    char label;
    int value;
};

/* You have an array struct Node nodes[5];. Without using the array subscript operator ([]), 
   write an expression to access the value member of the third element (nodes[2]) using only 
   pointer arithmetic and the -> operator.
   
   struct Node nodes[5];
   >> printf("value member %d\n", (nodes + 2)->value);
*/

struct Item {
    double price;
    int quantity;
} items[4];

/* and a pointer struct Item *ip = items;, what does the expression *(ip + 3) mean, and how 
   would you access its quantity field?
   
   struct Item *p = items, p points to items[0].
   In expression *(ip + 3)
		1. ip + 3 moves to the 4th element of the array items[4].
		2. dereferencing it will give us the struct object.
		3. Quantitiy field can be accessed as (ip + 3)->quantity or (*(ip + 3)).quantity or items[3].quantity.
*/

Explain what happens when you execute pointer arithmetic on a struct pointer. For instance, 
why does ptr + 1 increment the address by sizeof(*ptr)? Illustrate your answer with an example 
using a struct Employee { int id; char dept; };.

/* 
	struct Employee {
		int id;
		char dept;
	};
	struct Employee	e[2] = {{ 1, 'M'}, {2, 'M'}};
	struct Employee *p = e;
	
	Q: why does ptr + 1 increment the address by sizeof(*ptr)
		- The following is the memory layour of e[0], memory address is hypothetical for explanation
		e[0] - 0x1000 to 0x1003 occupied by int id. (4 bytes)
		e[0] - 0x1004 occupied by char dept. (1 byte)
		
		Assuming 64 bit architecture,
		- the largest size of struct member in struct Employee is an integer.
		- so the next struct object will be aligned at multiples of 4.
		
		so we add 3 bytes of padding after char dept.
		e[0] - 0x1000 to 0x1003 occupied by int id. (4 bytes)
		e[0] - 0x1004 occupied by char dept. (1 byte)
		e[0] - 0x1005 to 0x1007 padding.	
		
		Now for e[1] the next struct is going to start at 0x1008, perfectly aligned at multiple of 4.
		
		this is how one struct instance is laid out in memory,
		that is the reason it increment the address by sizeof(*ptr) which is nonthing but sizeof(struct Employee).
*/

struct Data {
    float a;
    float b;
};
struct Data *arr = malloc(5 * sizeof(struct Data));

/* write code that sets the b member of the fourth element (index 3) 
   to 3.14f using only pointer arithmetic (no [] indexing).
   
   *(float *)((char *)(arr + 3) + offsetof(struct Data, b)) = 3.14f;
*/

struct Container {
    int nums[3];
} c[2];

/* With a pointer struct Container *cp = c;, write an expression using 
  pointer arithmetic to set the second integer of the second Container to 10.
  
  struct Container *cp = c;
  
  cp += 1; cp now points to second Container c[1].nums[0]
  int *p = (int *)cp + 1; cp now points to c[1].nums[1].
  *p = 10;
*/

struct Record {
    long id;
    short flags;
    char name[10];
} recs[10];

struct Record *rp = &recs[5];

/* What is the result of (char *)(rp + 1) - (char *)rp? 
   Explain why this calculation is useful when dealing with raw memory.
   
   rp currently points to the 6th element.
   (char *)(rp + 1) - (char *)rp // this is a subtraciton betweem two pointers of the same type.
   it is taking the difference of &recs[6] - &recs[5]
   so the answer will be (char *)(rp + 1) - (char *)rp = 1 * sizeof(struct Record).
   
   this calculation is useful when manipulating at byte level,
   we can change any of the 10 characters of char array name (the 3rd member of struct Record)
   
   // extra
   - This technique is often used in low-level memory management (e.g., binary serialization, memory-mapped I/O, or manual alignment).
   - It tells you how much memory each struct occupies, including any padding.
   - 	
*/

struct Pair {
    int a;
    int b;
};
struct Pair arr[] = { {2, 4}, {6, 8}, {10, 12} };
struct Pair (*pp)[3] = &arr;

/* How can you use pp and pointer arithmetic to print the value 8? 
   Write the exact printf format string and argument (no temporary variables).
   
   here pp is pointer to all 3 elements of struct Pair.
   dereferencing once we get pointer to base element arr[0] & by adding 1 we move to arr[1].a
   printf("b = %d\n", *(int *)((char *)(*pp + 1) + offsetof(struct Pair, b)));
*/

struct Mixed {
    char c;
    double d;
    int i;
};

/* A pointer struct Mixed *mp points to the first element of an array of 10 such structures. 
   Without using sizeof(struct Mixed) explicitly, write an expression to advance mp to point to the fifth element.
   struct Mixed m[10];
   struct Mixed *mp = m;
   
   mp += 4 will move it to 5th element.
*/

struct Example {
    char x;
    // compiler adds 3 bytes padding
    int y;
};
struct Example exs[4];
struct Example *e = exs;

/* 

calculate (in bytes) the difference between (char *)(e + 2) and (char *)e, assuming typical alignment and padding rules.
	- answer : 2 * sizeof(struct Example) = 16 bytes.
*/