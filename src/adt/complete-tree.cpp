#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int data;
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
};

struct TreeNode* createTreeNode(int value) {
    struct TreeNode* treeNode = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    treeNode->data = value;
    treeNode->leftChild = NULL;
    treeNode->rightChild = NULL;
    return treeNode; 
}

struct Node {
    struct TreeNode* data;
    struct Node* next;
};

struct Node* createNode(struct TreeNode** treeNode) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = *treeNode;
    node->next = NULL;
    return node;
}

void enqueue(Node** front, Node** rear, struct TreeNode** treeNode) {

    struct Node* node = createNode(treeNode);
    if(*front == NULL) {
        *front = *rear = node;
        return;
    }

    (*rear)->next = node;
    *rear = node;

}

struct TreeNode* dequeue(Node** front) {

    if(*front == NULL) {
        printf("Queue is Empty!\n");
        return NULL;
    }
    struct Node* temp = *front;
    *front = (*front)->next;
    struct TreeNode* treeNode = temp->data;
    //temp->data = NULL;
    temp->next = NULL;
    free(temp); 
    return treeNode;

}

void insertCompleteTree(struct TreeNode** root, int data) {
    
    struct TreeNode* treeNode = createTreeNode(data);
    if(*root == NULL) {
        *root = treeNode;
        return;
    }

    struct Node* front = NULL;
    struct Node* rear = NULL;

    enqueue(&front, &rear, root);

    while(front != NULL) {
        TreeNode* tnode = dequeue(&front);
        if(tnode->leftChild == NULL) {
            tnode->leftChild = treeNode;
            break;
        } else {
            enqueue(&front, &rear, &(tnode->leftChild));
        }

        if(tnode->rightChild == NULL) {
            tnode->rightChild = treeNode;
            break;
        } else {
            enqueue(&front, &rear, &(tnode->rightChild));
        }


    }

    while(front != NULL) {
        dequeue(&front);
    }

}

void freeTree(struct TreeNode* root) {
    TreeNode* leftSubTree = root->leftChild;
    TreeNode* rightSubTree = root->rightChild;
    if(leftSubTree != NULL) {
        freeTree(leftSubTree);
    }
    if(rightSubTree != NULL) {
        freeTree(rightSubTree);
    }
    free(root);
    
}

void inorderTraversal(struct TreeNode** root) {

    if(*root == NULL) {
        return;
    }
    inorderTraversal(&(*root)->leftChild);
    printf("%d ->", (*root)->data);
    inorderTraversal(&(*root)->rightChild);
}

void preOrderTraversal(struct TreeNode** root) {

    if(*root == NULL) {
        return;
    }
    printf("%d ->", (*root)->data);
    preOrderTraversal(&(*root)->leftChild);
    preOrderTraversal(&(*root)->rightChild);
}

void postOrderTraversal(struct TreeNode** root) {

    if(*root == NULL) {
        return;
    }
    postOrderTraversal(&(*root)->leftChild);
    postOrderTraversal(&(*root)->rightChild);
    printf("%d ->", (*root)->data);
}

int main() {


    struct TreeNode* root = NULL;

    insertCompleteTree(&root, 10);
    insertCompleteTree(&root, 20);
    insertCompleteTree(&root, 30);
    insertCompleteTree(&root, 40);
    insertCompleteTree(&root, 50);
    insertCompleteTree(&root, 60);
    insertCompleteTree(&root, 70);
    insertCompleteTree(&root, 80);
    insertCompleteTree(&root, 90);
    insertCompleteTree(&root, 100);
    insertCompleteTree(&root, 110);
    insertCompleteTree(&root, 120);

    printf("\n Inorder Traversal\n");
    inorderTraversal(&root);

    printf("\n Preorder Traversal\n");
    preOrderTraversal(&root);

    printf("\n Post Order Traversal\n");
    postOrderTraversal(&root);

    freeTree(root);
    printf("\n");
}

