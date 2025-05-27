/* Note
 * the subscript operator [], the member‐access operator . and the arrow operator -> 
 * all share the same precedence and associate left-to-right.
 * https://en.cppreference.com/w/c/language/operator_precedence
 */

int main(void) {
    typedef struct {
        int id;
        char name[50];
    } dev;

    dev dba = {2, "deviceA"};
    dev dbb = {3, "deviceB"};
    /* dba & dbb are of type dev
     * you can use . operator to access elements
     * dba.id will give you id. (object.member)
     */

    dev *cb = &dba;
    /* &dba is of type dev * & *cb(pointer to a struct (dev)) is assigned &dba.
     * cb is of type dev *,  you can use -> operator to access elements.
     * -> is used to dereference struct members for a variable that is pointer to a struct type.
     * cb->id is same as (*cb).id (pointer.member) */

    dev **a = &cb;
    /* here &cb is of type dev **, it is assigned to a.
     * a is dev** (dereferencing is required once), *a is dev*(arrow operator to be used), **a is dev(dot operator can be used).
     * (*a)->name == (**a).name (this is char* because name is a char array);
     */

    dev *db[2] = {&dba, &dbb};
    /* db decays to dev**, it's an array of pointers, each element of the array is dev* 
     * it's a double pointer kind of variable that holds address
     * each address is always 8 bytes which is of type dev*
     * based on above concepts use -> operator to gain access to struct members
     *
     * Note: “Arrays in expressions (except when they’re the operand of sizeof, _Alignof, 
     * or the unary &) convert to pointers to their first element.” so the type of db in that context is dev **
     */

    dev **ptr = db;
    /* ptr[0]->name accessing name char array.
     * ptr[0] expands to *(ptr + 0) which gives you location of dba
     * dba is of type dev*, hence ptr[0]->name gives you address of the char array
     * ptr[0]->name == (*(*(ptr + 0))).name
     * the above output is ok when you are accessing the first element of the array dba
     *
     * For second element.
     * if you write, ptr[1]->name, you will get seg fault(undefined behavior), or program will write indeterminate value.
     * why ?? array subsript has highest precedence, ptr is of type dev** (pointer to pointer to it's first element)
     * so when ptr[1] is done it will be *(ptr + 1), ptr will move by sizeof(db) which is a pointer (move by 8 bytes)
     * ptr should move by dev* which is sizeof(*db) i.e. sizeof(struct object) hence.
     * ptr[1]-> name should be written as (*ptr)[1].name (pointer variables will move by sizeof the thing they point too)
     * *ptr get the base address of array i.e. &dba and then move by sizeof(dev*)
     * (*ptr)[1] or *((*ptr) + 1) second struct member of type dev (will directly give struct instance)
     * use dot operator to get desired field values.
     *
     * representation with address
     * dba = 0xFFF000B60 struct type (at this level you can use . operator to manipulate fields)
     * dbb = 0xFFF000BA0 struct type (      ""      )
     * 
     * db array of pointers, will contain address that are of type dev*
     * db = element 0 -> 0xFFF000B50 (pointer type), *db = 0xFFF000B60 struct type.
     *    = element 1 -> 0xFFF000B58 (pointer type), *db = 0xFFF000BA0 struct type.
     *
     * **ptr = db.
     * ptr   =  level 1 -> 0xFFF000B50 (pointer type) & address: &ptr itself
     * *ptr  =  level 2 -> 0xFFF000B60 (struct  type) & address: 0xFFF000B50 (pointer type).
     * **ptr =  level 3 -> 0xFFF000B60 (struct feild) & address: 0xFFF000B60 (struct object).
     */

    // some questions from quiz

    struct Item { int id; float price; };
    struct Item items[5];
    struct Item *iptr = items;
    /* How do you set the price of the third element (items[2]) to 9.99 using iptr?
     * iptr[2].price = 9.99 or (iptr + 2)->price = 9.99;
     * because iptr already has address of first element., iptr = items or &items[0].
     */

    struct Widget { int id; };
    struct Widget *wptrs[10];
    struct Widget **wp = wptrs;
    /* How do you assign a newly malloc’d Widget to the 5th slot (wptrs[4]) via wp?
     * **wp = wptrs holds the address of first element (that holds struct Widget * type address)
     * wp + 4 points to the fifth element of the array (i.e. wptrs[4]).
     * Dereferencing it gives you the storage location for a struct Widget *, so the type of wp[4] is indeed struct Widget *.
     * wp[4] = malloc(sizeof *wp[4]);
     */

    struct Rec { int a, b, c; };
    struct Rec arr[3];
    struct Rec *rp = &arr[1];
    /* What struct does *(rp + 1) refer to, and how would you set its c member to 100?
     * rp points at arr[1] (the second element).
     * So *(rp + 1) dereferences the pointer one element past that, i.e. it yields arr[2] (the third element).
     * (*(rp + 1)).c = 100; or (rp + 1)->c = 100;
     */
    return 0;
}
