### structs and pointers by AI

```c
Pointer Offset into a Struct Array
What does this print? If you then do p += 2; and print again, what values appear?

struct Point { int x, y; };
struct Point pts[5] = { {0,0}, {1,1}, {2,2}, {3,3}, {4,4} };
struct Point *p = pts + 2;
printf("%d, %d\n", p->x, p->y);
/* This will print 2, 2
 * For again p += 2, it will print 4, 4
 */
```
Casting and Pointer Arithmetic
What is printed, and why?

int arr[4] = {10, 20, 30, 40};
char *pc = (char*)arr;
*(pc + sizeof(int)) = 0;
printf("%d\n", arr[1]);

/* pointer pc if any pointer arithmetic done will be done at byte level.
 * because we have cast it to char *
 * *(pc + sizeof(int)) >> here pc is char address type, 
 * doing +4 takes it to the next address in the array
 * so element at a[1] is made 0
 * prints > 0

    [ What did I miss ] 
    why the element at a[1] is made 0 ?         
    initially points to arr[0]
    then incrementing by 4 lands the address at arr[1]
                                                LSB            MSB
    because in a little endian machine, arr[1]: 0x14 0x00 0x00 0x00
    LSB is stored first we make it 0,   arr[1]: 0x00 0x00 0x00 0x00

    When printf reads the integer it reads 4 byte (an integer) prints 0
 */

Pointer to Pointer Manipulation
What character is printed, and explain the pointer steps.

char *words[] = {"alpha", "beta", "gamma"};
char **w = words;
w++;
printf("%c\n", *(*(--w) + 2));
/* 
    w = words, here w will have address of the first element of the array of pointers.
    *w = will give me address to the string (char *)
    **w = will give me the first character of the first string i.e. 'a' of string "alpha"

    w++ moves pointer to next element of array i.e. at words[1]
    you have used brackets
    --w will bring the pointer back at words[0]
    *(--w) will point to the whole char string "alpha"
    *(--w) + 2 will move the address by 2 characters at "pha"
    *(*(--w) + 2) dereferecning at that address will print 'p' (the answer)
*/

Struct with Embedded Pointer
What value is printed, and what did the assignment via pp do?

struct Node {
    int val;
    struct Node *next;
};
struct Node a = {1, NULL}, b = {2, NULL}, c = {3, NULL};
a.next = &b;
b.next = &c;
struct Node **pp = &a.next;
*pp = c.next = &a;
printf("%d\n", a.next->next->val);
/* 
    [guess]
    prints 1

    [How it actually works]
    struct Node **pp = &a.next;
    *pp is an alias for a.next.
    *pp = c.next = &a;
    First, c.next = &a; sets c.next so that c points back to a.
    Then *pp = &a; sets a.next = &a; (because *pp is a.next).
    a.next now points to a itself (a self-loop) & c.next also points to a.

    a.next is &a (self-loop), so a.next->next is also &a
    Thus a.next->next->val is a.val, which is 1.
*/

Pointer Arithmetic Beyond Array Bounds
Is this defined behavior? If it prints something, what would you expect and why?

double data[3] = {1.1, 2.2, 3.3};
double *d = data + 1;
printf("%.1f\n", *(d + 2));
/* 
    d points to data[1] when it was assigned
    inside the printf statement we are incrementing by 2, d is out of bounds
    dereferecing the value at that point is undefined behavior
    if it prints something it might be garbadge value

*/

Array of Structs and Incrementing a Pointer
What three numbers does this loop print?

struct Rect { int w, h; };
struct Rect shapes[] = { {2,3}, {4,5}, {6,7} };
struct Rect *r = shapes;
for(int i = 0; i < 3; ++i) {
    printf("%d\n", (r + i)->w * (r + i)->h);
}
/* 
    r points to the first element of struct array shapes[0]
    inside the loop we are performing pointer arithmetic on r, 
    any pointer arithmetic on r will move the pointer by sizeof(struct Rect)
    
    so inside the loop it will print
    6
    20
    42
*/

Function Pointer in a Struct
Which operation runs, and what is the output?

int add(int a, int b) { return a + b; }
int mul(int a, int b) { return a * b; }
struct Ops {
    int (*op)(int, int);
} ops[2] = { {add}, {mul} };
struct Ops *p = ops + 1;
printf("%d\n", p->op(3, 4));

/* 
    p will point to ops[1]
    p->op(3, 4) will trigger multiplication function
    12 is printed
*/


Pointer to Struct vs Struct Pointer Arithmetic
Explain the casting and what gets printed.

struct Item { char tag; float weight; };
struct Item items[2] = { {'A', 1.0f}, {'B', 2.0f} };
struct Item *ip = items;
char *cp = (char*)items;
cp += sizeof(struct Item);
struct Item *ip2 = (struct Item*)cp;
printf("%c %.1f\n", ip2->tag, ip2->weight);

/* 
    ip points to items[0]
    cp points to items[1] 
    ip2 gets address of cp
    prints > B 2.0
*/

Swapping via Double Pointer
After the swap, what do *pa and *pb print?

void swap(int **p1, int **p2) {
    int *temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
int a = 100, b = 200;
int *pa = &a, *pb = &b;
swap(&pa, &pb);
printf("%d %d\n", *pa, *pb);

/* 
  prints > 200 100, the swap function swaps their address  
*/

Pointer Arithmetic with Struct Padding
Assuming #pragma pack(1) removes padding, what does this print and why?

#pragma pack(push,1)
struct P { char c; double d; };
#pragma pack(pop)
struct P arr[2] = { {'x',1.5}, {'y',2.5} };
char *ptr = (char*)arr;
ptr += sizeof(struct P) + sizeof(char);
struct P *p = (struct P*)(ptr - sizeof(char));
printf("%c %.1f\n", p->c, p->d);
/* 
    prints > y 2.5
*/
```
