/* https://www.geeksforgeeks.org/dsa/queue-data-structure/
 * A Queue Data Structure is a fundamental concept in computer science used for storing and managing data in a specific order.
 * It follows the principle of "First in, First out" (FIFO), where 
 *      the first element added to the queue is the first one to be removed.
 *      It is used as a buffer in computer systems where we have speed mismatch between two devices 
 *      that communicate with each other. For example, CPU and keyboard and two devices in a network
 *      Queue is also used in Operating System algorithms like CPU Scheduling and Memory Management, 
 *      and many standard algorithms like Breadth First Search of Graph, Level Order Traversal of a Tree.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_QUEUE_SIZE 50
#define PRINT_QUEUE(queue) printf("Queue back: %d, :: ", queue->back); \
                           for(int i = 0; queue->s[i] != '\0'; i++) {  \
                               printf("%c", queue->s[i]);              \
                           } printf("\n");

// skeleton of the queue
typedef struct _queue {
	char *s;
	int  front;
	int  back;
    int  queueSize;
} queue;

// create and initialize Queue
queue *createQueue(int qSize) {
    if(qSize > MAX_QUEUE_SIZE) {
        printf("Cannot build stack of size %d, expected stack size < %d\n", 
                qSize, MAX_QUEUE_SIZE);
        exit(-1);
    }
    queue *queue = calloc(1, sizeof(struct _queue));
    queue->front = 0;
    queue->back  = 0;
    queue->queueSize = qSize;
    queue->s = calloc(qSize, sizeof(char));
    return queue;
}

// check if queue is full
bool isQueueFull(queue *queue) {
    return queue->back >= queue->queueSize - 1;
}

// check if queue is empty
bool isQueueEmpty(queue *queue) {
    return queue->back == queue->front;
}

// Get front value of the Queue
char getFrontValue(queue *queue) {
    if(isQueueEmpty(queue))  {
        printf("Queue is Empty, GET denied\n");
        return -1;
    }
    return queue->s[queue->front];
}

// Get end value of the Queue
char getEndValue(queue *queue) {
    if(isQueueEmpty(queue))  {
        printf("Queue is Empty, GET denied\n");
        return -1;
    }
    return queue->s[queue->back - 1];
}

// PUSH value at end of Queue
int pushToQueue(queue *queue, char c) {
    if(isQueueFull(queue)) {
        printf("Queue is full, PUSH denied\n");
        return -1;
    }
	printf("%c pushed to queue\n",
	      (queue->s[queue->back++] = c));
    return 0;
}

// POP value at front of Queue
char popFromQueue(queue *queue) {
    if(isQueueEmpty(queue))  {
        printf("Queue is Empty, POP denied\n");
        return -1;
    }
    char pop = queue->s[queue->front];
    // update the Queue
    for(int i = 0; i < queue->back; i++) {
        queue->s[i] = queue->s[i + 1];
    }
    queue->s[queue->back - 1] = 0;
    queue->back -= 1;
    return pop;
}

// returns the number of valid elements in Queue
int getQueueSize(queue *queue) {
    return queue->back;
}

// delete the Queue
void deleteQueue(queue *queue) {
    free(queue->s);
    queue->s = NULL;
    free(queue);
    queue = NULL;
	printf("Queue is deleted\n");
}

int main(void) {
	char str[6] = "QUEUE";

    // create and initialize
    queue *q = createQueue(6);
    // fail case, getting value from empty queue
    if(getFrontValue(q) != (char)-1) {
        printf("Value returned:: %c\n", getFrontValue(q));
    }

    // PUSH and print the whole QUEUE
    for(int i = 0; str[i] != '\0'; i++) {
        pushToQueue(q, str[i]);
    }
    PRINT_QUEUE(q);

    // fail case, pushing to stack when Queue is full
    if(pushToQueue(q, 'M') != (char)-1) {
        PRINT_QUEUE(q);
    }

    // GET front and end values from QUEUE
    printf("Front :: %c & Back :: %c\n",
            getFrontValue(q), getEndValue(q));

    // POP
    printf("%c poped from Queue\n", popFromQueue(q));
    PRINT_QUEUE(q);
    printf("%c poped from Queue\n", popFromQueue(q));
    PRINT_QUEUE(q);
    printf("%c poped from Queue\n", popFromQueue(q));
    PRINT_QUEUE(q);
    // GET front and end values from QUEUE
    printf("Front :: %c & Back :: %c\n",
            getFrontValue(q), getEndValue(q));

    deleteQueue(q);

	return 0;
}
