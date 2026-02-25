// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.


class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>freq(26,0);
        int left = 0 , maxFreq = 0, ans = 0;

        for(int right = 0; right < s.size(); right++){
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq , freq[s[right] - 'A']);

            while((right - left + 1) - maxFreq > k){
            freq[s[left] - 'A']--;
            left++;
        }
        ans = max(ans , right - left +1);
        }
        return ans;
    }
};
