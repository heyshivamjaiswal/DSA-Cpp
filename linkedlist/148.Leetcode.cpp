//sort the ll in ascending order

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int>arr;
        ListNode*temp = head;
        while(temp != nullptr){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        sort(arr.begin() , arr.end());
        int i = 0;
        temp = head;
        while(temp != nullptr){
            temp->val = arr[i];
            i++;
            temp = temp->next;
        }
        return head;

    }
};