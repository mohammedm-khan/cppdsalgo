#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    Node* next;
};

struct Stack {
    Node* top;
    int count;
};


void initialize(Stack* stack) {
    stack->top = NULL;
    stack->count = 0;
}

void push(Stack* stack, int value) {
    struct Node* node = (struct Node*) malloc(sizeof(Node*));
    node->data = value;

    node->next = stack->top;

    stack->top = node;
    stack->count++;
}

int pop(Stack* stack) {
    if(stack->top == NULL) {
        printf("\nStack is Empty\n\n");
        return -1;
    }
    Node* temp = stack->top;

    int value = temp->data;
    stack->top = temp->next;
    stack->count--;
    free(temp);
    printf("\nPopped an element from stack: %d \n", value);
    return value;
}

void display(Stack* stack) {
    Node* temp = stack->top;
    if(temp != NULL) {
        printf("\n%d <- Top \n", temp->data);
    
        while (temp->next != NULL) {
            temp = temp->next;
            printf("%d \n", temp->data);
        }
        printf("\n");
    }
}

int main() {

    Stack stack;
    initialize(&stack);

    display(&stack);

    push(&stack, 12);
    display(&stack);

    push(&stack, 8);
    display(&stack);

    push(&stack, 9);
    push(&stack, 10);
    push(&stack, 7);
    push(&stack, 26);
    push(&stack, 4);
    display(&stack);

    for(int i=1; i<500; i++) {
        push(&stack, 14*i);
        
    }
    display(&stack);
    int data = -1;
    do {
        data = pop(&stack);
        display(&stack);
    } while (data != -1);
    
}