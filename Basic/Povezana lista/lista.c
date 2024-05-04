#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char arr[10];
    struct node *next;
};

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

    helper = head;
    while(helper != NULL){
        printf("%s\n", helper->arr);
        helper = helper->next;
    }

    while(head != NULL){
        struct node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}