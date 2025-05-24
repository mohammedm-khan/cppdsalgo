#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL) {
        return list2;
    }
    if (list2 == NULL) {
        return list1;
    }

    struct ListNode* mergedHead = NULL;
    if (list1->val <= list2->val) {
        mergedHead = list1;
        list1 = list1->next;
    } else {
        mergedHead = list2;
        list2 = list2->next;
    }

    struct ListNode* mergedTail = mergedHead;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            mergedTail->next = list1;
            list1 = list1->next;
        } else {
            mergedTail->next = list2;
            list2 = list2->next;
        }
        mergedTail = mergedTail->next;
    }

    if (list1 != NULL) {
        mergedTail->next = list1;
    } else if (list2 != NULL) {
        mergedTail->next = list2;
    }

    return mergedHead;
}

// Function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}


struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0) {
        return NULL;
    }

    while (listsSize > 1) {
        int i = 0;
        for (int j = 0; j < listsSize - 1; j += 2) {
            lists[i++] = mergeTwoLists(lists[j], lists[j + 1]);
        }
        listsSize = (listsSize + 1) / 2;
    }

    return lists[0];
}

int main() {
    // Create the k sorted linked lists
    struct ListNode* list1 = newNode(1);
    list1->next = newNode(4);
    list1->next->next = newNode(5);

    struct ListNode* list2 = newNode(1);
    list2->next = newNode(3);
    list2->next->next = newNode(4);

    struct ListNode* list3 = newNode(2);
    list3->next = newNode(6);

    struct ListNode** lists = (struct ListNode**)malloc(3 * sizeof(struct ListNode*));
    lists[0] = list1;
    lists[1] = list2;
    lists[2] = list3;

    int listsSize = 3;

    struct ListNode* mergedList = mergeKLists(lists, listsSize);

    // Print the merged list
    while (mergedList != NULL) {
        printf("%d ", mergedList->val);
        mergedList = mergedList->next;
    }
    printf("\n");

    return 0;
}