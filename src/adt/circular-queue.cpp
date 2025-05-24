#include <stdio.h>
#include <stdlib.h>

void enqueue(char queue[], int MAX, int* front, int* rear, char val) {

    if(*rear == MAX - 1 and *front == 0) {
        printf("Queue is Full! No more elements allowed.\n");
    } else if(*front == -1 and *rear == -1) {
        *front = *rear = 0;
    } else if(*front > 0 and *rear == MAX - 1) {
        *rear = 0;
    } else {
        *rear = *rear + 1;
    }
    queue[*rear] = val;
}

char dequeue(char queue[], int MAX, int* front, int* rear) {

    if(*front == -1) {
        printf("\nQueue is Empty!");
        return '\0';
    } 
    char r = queue[*front];
    if(*front == *rear) {
        *front = *rear = -1;
    } else {
        if(*front == MAX - 1) {
            *front = 0;
        } else {
            *front = *front + 1;
        }
    }
    return r;
}


int main() {
    int MAX=10;
    int front=-1,rear=-1;

    char queue[MAX];

    for(int i=0; i<MAX;i++) {
        enqueue(queue, MAX, &front, &rear, i + 97);
    }
    for(int i=0; i<MAX-5; i++) {
        printf("%c ", dequeue(queue, MAX, &front, &rear));
    }
    for(int i=0; i<MAX-4; i++) {
        enqueue(queue, MAX, &front, &rear, i + 107);
    }
    printf("\n");
    for(int i=0; i<MAX;i++) {
        printf("%c ", queue[i]);
    }
    printf("\n");
    for(int i=0; i<MAX; i++) {
        printf("%c ", dequeue(queue, MAX, &front, &rear));
    }
    printf("\n");
}
