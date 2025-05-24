#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct QueueNode {
    struct Node* treeNode;
    struct QueueNode* next;
};


// Function to create a new tree node
struct Node* createTreeNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a new queue node
struct QueueNode* createQueueNode(struct Node* treeNode) {
    struct QueueNode* newQueueNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newQueueNode->treeNode = treeNode;
    newQueueNode->next = NULL;
    return newQueueNode;
}

// Function to remove a tree node from the queue
struct Node* dequeue(struct QueueNode** front, struct QueueNode** rear) {
    if (*front == NULL) {
        return NULL;
    }
    struct QueueNode* temp = *front;
    struct Node* treeNode = temp->treeNode;
    *front = (*front)->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    free(temp);
    return treeNode;
}

// Function to insert a tree node into the queue
void enqueue(struct QueueNode** front, struct QueueNode** rear, struct Node* treeNode) {
    struct QueueNode* newQueueNode = createQueueNode(treeNode);
    if (*rear == NULL) {
        *front = *rear = newQueueNode;
    } else {
        (*rear)->next = newQueueNode;
        *rear = newQueueNode;
    }
}

// Function to insert a node in a complete binary tree
void insert(struct Node** root, int data) {
    struct Node* newNode = createTreeNode(data);

    // If tree is empty, assign new node as root
    if (*root == NULL) {
        *root = newNode;
        return;
    }

    // Use a queue to perform level-order traversal
    struct QueueNode* front = NULL;
    struct QueueNode* rear = NULL;
    enqueue(&front, &rear, *root);

    while (front != NULL) {
        struct Node* temp = dequeue(&front, &rear);

        // If the left child is empty, insert the new node as the left child
        if (temp->left == NULL) {
            temp->left = newNode;
            break;
        } else {
            enqueue(&front, &rear, temp->left);
        }

        // If the right child is empty, insert the new node as the right child
        if (temp->right == NULL) {
            temp->right = newNode;
            break;
        } else {
            enqueue(&front, &rear, temp->right);
        }
    }
}

// Function to perform an in-order traversal of the binary tree
void inorderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("%d ->", root->data);
    inorderTraversal(root->right);
}

int main() {
    struct Node* root = NULL;

    // Insert elements into the complete binary tree
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 40);
    insert(&root, 50);
    insert(&root, 60);
    insert(&root, 70);

    // Perform in-order traversal to check the tree structure
    printf("In-order Traversal: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}