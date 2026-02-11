// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*dummyNode = new ListNode(-1);
        ListNode*current = dummyNode;
        int carry = 0;

        while(l1 != nullptr || l2 != nullptr || carry != 0){
            int sum = carry;
            if(l1 != nullptr){
                sum = sum + l1->val;
                l1 = l1->next;
            }
            if(l2 != nullptr){
                sum = sum + l2->val;
                l2 = l2->next;
            }
            carry = sum/10;
            int lastDigit = sum%10;
            current->next = new ListNode(lastDigit);
            current = current->next;
        }
        return dummyNode->next;
    }
};