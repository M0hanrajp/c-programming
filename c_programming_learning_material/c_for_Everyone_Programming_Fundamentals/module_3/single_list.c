#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int data;
    struct list *next;
} list;

list *createList(int data) {
    list *head = calloc(1, sizeof(list));
    head->data = data;
    head->next = NULL;
    return head;
}

list *addList(int data, list *phead) {
    list *head = createList(data);
    head->next = phead;
    return head;
}

list *createDescendingList(int *data, int size) {
    list *head = createList(data[0]);
    for(int i = 1; i < size; i++)
        head = addList(data[i], head);
    printf("print the list in decsending order\n");
    return head;
}

list *createAscendingList(int *data, int size) {
    list *head = createList(data[size - 1]);
    for(int i = size - 2; i >= 0; i--)
        head = addList(data[i], head);
    printf("print the list in ascending order\n");
    return head;
}

void printList(list *head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
    free(head);
    head = NULL;
}

int main(void) {
    printf("sizeof list :: %zu\n", sizeof(struct list));
    int data[5] = {1, 2, 3, 4, 8};
    printList(createDescendingList(data, sizeof(data)/sizeof(*data)));
    printList(createAscendingList(data, sizeof(data)/sizeof(*data)));
    return 0;
}
