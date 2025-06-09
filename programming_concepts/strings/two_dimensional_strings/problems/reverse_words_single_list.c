#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
    char *words;
    struct list *next;
} list;

list *createList(char *data) {
    list *head  = calloc(1, sizeof(list));
    head->words = calloc(1, sizeof(strlen(data + 1)));
    strcpy(head->words, data);
    head->next = NULL;
    return head;
}

list *addList(char *data, list *phead) {
    list *head = createList(data);
    head->next = phead;
    return head;
}

list *buildList(char *obiwan[], int size) {
    list *head = createList(obiwan[0]);
    for(int i = 1; i < size; i++)
        head = addList(obiwan[i], head);
    return head;
}

void printList(list *head) {
    while (head != NULL) {
        printf("%s ", head->words);
        head = head->next;
    }
    printf("\n");
    free(head);
    head = NULL;
}

int main(void) {
    // obi wan :: he is the chosen one
    // yoda    :: one chosen the is he
    char *yoda[] = { "one", "chosen",  "is", "he" };
    printf("size of the array computed to be = %zu / %zu :: %zu\n",
           sizeof(yoda), sizeof(*yoda), sizeof(yoda)/sizeof(*yoda));

    printf("yoda speaks : %s %s %s %s \n", yoda[0], yoda[1], yoda[2], yoda[3]);
    printf("obiwan speaks: "); printList(buildList(yoda, sizeof(yoda)/sizeof(*yoda)));
    return 0;
}
