// Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

// Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

class Solution {
public:

     bool isVowel(char c){
     return c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i';
    }


    int maxVowels(string s, int k) {
        int maxVal = 0;
        int count = 0;
        int left = 0;
        for(int right = 0; right < k; right++){
            if(isVowel(s[right])) count++;
        }
        maxVal = count;

        //slide the window 
        for(int right = k; right < s.size(); right++){
            if(isVowel(s[right])) count++;
            if(isVowel(s[right-k])) count--;

            maxVal = max(maxVal , count);
        }
        return maxVal;
    }
};