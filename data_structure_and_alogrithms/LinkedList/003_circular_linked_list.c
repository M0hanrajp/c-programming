#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int lSize = 0;
// Sekeleton of the list
typedef struct _node {
    char data;
    struct _node *next;
} node;

// Create the list
node *initializeList(char data) {
    node *node = calloc(1, sizeof(struct _node));
    node->data = data;
    node->next = node;
    lSize++;
    return node;
}

// build List (push from front)
node *pushFront(char data, node *tail) {
    if(tail == NULL) {
        printf("Please initilaize the List first!\n");
        exit(-1);
    }
    node *node = initializeList(data);
    node->next = tail;
    tail->next = node;
    return node;
}

// print List
void printLinkedList(node *head) {
    node *tmp = head;
    do {
        printf("%c -> ", tmp->data);
        tmp = tmp->next;
    } while(tmp != head);
    printf("[END] total size = %d\n", lSize);
}

// print List with address to verify curr and next address for a node
void printLinkedListWithAddress(node *head) {
    printf("\n === [ DEBUG ] === \n");
    node *tmp = head;
    do {
        printf("C::%p & D::%c N::%p\n",
                tmp, tmp->data, tmp->next);
        tmp = tmp->next;
    } while(tmp != head);
    printf("[END] total size = %d\n", lSize);
}

int main(void) {
    node *n = initializeList('M');
    n = pushFront('T', n);
    printLinkedList(n);

    printLinkedListWithAddress(n);
    return 0;
};
