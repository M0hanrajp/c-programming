#include <stdio.h>
#include <string.h>
#define MAX_LEN 20
#define EMPTY    0
// there are many more other operations that are not implemented

typedef struct stack {
    char s[MAX_LEN];
    int  top;
} stack;

/* @brief, clears the stack and sets elements of string & top to 0
 * stack is cleared for new use,
 * @param, stk gets the address of local stack session
 */
void reset(stack *stk) {
    memset(stk->s, 0, sizeof(stk->s));
    stk->top = EMPTY;
}

/*@brief, push the elements over stack's string one by one 
*/
void push(char *string, stack *stk) {
    for(int i = 0; string[i] != '\0'; i++)
        stk->s[stk->top++] = string[i];
    printf("[PUSH]: %s, [TOP]: %d\n", stk->s, stk->top);
}

/*@brief, pop the elements over stack's string one by one 
*/
void pop(char *string, stack *stk) {
    int str_idx = EMPTY;
    for(int i = stk->top - 1; i >= 0; i--)
        string[str_idx++] = stk->s[i];
    reset(stk);
}

int main(void) {
    char str[MAX_LEN] = "Summer Time";
    stack session;
    reset(&session);
    push(str, &session);
    pop(str, &session);
    printf("[POP]: %s\n", str);
    return 0;
}
