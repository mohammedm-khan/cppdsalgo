#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* create_node(int value) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    return node;
}

void enqueue(Node** front, Node** rear, int value) {
    struct Node* node = create_node(value);
    if(*rear == NULL) {
        *front = *rear = node;
        return;
    }
    (*rear)->next = node;
    *rear = node;
}

int dequeue(Node** front, Node** rear) {
    if(*front == NULL) {
        return -1;
    }
    struct Node* temp = *front;
    *front = temp->next;
    if (*front == NULL) {
        *rear = NULL;
    }
    //temp->next = NULL;
    int value = temp->data;
    free(temp);
    return value;
}

void bfs(int *adjMatrix, int n, int startVertex) {

    struct Node* front = NULL;
    struct Node* rear = NULL;
    bool visited[n] = {0};
    

    
    enqueue(&front, &rear, startVertex);
    visited[startVertex] = 1;
    printf("BFS: ");
    while(front != NULL) {
        int v = dequeue(&front, &rear);
        printf("%d, ", v);
        for(int j=0; j<n; j++) {
            int edge = *(adjMatrix + v * n + j);
            if(edge == 1 && !visited[j]) {
                enqueue(&front, &rear, j);
                visited[j] = 1;
            }
        }
    }
    printf("\n");
}

int main() {

    int n = 5;
    int arr[][n] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 1, 1, 0}
    };
    bfs((int *)arr, n, 3);
}