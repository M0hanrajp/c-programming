#include <stdio.h>

int main(int ac, char (*)av[]) {
    printf("%d\n", ac);
    printf("%s\n", av[0]);
    return 0;
}
/* the below is not of the proper form
c_question.c:3:26: error: expected ‘;’, ‘,’ or ‘)’ before ‘av’
    3 | int main(int ac, char (*)av[]) {
      |                          ^~
*/
