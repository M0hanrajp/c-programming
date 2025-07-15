/* https://www.geeksforgeeks.org/dsa/stack-data-structure/
 * Stack data structure implementation in C
 * A Stack is a linear data structure that follows a particular order in which the operations are performed. 
 *      The order may be LIFO(Last In First Out) or FILO(First In Last Out). 
 *      LIFO implies that the element that is inserted last, comes out first and 
 *      FILO implies that the element that is inserted first, comes out last.
 * It behaves like a stack of plates, where the last plate added is the first one to be removed. 
 *      Think of it this way:
 *      Pushing an element onto the stack is like adding a new plate on top.
 *      Popping an element removes the top plate from the stack.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STACK_SIZE 50
#define PRINT_STACK(stack)  printf("Stack size: %d, Stack top: %d, :: ", stack->stackSize, stack->top); \
                            for(int i = 0; stack->s[i] != '\0'; i++) { \
                                printf("%c", stack->s[i]);             \
                            } printf("\n");
// stack skeleton
typedef struct _stack {
	char *s;
	int  top;
	int  stackSize;
} stack;

// create & initialize stack
stack *createStack(int stackSize) {
	if(stackSize > MAX_STACK_SIZE) {
		printf("Cannot build stack of size %d, expected stack size < %d\n", stackSize, MAX_STACK_SIZE);
		exit(-1);
	}
	stack *stack = calloc(1, sizeof(struct _stack));
	stack->top = 0;
	stack->stackSize = stackSize;
	stack->s = calloc(stackSize, sizeof(char));
	printf("stack initialization compelte\n");
	return stack;
}

// check if stack is full
bool isStackFull(stack *stack) {
	return stack->top > stack->stackSize - 1;
}

// check if stack is empty
bool isStackEmpty(stack *stack) {
	return stack->top == 0;
}

// peek top value of the stack
int peekFromStack(stack *stack) {
	if(isStackEmpty(stack)) {
		printf("peek denied, stack is empty\n");
		return -1;
	}
	printf("Peek retuned :: %c\n", stack->s[stack->top - 1]);
    return 0;
}

// push elements to stack
int pushToStack(char c, stack *stack) {
	if(isStackFull(stack)) {
		printf("stack overflow\n");
		return -1;
	}
	printf("%c pushed to stack\n",
	       (stack->s[stack->top++] = c));
	return 0;
}

// pop elements from stack
char popFromStack(stack *stack) {
	if(isStackEmpty(stack)) {
		printf("POP denied, stack is empty\n");
		return -1;
	}
	char pop = stack->s[stack->top - 1];
	stack->s[stack->top - 1] = 0;
	stack->top -= 1;
	return pop;
}

int getStackSize(stack *stack) {
	return stack->top;
}

// delete the stack
void deleteStack(stack *stack) {
	free(stack->s);
	stack->s = NULL;
	free(stack);
	stack = NULL;
	printf("stack is deleted\n");
}

int main(void) {
	char a[5] = "STACK"; /* can be any array data type */
	stack *stack = createStack(5);

	isStackEmpty(stack) ? printf("Stack is empty\n") : printf("Stack not empty\n");
	// fails to peek empty Stack
	peekFromStack(stack);

	// PUSH
	for(int i = 0; a[i] != '\0'; i++) {
		pushToStack(a[i], stack);
	}
	// print the whole stack
	PRINT_STACK(stack);

	// fails to push extra letters
	pushToStack('M', stack);
	peekFromStack(stack);

	// POP
	printf("%c poped from stack\n", popFromStack(stack));
	PRINT_STACK(stack);
	printf("%c poped from stack\n", popFromStack(stack));
	PRINT_STACK(stack);

	// GET size
	printf("size of stack:: %d\n", getStackSize(stack));

	// delete
	deleteStack(stack);
	return 0;
}
