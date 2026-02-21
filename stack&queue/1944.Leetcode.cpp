// There are n people standing in a queue, and they numbered from 0 to n - 1 in left to right order. You are given an array heights of distinct integers where heights[i] represents the height of the ith person.

// A person can see another person to their right in the queue if everybody in between is shorter than both of them. More formally, the ith person can see the jth person if i < j and min(heights[i], heights[j]) > max(heights[i+1], heights[i+2], ..., heights[j-1]).

// Return an array answer of length n where answer[i] is the number of people the ith person can see to their right in the queue.

 



class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        vector<int>ans(n);

        for(int i = n-1; i>=0; i--){
            int visible = 0;

            while(!st.empty() && heights[i] > st.top()){
                st.pop();
                visible++;
            }

            if(!st.empty()) visible++;
            ans[i] = visible;
             st.push(heights[i]);
        }
      return ans; 
    }
};