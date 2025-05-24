#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


struct Node {
    char data;
    struct Node* next;
};



void push(struct Node** head, char value) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node**));
    node->data = value;
    node->next = NULL;

    if(*head == NULL) {
        *head = node;
        return;
    }

    node->next = *head;
    *head = node;
}

char peek(struct Node** head) {
    if(*head == NULL) {
        printf("Stack is empty");
        return '\0';
    }
    char value = (*head)->data;
    return value;
}

char pop(struct Node** head) {
    if(*head == NULL) {
        printf("Stack is empty");
        return '\0';
    }
    Node* temp = *head;
    *head = temp->next;
    char value = temp->data;
    free(temp);
    return value;
}

// Function to determine the precedence of operators
int precedence(char ch) {
    switch (ch) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

// Check if a character is an operator
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

// Function to convert infix expression to postfix expression
void infixToPostfix(char infix[], char postfix[]) {
    struct Node* head = NULL ;
    int i, j = 0;
    
    for (i = 0; infix[i] != '\0'; i++) {
        // If the character is an operand, add it to the postfix expression
        if (isalnum(infix[i])) {
            postfix[j++] = infix[i];
        }
        // If the character is '(', push it onto the stack
        else if (infix[i] == '(') {
            push(&head, infix[i]);
        }
        // If the character is ')', pop and output from the stack until '(' is found
        else if (infix[i] == ')') {
            while (head != NULL && peek(&head) != '(') {
                postfix[j++] = pop(&head);
            }
            pop(&head);  // Pop '(' from the stack
        }
        // If the character is an operator
        else if (isOperator(infix[i])) {
            while (head != NULL && precedence(peek(&head)) >= precedence(infix[i])) {
                postfix[j++] = pop(&head);
            }
            push(&head, infix[i]);
        }
    }

    // Pop all remaining operators from the stack
    while (head != NULL) {
        postfix[j++] = pop(&head);
    }

    postfix[j] = '\0';  // Null-terminate the postfix expression
}


int main() {
    char infix[100] = "a - ((b * c) + d) / a", postfix[100];

    printf("Enter infix expression: ");
    //scanf("%s", infix);
    
    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}