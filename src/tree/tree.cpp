#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
};


int main() {

    struct Node* tree;

    int elements[] = {4, 3, 17, 14, 8, 18, 17, 9, 21, 10, 12, 7};
    int n = sizeof(elements)/sizeof(int);

    tree = (struct Node*) malloc(sizeof(Node*) * n);

    for(int i=0; i<n; i++) {
        Node* elm = &tree[i];
        elm->data = elements[i];
    }

    for(int i=0; i< n; i++) {
        Node* elm = &tree[i];
        printf("%d -> ",elm->data);
    }

    for(int i=0; i< n; i++) {
        Node* elm = &tree[i];
        printf("\nRelationship of Node %d at index %d:", elm->data, i);
        int parent = (i - 1)/2;
        int lchild = 2*i + 1;
        int rchild = 2*i + 2;
        Node* parentElm = &tree[parent];
        Node* lchildElm = &tree[lchild];
        Node* rchildElm = &tree[rchild];
        printf("\nParent: %d at %d", parentElm->data, parent);
        printf("\nLeft Child: %d at %d", lchildElm->data, lchild);
        printf("\nRight Child: %d at %d", rchildElm->data, rchild);
        printf("\n");
    }

    printf("\n\n\n");
}