#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node* next;
};

struct Node* createNode(char val) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node*));
    node->data = val;
}

void push(struct Node** top, char val) {
    
    struct Node* node = createNode(val);
    if(*top == NULL) {
        *top = node;
        return;
    }
    struct Node* temp = *top;
    temp->next = node;
    *top = node;
}

char pop(struct Node** top) {
    if(*top == NULL) {
        return '\0';
    }
    struct Node* temp = *top;
    *top = temp->next;
    temp->next = NULL;
    char r = temp->data;
    free(temp);
    return r;
}

int isMatchingPair(char character1, char character2) {
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else
        return 0;
}


bool isValid(char* exp) {
    int i;
    struct Node* top = NULL;

    for (i = 0; exp[i]; ++i) {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
            push(&top, exp[i]);
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}') {
            if (top == NULL)
                return 0;
            else if (!isMatchingPair(pop(&top), exp[i]))
                return 0;
        }
    }
    return top == NULL;
}

int main() {

    char* exp = "([]){}";

    if (isValid(exp))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;

}