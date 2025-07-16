#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#define MAX_QUEUE_SIZE 50

// skeleton of the queue
typedef struct _queue {
	char *s;
        int  front;
	int  back;
        int  Size;
        int  defaultSize;
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
    queue->Size  = 0;
    queue->defaultSize = qSize;
    queue->s = calloc(qSize, sizeof(char));
    return queue;
}

// check if queue is full
bool isQueueFull(queue *queue) {
    return queue->Size >= queue->defaultSize - 1;
}

// check if queue is empty
bool isQueueEmpty(queue *queue) {
    return queue->Size == 0;
}

// Get front value of the Queue
char getFrontValue(queue *queue) {
    if(isQueueEmpty(queue))  {
        printf("Queue is Empty, GET denied\n");
        exit(-1);
    }
    return queue->s[queue->front];
}

// Get end value of the Queue
char getEndValue(queue *queue) {
    if(isQueueEmpty(queue))  {
        printf("Queue is Empty, GET denied\n");
        return -1;
    }
    if(queue->back == 0) {
        return queue->s[queue->defaultSize - 1];
    }
    return queue->s[queue->back - 1];
}

// PUSH value at end of Queue
int pushToQueue(queue *queue, char c) {
    if(isQueueFull(queue)) {
        printf("Queue is full, PUSH denied\n");
        exit(-1);
    }
    if(queue->back > queue->defaultSize - 1)
        queue->back = 0;
    printf("%c pushed to queue\n",
            (queue->s[queue->back++] = c));
    queue->Size++;
    return 0;
}

// POP value at front of Queue
char popFromQueue(queue *queue) {
    if(isQueueEmpty(queue))  {
        printf("Queue is Empty, POP denied\n");
        exit(-1);
    }
    if(queue->front > queue->defaultSize - 1)
        queue->front = 0;
    char pop = queue->s[queue->front];
    queue->s[queue->front] = 0;
    // update the Queue
    queue->front++;
    queue->Size--;
    return pop;
}

// returns the number of valid elements in Queue
int getQueueSize(queue *queue) {
    return queue->Size;
}

void displayQueue(queue *queue) {
    if(isQueueEmpty(queue)) {
        printf("Queue is Empty, DISPLAY denied\n");
        exit(-1);
    }
    int i = queue->front;
    printf("Front: %d, End: %d, current Queue Size: %d :: ", 
            queue->front, queue->back, queue->Size);
    do {
        printf("%c", queue->s[i]);
        i++;
        if(i > queue->defaultSize) i = 0;
    } while(i != queue->back);
    printf("\n");
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
    // uncomment: fail case, getting value from empty queue
    // if(getFrontValue(q) != (char)-1) {
    //    printf("Value returned:: %c\n", getFrontValue(q));
    // }

    // PUSH and print the whole QUEUE
    for(int i = 0; str[i] != '\0'; i++) {
        pushToQueue(q, str[i]);
    }
    displayQueue(q);


    // Uncomment: fail case, pushing to stack when Queue is full
    // if(pushToQueue(q, 'M') != (char)-1) {
    //    displayQueue(q);
    // }

    // GET front and end values from QUEUE
    printf("Front :: %c & Back :: %c\n",
            getFrontValue(q), getEndValue(q));

    // POP
    printf("%c poped from Queue\n", popFromQueue(q));
    displayQueue(q);
    printf("%c poped from Queue\n", popFromQueue(q));
    displayQueue(q);
    printf("%c poped from Queue\n", popFromQueue(q));
    displayQueue(q);
    printf("%c poped from Queue\n", popFromQueue(q));
    displayQueue(q);
    // case where front and back are same
    printf("Front :: %c & Back :: %c\n",
            getFrontValue(q), getEndValue(q));
    pushToQueue(q, 'Z');
    displayQueue(q);

    // Uncomment: Test new circular Queue implementation, end will become 0
    // pushToQueue(q, 'Q');
    // displayQueue(q);
    printf("Front :: %c & Back :: %c\n",
            getFrontValue(q), getEndValue(q));
    deleteQueue(q);

	return 0;
}
