#include <stdio.h>

enum Color { RED, GREEN, BLUE, NUM_COLORS };

const char *color_names[NUM_COLORS] = {
    "Red Color",
    "Green Color",
    "Blue Color"
};

void print_upcase(const char *s) {
    while (*s) {
        char ch = *s;
        if ('a' <= ch && ch <= 'z')
            putchar(ch - 32);
        else
            putchar(ch);
        s++;
    }
}

void test_enum_ptr(enum Color *cp, int count) {
    while (count--) {
        print_upcase(color_names[*cp]);
        putchar('\n');
        cp++;
    }
}

int main(void) {
    enum Color arr[] = {GREEN, BLUE, RED};
    // arr[0] = 1, arr[1] = 2, arr[2] = 0 (check enum positions)
    test_enum_ptr(arr, sizeof(arr)/sizeof(*arr));

    int *ip = (int *)arr;
    test_enum_ptr((enum Color *)ip, 3);

    enum Color clr;
    /*
    | Property            | Description                                                            |
    | ------------------- | ---------------------------------------------------------------------- |
    | **Type**            | `enum Color`                                                           |
    | **Storage**         | Usually occupies the same space as an `int` (4 bytes on most systems)  |
    | **Default Value**   | Uninitialized (undefined value unless explicitly assigned)             |
    | **Value Semantics** | Can hold **any integer**, even values not in the enum list             |
    | **Not a Constant**  | `clr` is **not a constant** — it’s a modifiable lvalue                 |
    | **Symbol Mapping**  | `RED`, `GREEN`, `BLUE` are just named `int` constants (`0`, `1`, `2`)  |
    | **Usage**           | Used to make code more readable and type-safe in APIs and switch-cases |
    */
    return 0;
}
