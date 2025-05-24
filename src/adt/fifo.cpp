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

void enqueue(Node** front, Node** rear, int value) {
    
    struct Node* node = create_node(value);

    if(*front == NULL) {
        *front = *rear = node;
        return;
    }
    (*rear)->next = node;
    *rear = node;
}

Node* dequeue(Node** front, Node** rear) {
    if(*front == NULL) {
        printf("Queue is Empty!\n");
        return NULL;
    }
    Node* temp = *front;
    *front = temp->next;
    temp->next = NULL;
    return temp;
}

int main() {

    struct Node* rear = NULL;
    struct Node* front = NULL;

    enqueue(&front, &rear, 10);
    enqueue(&front, &rear, 50);
    enqueue(&front, &rear, 30);
    enqueue(&front, &rear, 20);

    struct Node* node = dequeue(&front, &rear);
    if(node != NULL) {
        printf("Dequeue: %d\n", node->data);
        free(node);
    }
    node = dequeue(&front, &rear);
    if(node != NULL) {
        printf("Dequeue: %d\n", node->data);
        free(node);
    }
    node = dequeue(&front, &rear);
    if(node != NULL) {
        printf("Dequeue: %d\n", node->data);
        free(node);
    }
    node = dequeue(&front, &rear);
    if(node != NULL) {
        printf("Dequeue: %d\n", node->data);
        free(node);
    }
    node = dequeue(&front, &rear);
    
    node = dequeue(&front, &rear);
    

}