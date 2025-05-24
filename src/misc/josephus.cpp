#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* node = (struct Node* ) malloc(sizeof(struct Node* ));
    node->data = value;
    node->next = NULL;
}

int main() {

    int n = 5;


    Node* start = createNode(1);

    Node* temp = start;
    for(int i=2; i<=n; i++) {
        Node* node = createNode(i);
        temp->next = node;
        node->next = start;
        temp = node;
    }

    int k = 2;

    

    /* printf("\n");
    temp = start;
    for(int i=0; i<10000; i++) {
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("\n"); */
}