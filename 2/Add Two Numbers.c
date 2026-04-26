#include <stdlib.h>
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int size = sizeof(struct ListNode);
    struct ListNode* dummy = malloc(size);
    struct ListNode* curr = dummy;
    int carry = 0;
    while (l1 || l2 || carry) {
        int sum = carry;
        if (l1) {
            sum += l1->val;
            l1 = l1->next;
            }
        if (l2) {
            sum += l2->val;
            l2 = l2->next;
            }
        carry = sum / 10;
        struct ListNode* newNode = malloc(size);
        newNode->val = sum % 10;
        curr->next = newNode;
        curr = newNode;
        }
    curr->next = NULL;
    return dummy->next;
    }
