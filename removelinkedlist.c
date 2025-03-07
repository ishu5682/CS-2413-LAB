#include <stdio.h>
#include <stdlib.h>

// Function to remove elements from the linked list
struct ListNode* removeElements(struct ListNode* head, int val) {
    // Remove nodes at the head
    while (head != NULL && head->val == val) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);  
    }

    // If list becomes empty
    if (head == NULL) return NULL;

    // Traverse the list and remove matching nodes
    struct ListNode* current = head;
    while (current->next != NULL) {
        if (current->next->val == val) {
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp);  
        } else {
            current = current->next;
        }
    }
    return head;
}
