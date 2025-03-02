/* This kata is about a function that should return different values.
On the first call it must be 1, on the second and others - it must be a double from previous value.
Look tests for more examples, good luck :) */
unsigned get_number (void) {
  static unsigned p = 1, c = 0;
  c++; if(c < 2){return 1;}
  return p += p;
}
