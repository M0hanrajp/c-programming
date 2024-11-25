#include "string_to_int_convert.h"

/* algo to compute ISBN number
Input : 007462542X
Output : Valid
007462542X = 10*0 + 9*0 + 8*7 + 7*4 + 6*6 + 
        5*2 + 4*5 + 3*4 + 2*2 + 1*10 = 176
Since 55 leaves no remainder when divided 
by 11, hence it is a valid ISBN.

Input : 0112112425
Output : Invalid
0112112425 = 10*0 + 9*1 + 8*1 + 7*2 + 6*1 +
           5*1 + 4*1 + 3*4 + 2*2 + 1*5 = 71
Since 71 is not divisible by 11, given number
is not a valid ISBN.
 */
bool checkIsValidISBN(const char *inputString) {
    bool isValidISBN = 0;
    uint64_t sumISBN = 0;
    uint8_t index = 0;
    uint8_t multiplier = 10;
    while (inputString[index] != '\0' && multiplier != 0) {
        if(inputString[index] == '0') {
            index++;
            multiplier--;
            continue;
        }
        if(inputString[index] == 'X') {
            sumISBN = sumISBN + (10 * multiplier);
            index++;
            multiplier--;
            continue;
        }
        sumISBN += ((inputString[index] - '0') * multiplier);
        index++;
        multiplier--;
    }
    isValidISBN = sumISBN % 11;
    return isValidISBN;
}
