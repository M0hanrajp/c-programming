#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int lSize = 0;
// Sekeleton of the list
typedef struct _node {
    char data;
    struct _node *next;
    struct _node *prev;
} node;

// Create the list
node *initializeList(char data) {
    node *node = calloc(1, sizeof(struct _node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
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
    tail->prev = node;
    node->next = tail;
    return node;
}

// build List (push from rear)
node *pushEnd(char data, node *head) {
    if(head == NULL) {
        printf("Please initilaize the List first!\n");
        exit(-1);
    }
    struct _node *lastHead = head;
    while (lastHead->next != NULL) {
        lastHead = lastHead->next;
    }
    struct _node *newNode = initializeList(data);
    // Link with pervious node
    lastHead->next = newNode;
    newNode->prev = lastHead;
    return head;
}

// push node at defined index
node *pushAtIndex(char data, int index, node *head) {
    if(index == 0) {
        node *newHead = pushFront(data, head);
        return newHead;
    }
    if(index == (lSize - 1)) {
        node *newHead = pushEnd(data, head);
        return newHead;
    }
    // get to the node behind that index.
    int pindex = index - 1;
    node *phead = head;
    while (pindex) {
        phead = phead->next;
        pindex--;
    }
    // create temp new node to insert at index
    node *newNode = initializeList(data);
    newNode->data = data;

    // newNode will point to data at phead->next
    newNode->next = phead->next;
    // newNode prev points back to phead
    newNode->prev = phead;
    // data at phead->next points back to newNode
    phead->next->prev = newNode;
    // phead will have the new node's address
    phead->next = newNode;

    return head;
}

// push node at middle of the list
node *pushAtMiddle(char data, char totalSize, node *head) {
    return pushAtIndex(data, totalSize/2, head);
}

// search an element in node
bool searchElement(char key, node *head) {
    node *tmp = head;
    while(tmp != NULL) {
        if(tmp->data == key)
            return true;
        tmp = tmp->next;
    }
    return false;
}

// print List
void printLinkedList(node *head) {
    node *tmp = head;
    while (tmp != NULL) {
        printf("%c -> ",tmp->data);
        tmp = tmp->next;
    }
    printf("[END] total size = %d\n", lSize);
}

// print List with address to verify curr and next address for a node
void printLinkedListWithAddress(node *head) {
    printf("\n === [ DEBUG ] === \n");
    node *tmp = head;
    while (tmp != NULL) {
        printf("P::%p C::%p & D::%c N::%p\n",
                tmp->prev, tmp, tmp->data, tmp->next);
        tmp = tmp->next;
    }
    printf("[END] total size = %d\n", lSize);
}

int main(void) {
    node *n = initializeList('M');
    // push to front
    n = pushFront('S', n);
    printLinkedList(n);

    // push to rear
    n = pushEnd('A', n);
    printLinkedList(n);

    // push at index
    n = pushAtIndex('8', 1, n);
    printLinkedList(n);
    
    // push at middle
    n = pushAtMiddle('+', lSize, n);
    printLinkedList(n);

    printLinkedListWithAddress(n);
    return 0;
}
