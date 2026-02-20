
// Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

// Return true if there is a 132 pattern in nums, otherwise, return false.





class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        stack<int>st; //store 3 2nd element (middle element)
        int third = INT_MIN; //store last element 

        for(int i=n-1; i>=0; i--){
            //if current element becomes 1(smallest)
            if(nums[i] < third){
                return true;
            }

            while(!st.empty() && nums[i] > st.top()){
                third = st.top();
                st.pop();
            }
            //if current become 3 (middle element)
            st.push(nums[i]);
        }
        return false;
    }
};