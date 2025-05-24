#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int vertices;
    struct Node** adjLists;
};

struct Graph* create_graph(int vertices) {

    struct Graph* graph = (Graph*) malloc(sizeof(Graph*));
    graph->vertices = vertices;
    graph->adjLists = (Node**) malloc(sizeof(Node*) * vertices);

    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
    }
    
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {

    struct Node* node = (struct Node*) malloc(sizeof(struct Node*));
    node->data = dest;
    node->next = graph->adjLists[src];
    graph->adjLists[src] = node;

    struct Node* node_undirected = (struct Node*) malloc(sizeof(struct Node*));
    node_undirected->data = src;
    node_undirected->next = graph->adjLists[dest];
    graph->adjLists[dest] = node;

}

struct Node* create_node(int vertex) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node*));
    node->data = vertex;
    node->next = NULL;
    return node;
}

void enqueue(Node** front, Node** rear, int vertex) {
    struct Node* node = create_node(vertex);

    if(*rear == NULL) {
        *front = *rear = node;
        return;
    }

    (*rear)->next = node;
    *rear = node;
}

void dequeue(Node** front, Node** rear, Node** popped) {
    if(*front == NULL) {
        return;
    }
    Node* temp = *front;
    *front = temp->next;
    temp->next = NULL;
    if(*front == NULL) {
        *rear = NULL;
    }
    *popped = create_node(temp->data);
    free(temp);
}

void bfs(Graph* graph, int startVertex) {

    int vertices = graph->vertices;
    bool visited[vertices] = {0};
    
    struct Node* front = NULL;
    struct Node* rear = NULL;

    enqueue(&front, &rear, startVertex);
    visited[startVertex] = 1;

    printf("BFS: ");
    while(front != NULL) {
        Node* popElm = NULL;
        dequeue(&front, &rear, &popElm);
        printf("%d, ", popElm->data);

        Node* adjList = graph->adjLists[popElm->data];
        while (adjList != NULL) {
            if(!visited[adjList->data]) {
                enqueue(&front, &rear, adjList->data);
                visited[adjList->data] = 1;
            }
            adjList = adjList->next;
        }
        

        free(popElm);
    }
    printf("\n");
}

void push(Node** top, int vertex){
    Node* node = create_node(vertex);
    
    if(*top == NULL) {
        *top = node;
        return;
    }
    node->next = *top;
    *top = node;
}

void pop(Node** top, Node** popElm) {
    if(*top == NULL) {
        return;
    }
    
    Node* temp = *top;
    
    *top = (*top)->next;
    
    temp->next = NULL;
    *popElm = create_node(temp->data);

    free(temp);

}

void dfs(Graph* graph, int startVertex) {

    int vertices = graph->vertices;
    bool visited[vertices] = {0};

    struct Node* top = NULL;

    printf("\nDFS: ");
    push(&top, startVertex);

    while(top != NULL) {
        Node* popElm = NULL;
        pop(&top, &popElm);
        if(!visited[popElm->data]) {
            printf("%d, ", popElm->data);
            visited[popElm->data] = 1;
        }

        Node* adjList = graph->adjLists[popElm->data];

        while (adjList != NULL) {
            int v = adjList->data;
            if(!visited[v]) {
                push(&top, v);
            }
            adjList = adjList->next;
        }

        free(popElm);
    }

}

int main() {

    Graph* graph = create_graph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 3);
    
    addEdge(graph, 1, 0);
    addEdge(graph, 1, 4);

    addEdge(graph, 2, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);

    addEdge(graph, 3, 0);
    addEdge(graph, 3, 1);
    addEdge(graph, 3, 2);
    addEdge(graph, 3, 4);
    
    addEdge(graph, 4, 2);
    addEdge(graph, 4, 3);

    bfs(graph, 0);
    bfs(graph, 1);
    bfs(graph, 2);
    bfs(graph, 3);
    bfs(graph, 4);

    dfs(graph, 0);
    dfs(graph, 1);
    dfs(graph, 2);
    dfs(graph, 3);
    dfs(graph, 4);

}