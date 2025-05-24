#include <stdio.h>
#include <stdlib.h>


struct Node {
    struct Node* left;
    int data;
    struct Node* right;
};

struct Node* createTree(int value) {
    struct Node* node = (struct Node* ) malloc(sizeof(struct Node* ));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
}


void insert(Node** tree, int value) {
    if(*tree == NULL) {
        *tree = createTree(value);
        return;
    }
    Node* root = *tree;
    if(value <= root->data) {
        insert(&(root->left), value);
        return;
    }
    insert(&(root->right), value);
}

Node* findLargest(Node** tree) {
    return *tree;
}

void deleteNode(Node** tree, int value) {
    if(*tree == NULL) {
        printf("\nTree is empty! Can't delete\n\n");
        return;
    }

    if(value < (*tree)->data) {
        deleteNode(&(*tree)->left, value);
    } else if(value > (*tree)->data) {
        deleteNode(&(*tree)->right, value);
    } else if((*tree)->left != NULL && (*tree)->right != NULL) {
        Node* temp = findLargest(&(*tree)->left);
        (*tree)->data = temp->data;
        deleteNode(&(*tree)->left, temp->data);
    } else {
        Node* temp = (*tree);
        if((*tree)->left == NULL && (*tree)->right == NULL) {
            (*tree) = NULL;
        } else if((*tree)->left != NULL){
            (*tree) = (*tree)->left;
        } else {
            (*tree) = (*tree)->right;
        }
        free(temp);
    }
    
}

int height(Node* tree) {
    if(tree == NULL) {
        return 0;
    }

    int leftHeight = height(tree->left);
    int rightHeight = height(tree->right);

    if(leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

int totalNodes(Node* tree) {
    if(tree == NULL) {
        return 0;
    }
    return totalNodes(tree->left) + totalNodes(tree->right) + 1;
}

int totalInternalNodes(Node* tree) {
    if(tree == NULL) {
        return 0;
    }
    if(tree->left == NULL && tree->right == NULL) {
        return 0;
    }
    return totalInternalNodes(tree->left) + totalInternalNodes(tree->right) + 1;
}

int leafNodes(Node* tree) {
    if(tree == NULL) {
        return 0;
    }
    if(tree->left == NULL && tree->right == NULL) {
        return 1;
    }
    return leafNodes(tree->left) + leafNodes(tree->right);
}

Node* findSmallestNode(Node* tree) {

    if(tree == NULL || tree->left == NULL) {
        return tree;
    }
    return findSmallestNode(tree->left);
}

void deleteTree(Node* tree) {
    if(tree != NULL) {
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
    }
}

int main() {
    struct Node* tree = NULL;

    insert(&tree, 4);
    insert(&tree, 3);
    insert(&tree, 17);
    insert(&tree, 14);
    insert(&tree, 8);
    insert(&tree, 18);

    printf("\nHeight: %d\n", height(tree));
    printf("\nNodes: %d\n", totalNodes(tree));
    printf("\nInternal Nodes: %d\n", totalInternalNodes(tree));
    printf("\nLeaf Nodes: %d\n", leafNodes(tree));
    Node* small = findSmallestNode(tree);
    printf("\nSmalest value: %d\n", small->data);

    deleteTree(tree);

    deleteNode(&tree, 14);
    deleteNode(&tree, 3);
    deleteNode(&tree, 18);
    deleteNode(&tree, 4);
    printf("\nHeight: %d\n", height(tree));
    deleteNode(&tree, 17);
    deleteNode(&tree, 8);
    printf("\nHeight: %d\n", height(tree));
    deleteNode(&tree, 1);
    printf("\nHeight: %d\n", height(tree));

}