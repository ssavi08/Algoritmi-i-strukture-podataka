#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int number;
    struct Node* next;
} Node;

typedef struct stack{
    Node* top_element;
} Stack;

void initialize(Stack* stack){
    stack-> top_element = NULL;
}

bool isEmpty(Stack* stack){
    return stack-> top_element == NULL;
}

void push(Stack* stack, int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->number = value;
    newNode->next = NULL;

    if (isEmpty(stack))
    {
        stack-> top_element = newNode;
    }
    else
    {
        newNode->next = stack->top_element;
        stack-> top_element = newNode;
    }

    printf("The stack has pushed element %d into the stack.\n", value);
}
int pop(Stack* stack){
    if (isEmpty(stack))
    {
        printf("The stack is underflow, it cannot pop element from an empty stack.\n");
        return -1; // returns a sentinel value or deals with an error uniquely
    }
    else
    {
        Node* temp = stack->top_element;
        int value = temp->number;
        stack-> top_element = temp->next;
        free(temp);
        printf("The stack has popped element %d from the stack.\n", value);
        return value;
    }
}
int peek(Stack* stack){
    if (isEmpty(stack))
    {
        printf("The stack is empty.\n");
        return -1;
    }
    else
    {
        return stack->top_element->number;
    }
}

int main(){
    Stack stack;
    initialize(&stack);

    push(&stack, 5);
    push(&stack, 10);
    push(&stack, 20);

    printf("The top element of the stack is %d\n", peek(&stack));

    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack); // these commands pop out from an empty stack

    return 0;
}