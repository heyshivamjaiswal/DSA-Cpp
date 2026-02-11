//Reverse the ll

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != nullptr) {
            ListNode* nextNode = curr->next;  // save
            curr->next = prev;                // reverse
            prev = curr;                      // shift prev
            curr = nextNode;                  // shift curr
        }

        return prev;
    }
};