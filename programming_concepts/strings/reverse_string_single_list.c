#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
    char c;
    struct list *next;
} list;

list *createList(char *data) {
    list *head = calloc(1, sizeof(struct list));
    head->c = *data;
    head->next = NULL;
    return head;
}

list *addList(char *data, list *phead) {
    list *head = createList(data);
    head->next = phead;
    return head;
}

list *buildList(char (*string)[]) {
    list *head = createList(&(*string)[0]);
    for(int i = 1; (*string)[i] != '\0'; i++)
        head = addList(&(*string)[i], head);
    return head;
}

void reverseString(char (*string)[]) {
    list *head = buildList(string);
    int str_idx = 0;
    while (head != NULL) {
        (*string)[str_idx++] = head->c;
        head = head->next;
    }
}

int main(void) {
    char string[] = "Single List";
    printf("Before:: %s\n", string);
    reverseString(&string);
    printf("After :: %s\n", string);
}
