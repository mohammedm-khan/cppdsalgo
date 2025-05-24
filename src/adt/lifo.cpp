#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

Node* create_node(int value) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

void push(Node** top, int value) {
    Node* node = create_node(value);
    if(*top == NULL) {
        *top = node;
        return;
    }
    node->next = *top;
    *top = node;
}

Node* pop(Node** top) {
    if(*top == NULL) {
        printf("Stack is empty");
        return NULL;
    }
    Node* temp = *top;
    *top = temp->next;
    temp->next = NULL;
    return temp;
}


int main() {

    struct Node* stack = NULL;

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    Node* popNode = pop(&stack);
    if(NULL != popNode) {
        printf("pop: %d\n", popNode->data);
        free(popNode);
    }
    popNode = pop(&stack);
    if(NULL != popNode) {
        printf("pop: %d\n", popNode->data);
        free(popNode);
    }
    popNode = pop(&stack);
    if(NULL != popNode) {
        printf("pop: %d\n", popNode->data);
        free(popNode);
    }
    popNode = pop(&stack);
    if(NULL != popNode) {
        printf("pop: %d\n", popNode->data);
        free(popNode);
    }
    printf("\n");


}