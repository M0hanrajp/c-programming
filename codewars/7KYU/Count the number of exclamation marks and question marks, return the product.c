/* Count the number of exclamation marks and question marks, return the product.
"!!!??"     --->   6
"!!!???"    --->   9
"!???!!"    --->   9
"!????!!!?" --->  20 */
unsigned product (const char *string) {
  int q = 0, e = 0;
  while(*string) {
    switch(*string) {
        case '!': e++; break;
        case '?': q++; break;
        default :      break;
    }
    string++;
  }
  return q * e;
}
