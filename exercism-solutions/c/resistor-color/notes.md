### Learnings

Error encountered:
```bash
Compiling tests.out
./test_resistor_color.c: In function ‘test_colors’:
./test_resistor_color.c:36:36: error: initialization of ‘const resistor_band_t *’ from ‘int’ makes pointer from integer without a cast [-Werror=int-conversion]
   36 |    const resistor_band_t *actual = colors();
      |                                    ^~~~~~
cc1: all warnings being treated as errors
make: *** [makefile:37: tests.out] Error 1
```
- There was no colors(); declared.
- Had to declare `const resistor_band_t* colors();` in header file because based on the error, The function colors() should return a value of type const resistor_band_t *.
- then declared `static const resistor_band_t color_array[] = { /* some resistor_band_t values */ };`
    - Here `static` is used to persist the value of array between function calls.
- The test was to check if color_array is same as expected :
```bash
static void test_colors(void)
{
   const resistor_band_t expected[] = { BLACK, BROWN, RED,    ORANGE, YELLOW,
                                        GREEN, BLUE,  VIOLET, GREY,   WHITE };
   const resistor_band_t *actual = colors();
   TEST_ASSERT_EQUAL_INT_ARRAY(expected, actual, ARRAY_LENGTH(expected));
}
```
