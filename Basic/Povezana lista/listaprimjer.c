#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main(void){

    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 5;
    head->next = NULL;

    printf("%d\n", head->data);

    free(head);
    return 0;
}