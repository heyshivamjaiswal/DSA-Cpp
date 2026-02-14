// Given a string s, find the length of the longest substring without duplicate characters.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        // stores latest index of each character
        unordered_map<char , int> lastSeen;

        int left = 0;      // start of current valid window
        int maxLen = 0;    // best answer so far

        // expand window using right pointer
        for(int right = 0; right < s.size(); right++){

            char c = s[right];  // current incoming character

            // if character seen before AND inside current window → duplicate
            if(lastSeen.count(c) && lastSeen[c] >= left){

                // jump left just after previous occurrence
                // removes duplicate in O(1) instead of shrinking step-by-step
                left = lastSeen[c] + 1;
            }

            // update latest position of character (VERY IMPORTANT)
            // we always care about the most recent occurrence
            lastSeen[c] = right;

            // window [left ... right] always valid (unique)
            // update maximum length
            maxLen = max(maxLen , right - left + 1);
        }

        return maxLen;
    }
};
