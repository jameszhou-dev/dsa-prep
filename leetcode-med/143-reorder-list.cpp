#include <leet.h>
class Solution {

public:
    void reorderList(ListNode* head) {
        ListNode* curr = head;
        int len = 0;
        while (curr) {
            curr = curr->next;
            len++;
        }
        curr = head;
        int i = 0;
        while (i < (len + 1) / 2) {
            curr = curr->next;
            i++;
        }
        ListNode* prev = nullptr;
        ListNode* temp = nullptr;
        while (curr) {
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        curr = head;
        i = 0;
        while (i < (len)/ 2) {
            temp = curr->next;
            curr->next = prev;
            prev = prev->next;
            curr = curr->next;
            curr->next = temp;
            curr = curr->next;
            i++;
        }
        curr->next = nullptr;

        
    }
};