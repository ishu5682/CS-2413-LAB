#include <stdio.h>
#include <stdlib.h>

// Function to reverse the linked list iteratively
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *nextNode, *prevNode = NULL;
    while (head != NULL) {
        nextNode = head->next;
        head->next = prevNode;
        prevNode = head;
        head = nextNode;
    }
    return prevNode;
}

// Function to print the linked list
void printList(struct ListNode* node) {
    while (node != NULL) {
        printf("%d -> ", node->val);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (new_node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}


