/*
 * Deque (Double-Ended Queue) implementation using a fixed-size circular array in C.
 * Supports insertion and removal at both front and back.
 */

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 5  // Maximum capacity of the deque

// Deque structure
typedef struct {
    int arr[MAX_SIZE];  // Array to store elements
    int front;          // Index of front element
    int rear;           // Index of rear element
    int size;           // Current number of elements
} Deque;

// Initialize the deque
void initDeque(Deque *dq) {
    dq->front = 0;
    dq->rear = -1;
    dq->size = 0;
}

// Check if deque is empty
bool isEmpty(Deque *dq) {
    return dq->size == 0;
}

// Check if deque is full
bool isFull(Deque *dq) {
    return dq->size == MAX_SIZE;
}

// Insert an element at the rear
bool pushBack(Deque *dq, int value) {
    if (isFull(dq)) {
        return false; // Overflow
    }
    dq->rear = (dq->rear + 1) % MAX_SIZE;
    dq->arr[dq->rear] = value;
    dq->size++;
    return true;
}

// Insert an element at the front
bool pushFront(Deque *dq, int value) {
    if (isFull(dq)) {
        return false; // Overflow
    }
    dq->front = (dq->front - 1 + MAX_SIZE) % MAX_SIZE;
    dq->arr[dq->front] = value;
    dq->size++;
    return true;
}

// Remove and return the front element
int popFront(Deque *dq, bool *success) {
    if (isEmpty(dq)) {
        *success = false; // Underflow
        return -1;
    }
    int value = dq->arr[dq->front];
    dq->front = (dq->front + 1) % MAX_SIZE;
    dq->size--;
    *success = true;
    return value;
}

// Remove and return the rear element
int popBack(Deque *dq, bool *success) {
    if (isEmpty(dq)) {
        *success = false; // Underflow
        return -1;
    }
    int value = dq->arr[dq->rear];
    dq->rear = (dq->rear - 1 + MAX_SIZE) % MAX_SIZE;
    dq->size--;
    *success = true;
    return value;
}

// Peek front element without removing
int peekFront(Deque *dq, bool *success) {
    if (isEmpty(dq)) {
        *success = false;
        return -1;
    }
    *success = true;
    return dq->arr[dq->front];
}

// Peek rear element without removing
int peekBack(Deque *dq, bool *success) {
    if (isEmpty(dq)) {
        *success = false;
        return -1;
    }
    *success = true;
    return dq->arr[dq->rear];
}

// Display all elements from front to rear
void displayDeque(Deque *dq) {
    if (isEmpty(dq)) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque contents: ");
    for (int i = 0, idx = dq->front; i < dq->size; i++) {
        printf("%d ", dq->arr[idx]);
        idx = (idx + 1) % MAX_SIZE;
    }
    printf("\n");
}

// Example usage
int main() {
    Deque dq;
    initDeque(&dq);

    pushBack(&dq, 10);
    pushBack(&dq, 20);
    pushFront(&dq, 5);
    displayDeque(&dq); // Expected: 5 10 20

    bool ok;
    int v1 = popFront(&dq, &ok);
    if (ok) printf("Popped front: %d\n", v1);
    int v2 = popBack(&dq, &ok);
    if (ok) printf("Popped back: %d\n", v2);

    displayDeque(&dq); // Remaining elements

    return 0;
}
