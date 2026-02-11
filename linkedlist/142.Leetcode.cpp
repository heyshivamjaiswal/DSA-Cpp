// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

// Do not modify the linked list.

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode * temp = head;
        ListNode * slow = head;
        ListNode * fast = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};