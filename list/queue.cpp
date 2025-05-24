#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void initialize(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    printf("\n\n");
}

void add(struct Queue* queue, int value) {

    struct Node* node = (struct Node*) malloc(sizeof(struct Node*));
    node->data = value;
    node->next = NULL;

    if(queue->front == NULL) {
        queue->front = node;
        queue->rear = node;
        queue->front->next = queue->rear->next = NULL;
    } else {
        queue->rear->next = node;
        queue->rear = node;
        queue->rear->next = NULL;
    }
}

int deleteElm(Queue* queue) {
    if(queue->front == NULL) {
        printf("\nQueue is Empty! Can't delete an element\n");
        return -1;
    }
    struct Node* temp = queue->front;
    queue->front = temp->next;
    temp->next = NULL;
    int value = temp->data;
    free(temp);
    return value;
}

void printQueue(struct Queue* queue) {
    int i=0;
    if(queue->front == NULL) {
        printf("\nQueue is Empty \n");
        return;
    }
    struct Node* temp = queue->front;
    while(temp != NULL) {
        printf("%d <- ", temp->data);
        temp = temp->next;
        i++;
    }
    printf("\n");
    printf("^_ Front ");
    for (int j = 3; j < i; j++) {
        printf("    ");
        if(j % 3 == 0) {
            printf("      ");
        }
    }
    printf("^_ Rear");
    printf("\n");
}

int main() {
    Queue queue;
    initialize(&queue);

    add(&queue, 12);
    add(&queue, 8);
    add(&queue, 9);
    add(&queue, 7);
    add(&queue, 10);
    add(&queue, 3);
    printQueue(&queue);

    add(&queue, 12);
    add(&queue, 8);
    add(&queue, 9);
    add(&queue, 7);
    add(&queue, 10);
    add(&queue, 3);


    printQueue(&queue);

    printf("\nDeleting An element from queue. Elm: %d \n", deleteElm(&queue));
    printQueue(&queue);
    printf("\nDeleting An element from queue. Elm: %d \n", deleteElm(&queue));
    printQueue(&queue);
    printf("\nDeleting An element from queue. Elm: %d \n", deleteElm(&queue));
    printQueue(&queue);
    printf("\nDeleting An element from queue. Elm: %d \n", deleteElm(&queue));
    printQueue(&queue);
    printf("\nDeleting An element from queue. Elm: %d \n", deleteElm(&queue));
    printQueue(&queue);
    printf("\nDeleting An element from queue. Elm: %d \n", deleteElm(&queue));
    printQueue(&queue);
    printf("\nDeleting An element from queue. Elm: %d \n", deleteElm(&queue));
    printQueue(&queue);

    printf("\nDeleting An element from queue. Elm: %d \n", deleteElm(&queue));
    printQueue(&queue);
    printf("\nDeleting An element from queue. Elm: %d \n", deleteElm(&queue));
    printQueue(&queue);
    printf("\nDeleting An element from queue. Elm: %d \n", deleteElm(&queue));
    printQueue(&queue);
    printf("\nDeleting An element from queue. Elm: %d \n", deleteElm(&queue));
    printQueue(&queue);
    printf("\nDeleting An element from queue. Elm: %d \n", deleteElm(&queue));
    printQueue(&queue);

    printf("\nDeleting An element from queue. Elm: %d \n", deleteElm(&queue));
    printQueue(&queue);
    
    add(&queue, 12);
    printQueue(&queue);
    add(&queue, 8);
    printQueue(&queue);
    add(&queue, 9);
    printQueue(&queue);
    add(&queue, 7);
    printQueue(&queue);
    add(&queue, 10);
    printQueue(&queue);
    add(&queue, 3);
    printQueue(&queue);
    
}

