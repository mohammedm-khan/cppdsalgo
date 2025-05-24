#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // For bool type

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Stack structure (simple implementation)
#define MAX_STACK_SIZE 1000 // Adjust as needed
struct Stack {
    struct TreeNode* data[MAX_STACK_SIZE];
    int top;
};

void stack_init(struct Stack* s) {
    s->top = -1;
}

bool stack_is_empty(struct Stack* s) {
    return s->top == -1;
}

void stack_push(struct Stack* s, struct TreeNode* node) {
    if (s->top >= MAX_STACK_SIZE - 1) {
        fprintf(stderr, "Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->data[++s->top] = node;
}

struct TreeNode* stack_pop(struct Stack* s) {
    if (stack_is_empty(s)) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->data[s->top--];
}

// Iterative inorder traversal
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int capacity = 100; // Initial capacity. Adjust if needed.
    int* result = (int*)malloc(sizeof(int) * capacity);
    if (result == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    int index = 0;

    struct Stack stack;
    stack_init(&stack);
    struct TreeNode* current = root;

    while (current != NULL || !stack_is_empty(&stack)) {
        while (current != NULL) {
            stack_push(&stack, current);
            current = current->left;
        }
        current = stack_pop(&stack);
        result[index++] = current->val;
        current = current->right;
    }

    result = (int*)realloc(result, sizeof(int) * index); // Resize to actual size
    if(result == NULL && index > 0){
        perror("Memory reallocation failed");
        exit(EXIT_FAILURE);
    }
    *returnSize = index;
    return result;
}

// Helper function to create a new node (same as before)
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // Example usage (same as before)
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int returnSize;
    int* inorder = inorderTraversal(root, &returnSize);

    printf("Inorder traversal: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", inorder[i]);
    }
    printf("\n");

    free(inorder);
    //Free tree nodes
    free(root->left->right);
    free(root->left->left);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}