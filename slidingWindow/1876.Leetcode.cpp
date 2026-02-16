// A string is good if there are no repeated characters.

// Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.

// Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

// A substring is a contiguous sequence of characters in a string.


//Method 1
class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;

        for(int i = 0 ; i+2< s.size(); i++){

            if(s[i] != s[i+1] && s[i] != s[i+2] && s[i+1] != s[i+2]) count++;
        }
        return count;
    }
};

//Method 2 (Generalize sliding window)
class Solution{
    public:
    int countGoodSubstrings(string s){
        unordered_map<char , int>freq;
        int ans = 0;

        for(int i = 0 ; i<s.size(); i++){

            //mark the freq
            freq[s[i]]++;

            if(i >= 3){
                freq[s[i-3]]--;
                if(freq[s[i-3]] == 0) 
                freq.erase(s[i-3]);
            }
            if(freq.size() == 3){
                ans++;
            }
        }
        return ans;
    }
};