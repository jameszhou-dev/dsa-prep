#include <leet.h>
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head || !head->next) {
            return nullptr;
        }
        int delay = 0;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        while (fast->next) {
            fast = fast->next;
            delay++;
            if (delay >= n) {
                prev = slow;
                slow = slow->next;
            }
        }
        if (prev) {
            prev->next = slow->next;
        } else {
            head = head->next;
        }
        return head;
        
    }
};