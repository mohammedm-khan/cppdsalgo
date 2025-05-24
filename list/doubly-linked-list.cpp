#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    Node* next;
    Node* prev;
};


void add(Node** head, int value) {

    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;
    node->prev = NULL;

    if(*head == NULL) {
        *head = node;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
        node->prev = temp;
    }
}

void remove(Node** head, int index) {

     if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = *head;

    if(index == 0) {
        *head = temp->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
        int value = temp->data;
        free(temp);
        printf("Element %d at index %d has been removed.\n", value, index);
        return;
    }
    
    for(int i=0; temp != NULL && i<index; i++){
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Index out of range, for index %d \n", index);
        return;
    }

     if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    int value = temp->data;
    free(temp);
    printf("Element %d at index %d has been removed.\n", value, index);
}

void print(struct Node* head) {
    printf("DoublyLinkedList: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}




int main() {
    printf("\n");
    Node* head = NULL;


    add(&head, 12);
    add(&head, 8);
    add(&head, 91);
    add(&head, 7);
    add(&head, 90);
    print(head);

    remove(&head, 0);
    print(head);

    remove(&head, 4);
    print(head);

    remove(&head, 3);
    print(head);

    remove(&head, 0);
    print(head);

    remove(&head, 0);
    print(head);

    remove(&head, 0);
    print(head);

    remove(&head, 0);
    print(head);

    printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");printf("\n");
}
