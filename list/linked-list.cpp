#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    Node* next;
};

void add(struct Node** head, int value) {
    
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = value;
    node->next = NULL;

    if(*head == NULL) {
        *head = node;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
}

int size(struct Node** head) {
    int i=1;
    Node* current = *head;
    while (current->next != NULL) {
        i++;
        current = current->next;
    }
    return i;
}

int indexOf(struct Node* head, int value){
    int r = 0;
    Node* temp = head;
    while (temp != NULL) {
        if(temp->data == value){
            return r;
        }
        temp = temp->next;
        r++;
    }
    
    return -1;
}

void print(struct Node* head) {
    struct Node* current = head;
    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("\n");
}

void remove(Node** head, int value) {
    Node* temp = *head;
    Node* prev = NULL;

    while (temp != NULL) {
        if(temp->data == value) {
            Node* next = temp->next;
            free(temp);
            if(prev != NULL) {
                prev->next = next;
            }
            printf("Removed linked list element: %d \n", value);
            return;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
    printf("End of list reached! Can't remove element %d, Element does not exist. \n", value);
}

int main() {
    struct Node* head = NULL;
    add(&head, 20);
    add(&head, 30);
    add(&head, 31);
    add(&head, 10);
    add(&head, 14);
    add(&head, 29);
    add(&head, 26);
    add(&head, 9);
    add(&head, 3);
    add(&head, 5);
    add(&head, 1);


    print(head);

    printf("size: %d \n", size(&head));

    printf("Index of 5: %d \n", indexOf(head, 5));

    remove(&head, 26);
    print(head);

    remove(&head, 26);
    print(head);

    remove(&head, 3);
    print(head);

    remove(&head, 14);
    print(head);

    remove(&head, 10);
    print(head);

    remove(&head, 31);
    print(head);
}

