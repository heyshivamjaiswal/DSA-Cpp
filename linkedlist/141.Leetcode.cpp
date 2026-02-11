
//Detect a loop in a linked list

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode * slow = head;
        ListNode* fast = slow;
        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next->next;
            slow = slow->next;

            if(fast == slow) return true;
        }
        return false;
    }
};