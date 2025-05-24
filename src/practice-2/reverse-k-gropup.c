#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};



struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL, *curr = head, *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (head == NULL || k == 1) {
        return head;
    }

    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy;

    while (head) {
        struct ListNode* tail = prev;
        struct ListNode* curr = head;

        // Count k nodes
        for (int i = 0; i < k && curr; i++) {
            curr = curr->next;
        }

        if (curr == NULL) {
            break;
        }

        struct ListNode* next = curr->next;
        curr->next = NULL;

        // Reverse the k nodes
        curr = reverseList(head);

        // Connect the reversed k nodes to the previous group
        tail->next = curr;
        prev = head;
        head = next;
    }

    return dummy->next;
}

// Function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to print the linked list
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    int k = 2;

    printf("Original List: ");
    printList(head);

    head = reverseKGroup(head, k);

    printf("Reversed List: ");
    printList(head);

    return 0;
}