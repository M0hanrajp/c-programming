/* Dynamic Stack Implementation
 * TODO: Add NULL checks in the stack
 */
#include <stdio.h>
#include <stdlib.h>

// node
typedef struct _Node {
	char data;
	struct _Node *next;
} Node;

Node *createNode(char data) {
	Node *node = calloc(1, sizeof(Node));
	node->data = data;
	node->next = NULL;
	return node;
}

// Stack with member element pointer to a Node type
typedef struct _Stack {
	Node *head;
} Stack;

Stack *initializeStack() {
	Stack *s = calloc(1, sizeof(struct _Stack));
	s->head = NULL;
	return s;
}

void push(char data, Stack *stack) {
	Node *newNode = createNode(data);
	// for the first Node creation, stack->head is NULL, hence first node link is always NULL
	newNode->next = stack->head;
	stack->head = newNode;
}

void pop(Stack *stack) {
	Node *tmp = stack->head;
	stack->head = tmp->next;
	printf("%c was poped\n", tmp->data);
	free(tmp);
	tmp = NULL;
}

void peek(Stack *stack) {
	printf("Current Top :: %c\n", stack->head->data);
}

void printStack(Stack *s) {
	Node *c = s->head;
	while(c != NULL) {
		printf("%c -> ", c->data);
		c = c->next;
	}
	printf("\n");
}

void printStackDBG(Stack *s) {
	Node *c = s->head;
	printf("\n=== DEBUG ===\n");
	while(c != NULL) {
		printf("%c curr:: %p nex:: %p\n", c->data, c, c->next);
		c = c->next;
	}
	printf("\n");
}

void printEr(Stack *stack) {
	Stack *c = stack;           // c and s point to the *same* Stack
	while (c->head != NULL) {
		printf("%c -> ", c->head->data);
		c->head = c->head;  // **this moves the Stack’s head pointer**
	}
}

int main(void) {
	Stack *s = initializeStack();
	push('1', s);
	push('2', s);
	push('3', s);
	printStack(s);
	printStackDBG(s);
	
	pop(s);
	printStackDBG(s);
	return 0;
}
