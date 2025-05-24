#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void push(char stack[], int n, int* top, char val) {

    if(*top == n) {
        printf("stack is full");
        return;
    }
    *top = *top + 1;
    stack[*top] = val;
}

char pop(char stack[], int* top) {
    char r = stack[*top];
    *top = *top - 1;
    return r;
}

int main() {

    char seq1[] = "newstring";

    int n = strlen(seq1);

    char stack[n];

    int top = -1;

    for(int i=0; seq1[i]!='\0'; i++) {
        printf("%c", seq1[i]);
        push(stack, n , &top, seq1[i]);
    }
    printf("\n");

    int j=0;
    while(top != -1) {
        seq1[j] = pop(stack, &top);
        j++;
    }

    for(int i=0; seq1[i]!='\0'; i++) {
        printf("%c", seq1[i]);
    }
    printf("\n");


}