// https://www.geeksforgeeks.org/dsa/implementation-deque-using-doubly-linked-list/
// Deque implementation using doubly linked list
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Basic structure of a node inside a deque
typedef struct _node {
    struct _node *next;
    struct _node *prev;
    char value;
} Node;

// Deque skeleton
typedef struct _deque {
    Node *front;
    Node *rear;
    int  size;
} Deque;

/* Deque will contain nodes that will point to next and prev
 * each node will have the data.
 * so Deque inside is a doubly linked list with pointers to
 * front and rear nodes so that they can be accessed and deleted.
 */
Deque *createDeque(void) {
    Deque *dq = calloc(1, sizeof(struct _deque));
    dq->front = NULL;
    dq->rear  = NULL;
    dq->size  = 0;
    return dq;
};

bool isDequeEmpty(Deque *dq) {
    if(dq->front == NULL)
        return true;
    if(dq->rear == NULL)
        return true;
    return false;
}

Deque *pushFront(char data, Deque *dq) {
    if(dq == NULL) {
        printf("Initialize Deque first\n");
        return dq;
    }
    Node *newNode = calloc(1, sizeof(struct _node));
    newNode->next = dq->front;
    newNode->prev = NULL;
    newNode->value= data;
    if(isDequeEmpty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        // make current head's prev point to new head
        dq->front->prev = newNode;
        // update the current head with new head (inserting front)
        dq->front = newNode;
    }
    dq->size++;
    return dq;
}

Deque *deleteFront(Deque *dq) {
    if(dq == NULL) {
        printf("Initialize Deque first\n");
        return dq;
    }
    if(isDequeEmpty(dq)) {
        printf("Deque cannot be empty\n");
        return dq;
    }
    Node *tmp = dq->front;
    dq->front = dq->front->next;
    if(dq->front)
        dq->front->prev = NULL;
    else 
        dq->front = NULL;
    free(tmp);
    dq->size--;
    return dq;
}

char getDequeFront(Deque *dq) {
    return dq->front->value;
}

Deque *pushBack(char data, Deque *dq) {
    if(dq == NULL) {
        printf("Initialize Deque first\n");
        return dq;
    }
    Node *newNode = calloc(1, sizeof(struct _node));
    newNode->next = NULL;
    newNode->prev = dq->rear;
    newNode->value= data;
    if(isDequeEmpty(dq)) {
        dq->front = dq->rear = newNode;
    } else {
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
    dq->size++;
    return dq;
}

Deque *deleteBack(Deque *dq) {
    if(dq == NULL) {
        printf("Initialize Deque first\n");
        return dq;
    }
    if(isDequeEmpty(dq)) {
        printf("Deque cannot be empty\n");
        return dq;
    }
    Node *tmp = dq->rear;
    dq->rear = dq->rear->prev;
    if(dq->rear)
        dq->rear->next = NULL;
    else
        dq->front = NULL;
    free(tmp);
    dq->size--;
    return dq;
}

char getDequeRear(Deque *dq) {
    return dq->rear->value;
}

void clearDeque(Deque *dq) {
    while (!isDequeEmpty(dq)) {
        deleteFront(dq);
    }
}

void displayDeque(Deque dq) {
    if(isDequeEmpty(&dq)) {
        printf("Empty Deck !!!\n");
        return;
    }
    printf("REAR:: %c FRONT:: %c \n", getDequeRear(&dq), getDequeFront(&dq));
    while(dq.front != NULL) {
        printf("Value:: %c, A:: %p, NA:: %p, PA:: %p\n",
                dq.front->value, dq.front, dq.front->next, dq.front->prev);
        dq.front = dq.front->next;
    }
    printf("\n");
}

int main(void) {
    Deque *dq = createDeque();
    dq = pushFront('A', dq);
    dq = pushBack( 'B', dq);
    dq = pushBack( 'C', dq);
    dq = pushFront('0', dq);
    displayDeque(*dq);
    // deleting front element
    deleteFront(dq);
    displayDeque(*dq);
    // deleting rear element
    deleteBack(dq);
    displayDeque(*dq);

    deleteBack(dq);
    displayDeque(*dq);

    clearDeque(dq);
    displayDeque(*dq);

    return 0;
}
