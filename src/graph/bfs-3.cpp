#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* create_node(int value) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data =  value;
    node->next = NULL;
    return node;
}

struct Node* adjList(int* arr, int vertex) {
    int size = sizeof(arr) / sizeof(arr[0]);
    struct Node* node = create_node(vertex);
    
    struct Node* temp = node;
    for(int i=0; i<size; i++) {
        temp->next = create_node(arr[i]);
        temp = temp->next;
    }
    return node;
}

int main() {

    int n = 5;
    struct Node** list = (struct Node**) malloc(sizeof(struct Node*) * n);
    
    int vert0[] = {1, 3};
    Node* list0 = adjList(vert0, 0);

    int vert1[] = {0, 2, 3};
    Node* list1 = adjList(vert1, 1);

    int vert2[] = {1, 3};
    Node* list2 = adjList(vert2, 2);

    int vert3[] = {0, 2, 3};
    Node* list3 = adjList(vert3, 3);

    int vert4[] = {0, 2, 3};
    Node* list4 = adjList(vert4, 4);


    list[0] = list0;
    list[1] = list1;
    list[2] = list2;
    list[3] = list3;
    list[4] = list4;
    
    //struct Node** list = {list0, list1, list2, list3, list4};

    for(int i=0; i<n; i++) {
        struct Node* adjList = list[i];
        
        printf("Adjacent vertices of: %d\n", adjList->data);
        struct Node* temp = adjList->next;
        while(temp != NULL) {
            printf("Vertex: %d\n", temp->data);
            temp = temp->next;
        }
    }

}