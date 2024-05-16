#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char arr[10];
    struct node *next;
    int numbers;
};

void printArray(struct node *head);
void addOnEnd(struct node *head);
void deleteLast(struct node *head);
void insertIntoArray(struct node *head, int x, int index);

int main(void){

    int number_of_people;
    printf("Insert number of people you want to add:");
    scanf("%d", &number_of_people);

    struct node *head = NULL;
    struct node *helper;
    for(int i = 0; i < number_of_people; i++){
        if(i == 0){
            head = (struct node*)malloc(sizeof(struct node));
            helper = head;
        }
        else{
            helper->next = (struct node*)malloc(sizeof(struct node));
            helper = helper->next;
        }
        printf("Insert name of person number %d:\n", i + 1);
        scanf_s("%20s", helper->arr);
        helper->next = NULL;
    }

    printArray(head);
    addOnEnd(head);
    printArray(head);

    while(head != NULL){
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}

void printArray(struct node *head){
    struct node *helper;
    helper = head;
    while(helper != NULL){
        printf("%s\n", helper->arr);
        helper = helper->next;
    }
}

void addOnEnd(struct node *head){
    struct node *helper;
    helper = head;
    while(helper->next != NULL){
        helper = helper->next;
    }

    struct node *helper2;
    helper2 = (struct node*) malloc(sizeof(struct node));
    printf("Unesi zadnjega:\n");
    scanf("%20s", helper2->arr);
    helper2->next = NULL;
    helper->next = helper2;
}

void deleteLast(struct node *head){
    //kreiramo privremeni cvor
    struct node *temp1 = (struct node*) malloc(sizeof(struct node));
    temp1 = head;
    struct node *old_temp = (struct node*) malloc(sizeof(struct node));

    while(temp1->next != NULL){
        old_temp = temp1;
        temp1 = temp1->next;
    }

    old_temp->next = NULL;
    free(temp1);
}

void insertIntoArray(struct node *head, int x, int index){
    struct node *new = (struct node*) malloc(sizeof(struct node));
    struct node *temp = head;

    int addition = 1;
    new->numbers = x;

    if(index == 1){
        new->next = head->next;
        head->next = new;
    }
    else{
        while(temp->next != NULL){
            if(addition == index){
                new->next = temp->next;
                temp->next = new;
                break;
            }else{
                temp = temp->next;
                addition++;
            }
        }
    }
}
