#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
};

struct Node* create_treenode(int value) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node*));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct QueueNode* create_queuenode(struct Node* node) {
    struct QueueNode* queuenode = (struct QueueNode*) malloc(sizeof(struct QueueNode*));
    queuenode->treeNode = node;
    queuenode->next = NULL;
}

void ins_queue(QueueNode** front, QueueNode** rear, struct Node* node) {

    QueueNode* queuenode = create_queuenode(node);
    if(*rear == NULL) {
        *front = *rear = queuenode;
    } else {
        (*rear)->next = queuenode;
        *rear = queuenode;

    }
}

Node* de_queue(QueueNode** front, QueueNode** rear) {

    if(*front == NULL) {
        printf("Queue is Empty");
        return NULL;
    }

    struct QueueNode* temp = *front;
    *front = temp->next;
    struct Node* treenode = temp->treeNode;
    free(temp);
    return treenode;
}


void ins_tree(struct Node** root, int data) {

    struct Node* treenode = create_treenode(data);
    if(*root == NULL) {
        *root = treenode;
        return;
    }

    struct QueueNode* front = NULL;
    struct QueueNode* rear = NULL;

    ins_queue(&front, &rear, *root);

    while(front != NULL) {

        struct Node* temp = de_queue(&front, &rear);

        if(temp->left == NULL) {
            temp->left = treenode;
            break;
        } else {
            ins_queue(&front, &rear, temp->left);
        }

        if(temp->right == NULL) {
            temp->right = treenode;
            break;
        } else {
            ins_queue(&front, &rear, temp->right);
        }
    }
    
}