// Given the head of a linked list, remove the nth node from the end of the list and return its head.


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode * fast = head;
        ListNode * slow = head;
        for(int i=0; i<n ; i++) fast = fast->next;
        if(fast == nullptr) return head->next;
        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode * delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
    }
};