#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL; 

struct Node* create_node(int value) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node*));
    node->data = value;
    node->next = NULL;
}

void ins_stack(Node** head, Node* node) {
    if((*head) == NULL) {
        *head = node;
        return;
    }
    node->next = *head;
    *head = node;
}

int pop_stack(Node** head) {
    if(*head == NULL) {
        printf("\nStack is Empty\n");
        return -1;
    }
    Node* temp = *head;
    *head = temp->next;
    int value = temp->data;
    free(temp);
    return value;
}

int main() {


    Node* stack = NULL;


    int elements[] = {4, 3, 17, 14, 8, 18, 17, 9, 21, 12, 10, 7};
    int n = sizeof(elements)/sizeof(int);
    for(int i=0; i < n; i++) {
        ins_stack(&stack, create_node(elements[i]));
    }

    int reverse[n];

    for(int i=0; i < n; i++) {
        reverse[i] = pop_stack(&stack);
    }

    printf("\nElements: ");
    for(int i=0; i < n; i++) {
        printf("%d -> ", elements[i]);
    }

    printf("\nReverse: ");
    for(int i=0; i < n; i++) {
        printf("%d -> ", reverse[i]);
    }
}