#include <stdio.h>
#include <stdlib.h>


struct Node {
    Node* lchild;
    int data;
    Node* rchild;
};

struct QueueNode {
    Node* data;
    QueueNode* next;
};

struct Queue {
    QueueNode* rear;
    QueueNode* front;
};


void insert_queue(Queue* queue, Node* data) {

    QueueNode* node = (struct QueueNode*) malloc(sizeof(struct QueueNode*));
    node->data = data;

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

QueueNode* de_queue(Queue* queue) {
    if(queue->front == NULL) {
        printf("\nQueue is Empty! Can't delete an element\n");
        return NULL;
    }
    struct QueueNode* temp = queue->front;
    queue->front = temp->next;
    temp->next = NULL;
    //free(temp);
    return temp;
}

int elements[] = {4, 3, 17, 14, 8, 18, 17, 9, 21, 12, 10, 7};

Queue* queue = (Queue*) malloc(sizeof(Queue*));

void initialize_queue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}



void insert_tree(Node** tree, int value) {

    if(*tree == NULL) {
        Node* node = (Node*) malloc(sizeof(Node*));
        node->lchild = NULL;
        node->data = value;
        node->rchild = NULL;

        *tree = node;
        insert_queue(queue, node);
        return;
    }

    QueueNode* queuenode = de_queue(queue);
    Node* root = queuenode->data;
    if (root->lchild == NULL) {
        insert_queue(queue, root);
        insert_tree(&root->lchild, value);
    } else if (root->rchild == NULL) {
        insert_tree(&root->rchild, value);
    }
    free(queuenode);
}

int main() {

    int n = sizeof(elements) / sizeof(int);
    
    initialize_queue(queue);

    Node* tree = NULL;
    insert_tree(&tree, 3);
    insert_tree(&tree, 4);
    insert_tree(&tree, 17);
    insert_tree(&tree, 14);
    insert_tree(&tree, 8);
    insert_tree(&tree, 18);
    insert_tree(&tree, 10);
    insert_tree(&tree, 9);
    insert_tree(&tree, 21);
    insert_tree(&tree, 12);
    insert_tree(&tree, 7);
    insert_tree(&tree, 26);

    printf("\n %d", tree->data);

    QueueNode* temp = de_queue(queue);

    for(;temp != NULL;) {
        printf("\n%d", temp->data->data);
        temp = de_queue(queue);
    }

    
    
}