#include "leet.h"
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *curr = head;
        ListNode *prev = nullptr;
        while (curr != nullptr) {
            if (curr->val == val) {
                if (curr == head) {
                    head = head->next;
                } else {
                    prev->next = curr->next; 
                }
            } else {
                prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};