/* A singly linked list is a fundamental data structure, it consists of nodes where 
 * each node contains a data field and a reference to the next node in the linked list. 
 * The next of the last node is null, indicating the end of the list. 
 * Linked Lists support efficient insertion and deletion operations.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
    node->next = NULL;
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

// Find length of List
int findLength() {
    return lSize;
    // in this program lSize, is keeping track of list size
    // it can also be returned by traversing the entire list
    // and then returning a new count
}

// delete a node
void deleteNode(node *node) {
    node->data = 0;
    node->next = NULL;
    free(node);
    node = NULL;
    lSize--;
}

// delete at front
node *deleteFront(node *head) {
    if(head == NULL || head->next == NULL) {
        printf("Not enough elements in the list to delete\n");
        exit(-1);
    }
    node *tmp = head;
    head = tmp->next;
    // delete the head and return new head;
    deleteNode(tmp);
    return head;
}

// delete at Rear
node *deleteRear(node *head) {
    if(head == NULL) {
        printf("Not enough elements in the list to delete\n");
        exit(-1);
    }
    // if list has only one node
    if(head->next == NULL) {
        deleteNode(head);
        return NULL;
    }
    node *slnode  = head;
    // get the node linked to last node
    while (slnode->next->next != NULL) {
        slnode = slnode->next;
    }
    // update node link to NULL to indicate new last element
    // forgetting to do this will result in segfault
    // delete last node and return head;
    deleteNode(slnode->next);
    slnode->next = NULL;
    return head;
}

// delete at given position
node *deleteAtIndex(int index, node *head) {
    if(index > lSize - 1) {
        printf("Accessing out of bound list, delete not permitted at this location\n");
        exit(-1);
    }
    if(head == NULL) {
        printf("Not enough elements in the list to delete\n");
        exit(-1);
    }
    // if list has only one node
    if(head->next == NULL) {
        deleteNode(head);
        return NULL;
    }
    if(index == 0) {
        node *newHead = deleteFront(head);
        return newHead;
    }
    if(index == lSize - 1) {
        node *newHead = deleteRear(head);
        return newHead;
    }
    int pindex  = index - 1;
    node *phead = head;
    while (pindex) {
        phead = phead->next;
        pindex--;
    }
    // get the node to delete
    node *tmp = phead->next;
    // Assign link to next element after the deleted element
    phead->next = phead->next->next;
    deleteNode(tmp);
    return head;
}

// reverse a linked list
node *reverseList(node *head) {
    node *current = head, *previous = NULL, *next;
    while (current != NULL) {
        // update next node from current node
        next = current->next;
        // Link the current node to previous node
        current->next = previous;

        // update previous element as current
        previous = current;
        // in order to go to next element
        // update current as next
        current = next;
    }
    // this will become the head at last traversal
    return previous;
}

// print List
void printLinkedList(node *head) {
    node *tmp = head;
    while (tmp != NULL) {
        printf("%c -> ", tmp->data);
        tmp = tmp->next;
    }
    printf("END, total size = %d\n", lSize);
}

int main(void) {
    char str[11] = "12345";
    node *n = initializeList(str[0]);
    printLinkedList(n);
    n = pushFront(str[1], n);
    printLinkedList(n);
    n = pushEnd(str[2], n);
    printLinkedList(n);
    n = pushEnd(str[4], n);
    printLinkedList(n);
    n = pushAtIndex('8', 0, n);
    printLinkedList(n);
    n = pushAtIndex('8', 4, n);
    printLinkedList(n);
    n = pushAtMiddle('*', lSize, n);
    printLinkedList(n);
    n = pushAtMiddle('+', lSize, n);
    printLinkedList(n);

    // searching
    printf("Is \'+\' present in List ? %s\n", searchElement('+', n) ? "yes" : "no");
    printf("Is \'=\' present in List ? %s\n", searchElement('=', n) ? "yes" : "no");

    // delete the first element
    n = deleteFront(n);
    printLinkedList(n);
    // delete the last element
    n = deleteRear(n);
    printLinkedList(n);
    // delete at position
    n = deleteAtIndex(3, n);
    printLinkedList(n);

    node *rn = reverseList(n);
    printLinkedList(rn);
    return 0;
}
