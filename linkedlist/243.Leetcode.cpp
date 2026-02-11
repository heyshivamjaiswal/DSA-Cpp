//check Palindrome in a ll

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int>st;
        ListNode*temp = head;
        while(temp != nullptr){
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp != nullptr){
            if(temp->val != st.top()) return false;
            temp = temp->next;
            st.pop();
        }
        return true;
    }
};